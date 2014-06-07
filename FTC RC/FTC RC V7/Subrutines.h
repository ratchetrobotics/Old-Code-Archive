/*Team 6806 Teleoperated program Version 7
By Vincent Bensch
Last update made 29-jan-2014*/

#include "JoystickDriver.c"  //Include file to accept controller commands

long g;
int i;

float drive_left = 0; //Setting initial power values
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

void enact_power() // Make the motorspeeds what the motor power variables say they should be
{
	motor[Drive_L] = drive_left;
	motor[Drive_R] = drive_right;
	motor[Lift] = tower_rotate;
	motor[Push] = tower_raise;
	motor[Paddle] = tower_paddle;
	motor[Flag] = tower_flag;
}

void reset() //set all Motor speeds to 0
{
	motor[Drive_L] = 0;
	motor[Drive_R] = 0;
	motor[Lift] = 0;
	motor[Push] = 0;
	motor[Paddle] = 0;
	motor[Flag] =	0;

	tower_rotate = 0;
	tower_raise = 0;
	tower_paddle = 0;
	tower_flag = 0;
	drive_left = 0;
	drive_right = 0;

	while(joy1Btn(3) || joy2Btn(3)) {wait1Msec(5);} // wait for reliece of the stop buttons
}

float max(float a, float b) //If b>=a return b else return a
{
	if (abs(a)>=abs(b)) {return a;}
	else {return b;}
}

float min(float a, float b) //If b>=a returna else return b
{
	if (abs(a)>=abs(b)) {return b;}
	else {return a;}
}

void initial_power() //Setup the motor power values to be proportional to the joystick values
{
	float left = joystick.joy1_y1;//Get Joystick values
	float right = joystick.joy1_y2;
	float rotate = joystick.joy2_y2;
	float raise = joystick.joy2_y1;

	if (abs(left) <= deadband) {left = 0;} //Ignore values inside the deadband
	if (abs(right) <= deadband) {right = 0;}
	if (abs(rotate) <= deadband) {rotate = 0;}
	if (abs(raise) <= deadband) {raise = 0;}

	drive_left = (left / 127) * drive_power; //Drive Power times the percent of the way each joystick is being pushed
	drive_right = (right / 127) * drive_power;
	tower_rotate = (rotate / 127) * tower_rotate_power;
	tower_raise = (raise / 127) * tower_raise_power;
	}

	void inverse_slave()
	{
		if (drive_left >= drive_right) {drive_right = drive_left * -1;} //If left power value is greater or equal to right power value right power value is the inverse of the left power value
		else {drive_left = drive_right * -1;} //If right power value is greater than left power value left power value is the inverse of the right power value
	}

	void slave()
	{
		drive_left = max(drive_left, drive_right); //Left power value is equal to the stronger of the two power values
		drive_right = drive_left; //Sets right power value to left power value
	}

	void paddeler(int mode)
	{
		if (mode == 1 && tower_paddle == 0) {tower_paddle = tower_paddle_power;} // If TL is pressed and the paddles are not moving, move them at tower_paddle_power
	  	if (mode == -1 && tower_paddle == 0) {tower_paddle = -1 * tower_paddle_power;} // If Bl is pressed and the paddles are not moving, move them at the inverse of tower_paddle_power
		else {tower_paddle_power = 0;} // if TL or BL are pressed and tower_paddle is not 0, make it 0
		while(joy2Btn(5) || joy2Btn(7)){wait1Msec(5);}//wait for reliece of both TL and BL
	  }

	void send_debug()//Sends current motor settings to Debuging NXT
    {
        sendMessageWithParm(0,drive_left);
        sendMessageWithParm(1,drive_right);
        sendMessageWithParm(4,tower_rotate);
        sendMessageWithParm(5,tower_raise);
        sendMessageWithParm(6,tower_paddle);
        sendMessageWithParm(7,tower_flag);
    }
