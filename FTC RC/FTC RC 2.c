#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     R,             tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     L,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, PIDControl)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int deadband = 3;
int power = 100;
int max_speed = 100;
int low_speed = 40;
float left = 0;
float right = 0;



float clearnoise(int joypos)
{
	return power * (joypos / 127);
}


task main()
{
	waitForStart();
	//while(true)
	//{
  while(!joy1Btn(3) && !joy2Btn(3)) // remove before testing
  {
  	getJoystickSettings(joystick);

  	if (joy1Btn(6) || joy1Btn(8))
		{
			power = low_speed;
		}
		else
		{
			power = max_speed;
		}

  	left = clearnoise(joystick.joy1_y1);
  	right = clearnoise(joystick.joy1_y2);

  	if (joy1Btn(7) || joy1Btn(5))
		{
			if (abs(left) >= abs(right))
			{
				right = -1 * left;
			}

			else
			{
				left = -1 * right;
			}
		}

		nxtDisplayCenteredTextLine (1,"%f", right);
		nxtDisplayCenteredTextLine (2,"%f", left);

		motor[R] = right;
		motor[L] = left;
	}

  	motor[R] = 0;
  	motor[L] = 0;
  //}
}
