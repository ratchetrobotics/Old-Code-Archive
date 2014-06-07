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

task calculateDistance()
{
	while(true)
	{
	D = SensorValue(sensorSONAR);
	float E = nMotorEncoder[Turret];

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
