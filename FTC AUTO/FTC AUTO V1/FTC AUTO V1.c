#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR,               sensorHiTechnicIRSeeker600)
#pragma config(Motor,  mtr_S1_C2_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     Lift,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_1,     Push,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_2,     Paddle,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     Flag,          tmotorTetrix, PIDControl)

//chi lin

#include "header.h"
#include "JoystickDriver.c"
task sto()
{
	while(true)
	{
		int cr = nMotorEncoder[Drive_R];
		int cl = nMotorEncoder[Drive_L];
		wait1Msec(1000);

		if ( (abs(motor[Drive_R])>0 && nMotorEncoder[Drive_R] < cr + 5) ||(abs(motor[Drive_L])>0 && nMotorEncoder[Drive_L] < cl + 5))
		{
			while(true)
			{
				motor[Drive_L] = 0;
				motor[Drive_R] = 0;
		}
		}
		}

}


task main()
{

  //StartTask(sto);
	int delay = 0;
	while (nNxtButtonPressed != 3)
	{
		if (nNxtButtonPressed == 1)
		{
			delay = delay + 1;
			while(nNxtButtonPressed == 1) {wait1Msec(1);}
		}
		if (nNxtButtonPressed == 2)
		{
			delay = delay - 1;
			while(nNxtButtonPressed == 2) {wait1Msec(1);}
		}
		nxtDisplayBigTextLine(3,"%i",delay);
	}
		waitForStart();
	wait1Msec(1000 * delay);


//	int td = nMotorEncoder[Drive_R];

//	turn(90);
	//drop block
//	turn(-90)
	drive(track_length, true);

	turn(55);
	drive(40,true);
	turn(120);
	drive(32,true);
}
