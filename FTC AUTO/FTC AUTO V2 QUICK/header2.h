float drive_power = 100;
float track_length = 55;
int one_turn = 1440;
int full_turn = 5500; //1325; 5300

#define PI 3.14159265358979323846

void turn(float t)
{
		t = (t / 360) * full_turn;

		nMotorEncoder[Drive_R] = 0;
		nMotorEncoder[Drive_L] = 0;

 		if (t>0)
 		{
 		nMotorEncoderTarget[Drive_R] = -1 *t;
 		nMotorEncoderTarget[Drive_L] = t;

		motor[Drive_R] = -1 * drive_power;
		motor[Drive_L] = drive_power;
		}

		else
		{
			nMotorEncoderTarget[Drive_R] = t;
 			nMotorEncoderTarget[Drive_L] = -1*t;

			motor[Drive_R] = drive_power;
			motor[Drive_L] = -1 * drive_power;
		}

		while((nMotorRunState[Drive_L] != runStateIdle) && (nMotorRunState[Drive_R] != runStateIdle)){wait1Msec(1);}

		motor[Drive_R] = 0;
		motor[Drive_L] = 0;

		nMotorEncoder[Drive_R] = 0;
		nMotorEncoder[Drive_L] = 0;
		}

void drive(float distance, bool dis = false)
{
	if (dis)
	{
	distance = distance / (4 * PI) * 1440;
	}

	nMotorEncoder[Drive_R] = 0;
	nMotorEncoder[Drive_L] = 0;

	nMotorEncoderTarget[Drive_R] = distance;
 	nMotorEncoderTarget[Drive_L] = distance;

	motor[Drive_R] = drive_power;
	motor[Drive_L] = drive_power;

	while((nMotorRunState[Drive_L] != runStateIdle) && (nMotorRunState[Drive_R] != runStateIdle)){wait1Msec(1);}

	motor[Drive_R] = 0;
	motor[Drive_L] = 0;

	nMotorEncoder[Drive_R] = 0;
	nMotorEncoder[Drive_L] = 0;
}
