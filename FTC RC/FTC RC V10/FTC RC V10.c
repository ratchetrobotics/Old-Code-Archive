#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Rtread,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Ltread,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Extender,          tmotorTetrix, PIDControl)

/*Team 6806 Teleoperated program Version 10
By Vincent Bensch
Last update made 29-feb-2014*/

#include "Subrutines.h";// Including custom header

task main()
{
	waitForStart();

	while(true)// Command recieved start loop untill FCS closes program
	{
		getJoystickSettings(joystick);
  	if (joy1Btn(6) || joy1Btn(8)) {drive_power = drive_max_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power
		else {drive_power = drive_min_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power

		joy_power(); //Set the global power valuesy

		if (joy1Btn(7) || joy1Btn(5)) {inverse_slave();} //If joystick 1 button RL or BL are pushed run the subrutine to rotate in place

		if (joy1Btn(1) || joy1Btn(2)) {slave();} //If joystick 1 button A or X are pressed, slave the two drive motors together

		motor[Ltread] = drive_left;
		motor[Rtread] = drive_right;

		if((joystick.joy2_y1 > deadband || joystick.joy2_y2 > deadband) && extenderpos == 0)
		{
			motor[Extender] = extender_power;
			wait1Msec(extend_delay);
			motor[Extender] = 0;
			extenderpos = 1;
		}

		if((joystick.joy2_y1 < -1 * deadband || joystick.joy2_y2 < -1 * deadband) && extenderpos == 1)
		{
			motor[Extender] = -1 * extender_power;
			wait1Msec(retract_delay);
			motor[Extender] = 0;
			extenderpos = 0;
		}

	}
}
