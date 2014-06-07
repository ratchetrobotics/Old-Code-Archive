#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR,               sensorHiTechnicIRSeeker600)
#pragma config(Motor,  mtr_S1_C2_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     Lift,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_1,     Trough,          tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Paddle,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     Flag,          tmotorTetrix, PIDControl)

/*Team 6806 Teleoperated program Version 9
By Vincent Bensch
Last update made 18-feb-2014*/

#include "Subrutines.h";// Including custom header

task drive_task()
{
	while(true)
	{
		if (boostbtn) {drive.current_power = drive.full_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power
		else {drive.current_power = drive.full_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power

		drive_refresh();

		if (turnbtn) {inverse_slave();} //If joystick 1 button RL or BL are pushed run the subrutine to rotate in place

		if (togetherbtn) {slave();} //If joystick 1 button A or X are pressed, slave the two drive motors together

		if (resetbtn1)
			{
				motor[Drive_R] = 0;
				motor[Drive_L] = 0;

				while(!overide1) {wait1Msec(1);} // wait for someone to press the reset button
			}

		motor[Drive_R] = drive.right;
		motor[Drive_L] = drive.left;
	}
}

task mechanism_task()
{
	while(true)
	{
		mechanism_refresh();

		if (paddle_for) {mech.paddle = mech.paddle_power;}

		if (paddle_back) {mech.paddle = -1 * mech.paddle_power;} //If joystick 2 button TL is pushed, move the paddles at speed tower_paddle_power

		if (flag_for) {mech.flag = mech.flag_power;} //If joystick 2 button A is pressed, run flag motor forward

		if (flag_back) {mech.flag = -1* mech.flag_power;} //If joystick 2 button Y is pressed, run flag motor backwards

		if (resetbtn2)
			{
				motor[Lift] = 0;
				motor[Trough] = 0;
				motor[Paddle] = 0;
				motor[Flag] = 0;

				while(!joy2Btn(4)) {if (killbtn){kill = true;} else{wait1Msec(1);}} // wait for someone to press the recet button
			}

			if((limit.lift_upper > liftpos > limit.lift_lower) || (liftpos > limit.lift_upper && mech.lift < 0) || (liftpos < limit.lift_lower && mech.lift > 0)) {motor[Lift] = mech.lift;}

			motor[Trough] = mech.trough;
			motor[Paddle] = mech.paddle;
			motor[Flag] = mech.flag;
		}
}

task main()
{
	PlayTone(784, 15);
	configure();
	waitForStart();// Waiting for start command from FCS

	StartTask(drive_task);
	StartTask(mechanism_task);
	PlayTone(784, 15);

	while(true)// Command recieved start loop untill FCS closes program
	{
		getJoystickSettings(joystick);

		if (kill || bDisconnected)
		{
			PlayTone(500, 15);
			StopAllTasks();
			return;
		}
	}
}
