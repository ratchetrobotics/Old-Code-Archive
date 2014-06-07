#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Extender,          tmotorTetrix, PIDControl)

#include "header2.h"
#include "joystickdriver.c"

float extender_power = 100;
int extenderpos = 0;

int extend_delay = 1000;

task main()
{
	//waitForStart();
	motor[Extender] = extender_power;
	wait1Msec(extend_delay);
	motor[Extender] = 0;
	extenderpos = 1;
	drive(15, true);
	drive(-4, true);
	motor[Extender] = -1 * extender_power;
	wait1Msec(extend_delay + 15);
	motor[Extender] = 0;

}
