/*Team 6806 Teleoperated program Version 9
By Vincent Bensch
Last update made 18-feb-2014*/

#include "Configure.h"
#include "JoystickDriver.c"  //Include file to accept controller commands

void drive_refresh()
{
	int left = leftjoy;//Get Joystick values
	int right = rightjoy;

	if (abs(left) <= deadband) {left = 0;} //Ignore values inside the deadband
	if (abs(right) <= deadband) {right = 0;}

	drive.left = (left / 127) * drive.current_power; //Drive Power times the percent of the way each joystick is being pushed
	drive.right = (right / 127) * drive.current_power;
}

void mechanism_refresh()
{
	int rotate = liftjoy;
	int raise = troughjoy;

	if (abs(rotate) <= deadband) {rotate = 0;}
	if (abs(raise) <= deadband) {raise = 0;}

	mech.lift = (rotate / 127) * mech.lift_power;
	mech.trough = (raise / 127) * mech.trough_power;
}

void inverse_slave()
{
	if (abs(drive.left) >= abs(drive.right)) {drive.right = drive.left * -1;} //If left power value is greater or equal to right power value right power value is the inverse of the left power value
	else {drive.left = drive.right * -1;} //If right power value is greater than left power value left power value is the inverse of the right power value
}

void slave()
{
	drive.left = max(drive.left, drive.right); //Left power value is equal to the stronger of the two power values
	drive.right = drive.left; //Sets right power value to left power value
}
