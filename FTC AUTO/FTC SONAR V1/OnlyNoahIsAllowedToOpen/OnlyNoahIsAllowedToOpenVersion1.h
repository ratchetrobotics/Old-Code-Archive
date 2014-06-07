const float RobotWidth = 27.5; //cm
const float TireDiameter = 1.75; //cm
const float ClicksPerTireRotation = 360; //nxt motors
const float b = 9; //cm distance from L side of robot to sensor
const float a = 18.5; //cm distance from R side of robot to sensor
const float c = 1; //cm distance from front of robot to sensor
const int MaxMotorPower = 100;
int i = 10000;

/*																											Note to self:
MotorA is sensor motor
MotorB is L motor
MotorC is R motor
*/

/////////////////////////////////////////////////////////Don't change anything below/////////////////////////////////////////////////////////////////////////////////////////////
/*////////////*/ const float ClicksPerTurn = ClicksPerTireRotation * RobotWidth / TireDiameter;																																					//
/*////////////*/ const float DegreesToLeft = 180;																																																													//
/*////////////*/ const float DegreesToRight = 0;																																																																												//
/*////////////*/																																																																												//
/*////////////*/																																																																												//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TurnRight(float degrees) {




	}

void TurnLeft(float degrees) {






}

void InitializeTurret() {
	nMotorEncoder[motorA] = 90;
	nMotorEncoderTarget[motorA] = 0;
	motor[motorA] = -10;
	while(nMotorRunState[motorA] != runStateIdle) {}
	motor[motorA] = 0;
	}


void FunctionDistance(float degrees, float dstc)
{
	degrees = degrees * PI / 180;
 	if(degrees == PI / 2 && dstc < c) {PlaySound(soundLowBuzz); wait1Msec(3000);}
	if(degrees > PI / 2 && degrees < PI && dstc * asin(degrees) < c) {PlaySound(soundUpwardTones); wait1Msec(3000);}
	if(degrees > 0 && degrees < PI / 2 && dstc * asin(degrees) < c) {PlaySound(soundDownwardTones); wait1Msec(3000);}

}

void GoPackers(float destination)
{
	nMotorEncoderTarget[motorA] = destination;
	while(nMotorRunState[motorA] != runStateIdle) {}
	FunctionDistance(destination, SensorValue[sonarSensor]);
}

void NormalOperation() {
	while(true) {
		//motor[motorB] = MaxMotorPower;
		//motor[motorC] = MaxMotorPower;
			//moving from Left to Right
		motor[motorA]= -10;
		for(i=170; i>0; i=i-10){
		GoPackers(i);
		}
		//motor[motorB] = MaxMotorPower;
		//motor[motorC] = MaxMotorPower;
		motor[motorA]= 10;
		for(i=10; i<180; i=i+10){
		GoPackers(i);
		}
	}
}
