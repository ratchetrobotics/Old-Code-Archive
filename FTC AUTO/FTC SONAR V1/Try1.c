#pragma config(Sensor, S2,     sonicSensor,    sensorSONAR)
#pragma config(Motor,  motorA,          Turret,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          Left,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          Right,         tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "ultrasonic2-finalversion.c"

task turret()
{
	while(true)
	{
		nMotorEncoderTarget[Turret] = 0;
		motor[Turret] = -1 * motorMaxPower;
		while(nMotorRuntState[Turret] != runStateIdle){}
		motor[Turret] = 0;

		nMotorEncoderTarget[Turret] = 180;
		motor[Turret] = motorMaxPower;
		while(nMotorRuntState[Turret] != runStateIdle){}
		motor[Turret] = 0;
	}
}

task drive()
{

}

task main()
{
motorInitialize();
motorRun();
}
