int counts = 1;
int motorMaxPower = 55;
int D = 50;
int Theta = 90;
int distance_to_L = 12;
int distance_to_R = 12;
int distance_in_front = 12;
int c = distance_in_front + 2;
int b = distance_to_L + 2;
int a = distance_to_R + 2; //all MUST BE in CM
int turnaround = 0;
int drivemotormaxpower = 80;








//Calculating distance


void calculateDistance()
{
	D = SensorValue[sensorSONAR];
	if(D > 16)
{
	D = 255;
}


















}
//end calculate distance







//initialize sonar motor rotation

void motorInitialize()
{
	bFloatDuringInactiveMotorPWM = false;
	nMotorEncoder[motorA] = 90;
	bMotorReflected[motorA] = false;
	nMotorEncoderTarget[motorA] = 90;
	motor[motorA] = motorMaxPower;


	while(nMotorRunState[motorA] != runStateIdle)
		{

		}


	motor[motorA] = 0;
	bMotorReflected[motorA] = true;
		nMotorEncoder[motorA] = 0;
	nMotorEncoderTarget[motorA] = 180;
	motor[motorA] = motorMaxPower;




	while(nMotorRunState[motorA] != runStateIdle)
	{

	}


	motor[motorA] = 0;
}
//end initialize







//run sonar motor

void motorRun()
{
	while(counts != 100)
{
	counts ++;
	bMotorReflected[motorA] = false;
	nMotorEncoderTarget[motorA] = 180;
	motor[motorA] = motorMaxPower;

		while(nMotorRunState[motorA] != runStateIdle)
		{
		nSyncedMotors = synchBC;
		nSyncedTurnRatio = +100;
		motor[motorB] = 60;
		calculateDistance();
		}
	motor[motorA] = 0;

	bMotorReflected[motorA] = true;
		nMotorEncoder[motorA] = 0;
	nMotorEncoderTarget[motorA] = 180;
	motor[motorA] = motorMaxPower;
	while(nMotorRunState[motorA] != runStateIdle)
	{
		nSyncedMotors = synchBC;
		nSyncedTurnRatio = +100;
		motor[motorB] = 60;
	calculateDistance();
	}
	motor[motorA] = 0;
}
}
//end run sonar motor
