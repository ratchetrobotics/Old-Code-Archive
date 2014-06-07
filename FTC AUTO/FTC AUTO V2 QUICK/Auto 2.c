#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)


#include "header2.h"
#include "joystickdriver.c"

task main()
{
	waitForStart();
	drive(38,true);
	turn(-55);
	drive(16,true);
	turn(95);
	drive(13,true);
}
