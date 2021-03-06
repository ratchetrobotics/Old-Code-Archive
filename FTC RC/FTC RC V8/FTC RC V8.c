#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR,               sensorHiTechnicIRSeeker600)
#pragma config(Motor,  mtr_S1_C2_1,     Drive_R,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     Drive_L,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     Lift,          tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_1,     Paddle,          tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Push,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,			LiftEncoder,	 tmotorTetrix, PIDControl, encoder)

/*Team 6806 Teleoperated program Version 8
By Vincent Bensch
Last update made 1-feb-2014*/

#include "Subrutines.h";// Including custom header
task main()
{
	waitForStart();// Waiting for start command from FCS
	while(true)// Command recieved start loop untill FCS closes program
	{
  	getJoystickSettings(joystick); //Refresh joystick values

  	if (joy1Btn(6) || joy1Btn(8)) {drive_power = drive_max_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power
		else {drive_power = drive_min_power;} //If joystick 1 button TR or BR are pushed set drive power to boost mode, otherwise set it to normal power

		initial_power(); //Set the global power values

		if (joy1Btn(7) || joy1Btn(5)) {inverse_slave();} //If joystick 1 button RL or BL are pushed run the subrutine to rotate in place

		if (joy1Btn(3) || joy2Btn(3)) {reset();} //If joystick 1 or joystick 2 push the red b button set all motor speeds to 0 unitll release

		if (joy1Btn(1) || joy1Btn(2)) {slave();} //If joystick 1 button A or X are pressed, slave the two drive motors together

		if (joy2Btn(2)) {
		motor[Paddle] = -2* tower_paddle_power;
		wait1Msec(1450);
		motor[Paddle] = 0;
		} //If joystick 2 button TL is pushed, move the paddles negative at speed tower_paddle_power

		if (joy2Btn(5)) {tower_paddle = -1* tower_paddle_power;}

		if (joy2Btn(7)) {tower_paddle = tower_paddle_power;} //If joystick 2 button TL is pushed, move the paddles at speed tower_paddle_power

		if (joy2Btn(2)) {tower_flag = tower_flag_power;} //If joystick 2 button A is pressed, run flag motor forward

		if (joy2Btn(4)) {tower_flag = -1* tower_flag_power;} //If joystick 2 button Y is pressed, run flag motor backwards

		enact_power();//Enact the power variables layed out by the previous subrutines
  }
}
