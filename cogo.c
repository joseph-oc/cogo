#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ncurses.h>

#define INVERSE             0
#define TRAVERSE            1
#define BB_INTERSECTION     2
#define BD_INTERSECTION     3
#define DB_INTERSECTION		 4
#define DD_INTERSECTION     5

// define struct determiner -> used to determine cogo function from data entry

struct determiner
	{
		unsigned int fromPoint 	:1;
		unsigned int angle_1	:1;
		unsigned int distance_1	:1;
		unsigned int locate_1	:1;
		unsigned int angle_2	:1;
		unsigned int distance_2	:1;
		unsigned int locate_2	:1;
	};



//Prototype Functions

double angle(char);
int determination(struct determiner fnflag2);

/* Extern variable for data entry strings, point numbers and Routine Type Flag*/

int intFunctionType;

struct pt {
  char id[128];
  double x;
  double y;
  double z;
  char desc[128];
};

//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

int main()
{
// Initialize fnflag1 structure
struct determiner fnflag1 = {
	fnflag1.fromPoint = 0,
	fnflag1.angle_1 = 0,
	fnflag1.distance_1 = 0,
	fnflag1.locate_1 =0,
	fnflag1.angle_2 =0,	fnflag1.distance_2=0,
	fnflag1.locate_2=0,
									};
								
// Initialize string variables
char strFromPoint[6], strLocate_1[6], strLocate_2[6];
char strAngle_1[40], strDistance_1[40], strAngle_2[40], strDistance_2[40];

// Initialize double float variables
double dblAngle_1, dblAngle_2, dblDistance_1, dblDistance_2;

// Initialize intFn
int intfn = 0;

/* Initialize OPENING SCREEN */
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	bkgd(COLOR_PAIR(1));
	attron(A_BOLD);
	center(1, "Surveyor's Coordinate Geometry - COGO");
	center(5, "Copyright 2013 - Joseph C. O'Connor, PMS - Open Source Software");
	flash();

addstr("\n\n/* ++++++++++++++++++++++++FROM POINT DATA ENTRY+++++++++++++++++++++++*/");

addstr("\nEnter From Point: ");
getstr(strFromPoint);

if (strlen(strFromPoint) == 0)
	fnflag1.fromPoint = 0;
else fnflag1.fromPoint = 1;
	
addstr("\nFrom Pt: ");
addstr(strFromPoint);
refresh();

addstr("\n/* ++++++++++++++++++++++++BEARING 1 DATA ENTRY++++++++++++++++++++++++++++*/");

addstr("\nEnter Angle/Bearing: ");
getstr(strAngle_1);

if (strlen(strAngle_1) == 0)
	fnflag1.angle_1 = 0;
else fnflag1.angle_1 =1;

addstr("Polar Angle: ");
addstr(strAngle_1);
refresh();

addstr("\n/*++++++++++++++++++++++DISTANCE 1 DATA ENTRY++++++++++++++++++++++++++++*/");

addstr("\nEnter Distance: ");
getstr(strDistance_1);

if (strlen(strDistance_1) == 0)
	fnflag1.distance_1 = 0;
else fnflag1.distance_1 = 1;

addstr("\nPolar Distance: ");
addstr(strDistance_1);
refresh();

addstr("\n/*++++++++++++++++++++++++LOCATE_1 DATA ENTRY++++++++++++++++++++++++++++ */");

addstr("\nEnter To Point: ");
addstr("\nEnter To Point: ");
getstr(strLocate_1);

if (strlen(strLocate_1) == 0)
	fnflag1.locate_1 = 0;
else fnflag1.locate_1 = 1;
refresh();
addstr("\n **************************** Locate_1 ****************************"  );

intfn = determination(fnflag1);

if(intfn == 0)  
	addstr("\n\nINVERSE");
else if (intfn== 1)
	addstr("\n\nTRAVERSE");

if (intfn == 0)
	addstr("  goto Inverse Calculation");
else if (intfn == 1)
	addstr("  goto Traverse Calculation");
refresh(); 

addstr("\nFrom Point: ");
addstr(strFromPoint);
addstr("\nBearing: ");
addstr(strAngle_1);
addstr("\nDistance: ");
addstr(strDistance_1);
addstr("\nLocate_1 Point: ");
addstr(strLocate_1);
refresh();

addstr("\n/** ++++++++++++++++++++++++Enter Bearing 2++++++++++++++++++++++++++ */");

addstr("\nEnter Angle/Bearing 2: ");
getstr(strAngle_2);
addstr("\nPolar Angle: ");
addstr(strAngle_2);
refresh();

addstr("\n/* ++++++++++++++++++++++++Enter Distance 2++++++++++++++++++++++++++++*/");

addstr("\nEnter Distance 2: ");
getstr(strDistance_2);
addstr("\nPolar Angle: ");
addstr(strDistance_2);
refresh();

addstr("\n/* ++++++++++++++++++++++++Locate - To Point ++++++++++++++++++++++++++++*/");

addstr("\nEnter To Point: ");
getstr(strLocate_2);
addstr("\n                      /* Solution */");
addstr("\nFrom Point: ");
addstr(strFromPoint);
addstr("\nBearing: ");
addstr(strAngle_1);
addstr("\nDistance: ");
addstr(strDistance_1);
addstr("\nTo Point: ");
addstr(strLocate_2);

addstr("\n/* +++++++++++++++Call Functions for Calculations +++++++++++++++++++++++++++*/");

	getch();
	endwin();

	return 0;
}

int determination(struct determiner fnflag2)

{

	// Inverse
	if 
	(fnflag2.fromPoint == 1 && fnflag2.angle_1 == 0 && fnflag2.distance_1 == 0 && fnflag2.locate_1 == 1)
		return 0;
	// Traverse
	else if 
	(fnflag2.fromPoint == 1 && fnflag2.angle_1 == 1 && fnflag2.distance_1 == 1 && fnflag2.locate_1 == 1)
		return 1;

}



void center(int row, char *title)
{
	int len,indent,y,width;

	getmaxyx(stdscr,y,width);	/* get screen width */

	len = strlen(title);		/* get title's length */
	indent = width - len;		/* subtract it from screen width */
	indent /= 2;			/* divide result into two */

	mvaddstr(row,indent,title);
	refresh();
}
