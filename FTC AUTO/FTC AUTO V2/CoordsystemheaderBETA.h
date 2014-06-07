
//all are in CM!!! CM! CM!!!!!! CM!!!! DON'T DO THE NASA!!!!

const float PI = 3.14159265358979323846264338327950288419716939937510;
const int robotwidth = 28;
const float wheeldiameter = 4.25;
const float revolutionsInFullRobotTurn = robotwidth / wheeldiameter;
const float wheelcircumfrence = wheeldiameter * PI;
const int encoderCountsPerTurn = 360 * revolutionsInFullRobotTurn; //1440 for robot, 360 for NXT
const float Heading = 90;
const float X = robotwidth / 2;
const float distancefromsensortomiddleofbot = 6.5;
const float Y = SensorValue[S1] + distancefromsensortomiddleofbot;
const float F = X * 2;
const float G = Y;
const float N = Heading;
const int Maxpower = 70;

void turnfwd(float G, float F)
{
	if( G==X || F==Y)
	{
	float	N = Heading;
	}
	else
	{
	float	N = radiansToDegrees(acos((F - X) * sqrt((F - X) + (G - Y))));
	}
	float Heading = Heading - N;
	if(Heading > 180 || Heading < -179)
	{
	float	Heading = -Heading;
	}
	Heading = Heading / 720;



	nSyncedMotors = synchBC;
	nSyncedTurnRatio = -100;
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = -Heading * encoderCountsPerTurn * revolutionsInFullRobotTurn;
	motor[motorB] = Maxpower;

	while(nMotorRunState[motorB] != runStateIdle)
	{

	}
	motor[motorB] = 0;
	nSyncedMotors = synchNone;
	float X = F;
	float Y = G;
	}
