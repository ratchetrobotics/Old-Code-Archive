#pragma config(Motor,  motorA,          R,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          L,             tmotorNXT, PIDControl, encoder)


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int low_speed = 40;
int max_speed = 100;

void initializeRobot()
{
  motor[L] = 0;
  motor[R] = 0;

  return;
}

int leftstick()
{
	int out = joystick.joy1_y1;
	if (abs(out) < 5)
	{
		return 0;
	}
	return out;
}

int rightstick()
{
	int out = joystick.joy1_y2;
	if (abs(out) < 5)
	{
		return 0;
	}
	return out;
}

task main()
{
	int i = 0;
	float left = 0;
	float right = 0;

  initializeRobot();

  waitForStart();

 	getJoystickSettings(joystick);

	left = leftstick();
	right = rightstick();

	if (joy1Btn(5) || joy1Btn(7))
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

	left = left / 127 * max_speed;
	right = right / 127 * max_speed;


	//if(joy1Btn(8) || joy1Btn(6))
	//{
	//left = left / 127 * low_speed;
	//right = right / 127 * low_speed;
	//nxtDisplayCenteredTextLine (5,"LOW");
	//}

	motor[L] = left;
	motor[R] = right;

		nxtDisplayCenteredTextLine (5, "%i", i);
		nxtDisplayCenteredTextLine (0, "%f", right);
		nxtDisplayCenteredTextLine (1, "%f", left);
  }
