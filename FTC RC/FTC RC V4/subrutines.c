#include "declerations.c"
#include "main.c"

void reset()
{
	motor[DL] = 0;
	motor[DR] = 0;
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

void initial_power(struct s)
{
	int left = joystick.joy1_y1;
	int right = joystick.joy1_y2;

	if (abs(left) <= deadband) {left = 0;}
	if (abs(right) <= deadband) {right = 0;}

	drive.left = (left / 127) * power;
	drive.left = (right / 127) * power;
	return;
	}

	void inverse_slave()
	{
		if (drive.left >= drive.right)
		{
			drive.right = drive.left * -1;
			return;
		}
		else
		{
			drive.left = drive.right * -1;
			return;
		}
	}

	void slave()
	{
		drive.left = max(drive.left, drive.right);
		drive.right = drive.left;
		return;
	}
