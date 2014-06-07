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
bool forward = true;

task calculateDistance()
{
	while(true)
	{
	D = SensorValue(sensorSONAR);
	float E = nMotorEncoder[motorA];

	if(D > 26) {D = 254;}

	if(E > 90 && E < 180){
		Theta = ((E * PI) / 180) - (PI/2);

		if(D * sin(Theta) <= c) {turnaround = 1;}
		if(D * cos(Theta) <= b) {turnaround = 1;}
	}

	if(E < 90 && E > 0){
		Theta = (E * PI) / 180;

		if(D * sin(Theta) <= c) {turnaround = 2;}
		if(D * cos(Theta) <= a) {turnaround = 2;}
	}

	if(E == 90 && D < c){turn(180);}
	if(turnaround == 1){turn(90 - E);}
	if(turnaround == 2){turn(E);}
	}
}


//initialize sonar motor rotation
void motorInitialize()
{
	bFloatDuringInactiveMotorPWM = false;

	nMotorEncoder[motorA] = 90;
	nMotorEncoderTarget[motorA] = 180;

	motor[motorA] = motorMaxPower;
	while(nMotorRunState[motorA] != runStateIdle){}
	motor[motorA] = 0;
}

void turn(float t)
{
	forward = false;
		t = (t / 360) * 2263;

		nMotorEncoder[motorC] = 0;
		nMotorEncoder[motorB] = 0;


			nMotorEncoderTarget[motorC] = t;
 			nMotorEncoderTarget[motorB] = -1*t;

			motor[motorC] = motorMaxPower;
			motor[motorB] = -1 * motorMaxPower;


		while((nMotorRunState[motorC] != runStateIdle) && (nMotorRunState[motorB] != runStateIdle)){wait1Msec(1);}

		motor[motorC] = 0;
		motor[motorB] = 0;

		nMotorEncoder[motorC] = 0;
		nMotorEncoder[motorB] = 0;

		forward= true;
}
