#include "declerations.c"
#include "subrutines.c"


task main()
{
	Driver drive;
	drive.left = 0;
	drive.right = 0;
	drive.power = 0;
	drive.max_speed = 100;
	drive.low_speed = 50;

	waitForStart();
	while(true)
	{
  	getJoystickSettings(joystick);

  	if (joy1Btn(6) || joy1Btn(8))
		{
			power = drive.max_speed;
		}
		else
		{
			power = drive.low_speed;
		}

		initial_power();

  	if (joy1Btn(7) || joy1Btn(5))
		{
			inverse_slave();
		}

		if (joy1Btn(3) || joy2Btn(3))
		{
			reset();
		}

		if (joy1Btn(1))
		{
			slave();
		}

		motor[DR] = drive.right;
		motor[DL] = drive.left;
  }
}
