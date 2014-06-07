#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

float drive_left = 0;
float drive_right = 0;

float drive_max_power = 100;
float drive_min_power = 50;
float drive_power = 0;

float tower_rotate = 0;
float tower_raise = 0;
float tower_paddle = 0;
float tower_flag = 0;

float tower_rotate_power = 50;
float tower_raise_power = 100;
float tower_paddle_power = 50;
float tower_flag_power = 100;

int deadband = 5;

void reset()
{
	motor[Drive_L] = 0;
	motor[Drive_R] = 0;
	motor[Lift] = 0;
	motor[Push] = 0;
	motor[Paddle] = 0;
	motor[Flag] = 0;
}

float max(float a, float b)
{
	if (abs(a)>=abs(b))
	{
		return a;
	}
	else
	{
		return b;
	}
}

void initial_power()
{
	float left = joystick.joy1_y1;
	float right = joystick.joy1_y2;
	float rotate = joystick.joy2_y2;
	float raise = joystick.joy2_y1;

	if (abs(left) <= deadband) {left = 0;}
	if (abs(right) <= deadband) {right = 0;}
	if (abs(rotate) <= deadband) {rotate = 0;}
	if (abs(raise) <= deadband) {raise = 0;}

	drive_left = (left / 127) * drive_power;
	drive_right = (right / 127) * drive_power;
	tower_rotate = (rotate / 127) * tower_rotate_power;
	tower_raise = (raise / 127) * tower_raise_power;
	return;
	}

	void inverse_slave()
	{
		if (drive_left >= drive_right)
		{
			drive_right = drive_left * -1;
			return;
		}
		else
		{
			drive_left = drive_right * -1;
			return;
		}
	}

	void slave()
	{
		drive_left = max(drive_left, drive_right);
		drive_right = drive_left;
		return;
	}
