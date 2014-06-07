#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR,               sensorHiTechnicIRSeeker600)
#pragma config(Motor,  mtr_S1_C2_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     Lift,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_1,     Push,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_2,     Paddle,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     Flag,          tmotorTetrix, PIDControl)

#include "header.h"
#include "joystickdriver.c"

task main()
{
	waitForStart();
	drive(38,true);
	turn(-55);
	drive(16,true);
	turn(95);
	drive(9,true);
}
