#pragma config(Sensor, S1,     sonic,          sensorSONAR)
#pragma config(Motor,  motorA,          Turret,        tmotorNXT, PIDControl, encoder)

void clearline(int xc, int s, int e)
{
	for(int i=s;i<=e;i++){
		nxtClearPixel(xc,i);
	}
}

float  x;
float  y;

float tx;
float ty;

task turretmotor()
{
	while(true)
	{
		motor[Turret] = 30;
		while(nMotorEncoder[Turret] < 180){}
		motor[Turret] = -30;
		while(nMotorEncoder[Turret] > 0){}
	}
}
//nxtEraseLine(20, 50, 60, 25);  // erase a line between the points (20,50) and (60,25)

task scanner()
{
	while(true)
	{
		int ix = SensorValue(sonic);

		tx = nMotorEncoder[Turret];
		ty = SensorValue(sonic);

		x = tx  / 180 * 100;
		y = ty / 250 * 63;

		if(ix < 255){
			nxtSetPixel(x,y);
			clearline(x,y + 1,64);
			clearline(x,0,y - 1);}
		else{clearline(x,0,64);}
	}
}

task main()
{
	nMotorEncoder[Turret] = 90;
	StartTask(turretmotor);
	StartTask(scanner);
	while(true){}
}
