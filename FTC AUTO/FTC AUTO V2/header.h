int drive_power = 50; //percent

const float B = 6; //17.5
const int A = 1; //4
const float T = B/A;
const int R = 360; // 1440
const float W = A * PI;
const int D = R * T;

float heading = 90;

const int Xmin = 0;
const int Xmax = 144;

const int Ymin = 0;
const int Ymax = 144;

float Y = 0;//ultrasonic distance + distance from ultrasonic sensor to middle of bot;
float X = 0;
float F = B;
float G = Y;




//this program requires X-coordinate (X) and Y-coordinate (Y)
//as well as destination X-coordinate (F) and destination Y-coordinate (G)
//and current heading (heading)

void go(int F, int G)
{
	float N = 0;
    if (F == X || G == Y)
    {
        N = heading;
    }
    else
    {
        N = acos((F - X) / sqrt((F - X) + (G - Y)));
    }

    heading = heading - N;

    if (heading > 180 || heading < -179)
    {
        heading = -1 * heading;
    }

    heading = -1 * (heading / 720) * T;

    nxtDisplayCenteredTextLine(0 ,"%f", heading * R);

    while(nNxtButtonPressed != 3){wait1Msec(1);}

    eraseDisplay();

    wait10Msec(10);

    //nMotorEncoderTarget[Drive_L] = heading * R;
    //nMotorEncoderTarget[Drive_R] = -1 * heading * R;

    //motor[Drive_L] = drive_power;
    //motor[Drive_R] = drive_power;

    //while(!nMotorRunState[Drive_L] != runStateIdle && !nMotorRunState[Drive_R] != runStateIdle){wait1Msec(1);}

    //motor[Drive_L] = 0;
    //motor[Drive_R] = 0;

    float H = sqrt((F-X)+(G-Y)) / W;

    nxtDisplayCenteredTextLine(0 ,"%f", H * R);

    while(nNxtButtonPressed != 3){wait1Msec(1);}

    eraseDisplay();

    //nMotorEncoderTarget[Drive_L] = H * R;
    //nMotorEncoderTarget[Drive_R] = H * R;

    //while(!nMotorRunState[Drive_L] != runStateIdle && !nMotorRunState[Drive_R] != runStateIdle){wait1Msec(1);}

    //motor[Drive_L] = 0;
    //motor[Drive_R] = 0;


    X = F;
    Y = G;
}





//#define PI 3.14159265358979323846

//void turn(float t)
//{
//		t = (t / 360) * full_turn;

//		nMotorEncoder[Drive_R] = 0;
//		nMotorEncoder[Drive_L] = 0;

// 		if (t>0)
// 		{
// 		nMotorEncoderTarget[Drive_R] = -1 * t;
// 		nMotorEncoderTarget[Drive_L] = t;

//		motor[Drive_R] = -1 * drive_power;
//		motor[Drive_L] = drive_power;
//		}

//		else
//		{
//			nMotorEncoderTarget[Drive_R] = t;
// 			nMotorEncoderTarget[Drive_L] = -1*t;

//			motor[Drive_R] = drive_power;
//			motor[Drive_L] = -1 * drive_power;
//		}

//		while((nMotorRunState[Drive_L] != runStateIdle) && (nMotorRunState[Drive_R] != runStateIdle)){wait1Msec(1);}

//		motor[Drive_R] = 0;
//		motor[Drive_L] = 0;

//		nMotorEncoder[Drive_R] = 0;
//		nMotorEncoder[Drive_L] = 0;
//		}

//void drive(float distance, bool dis = false)
//{
//	if (dis)
//	{
//	distance = distance / (2 * radius * PI) * one_turn;
//	}

//	nMotorEncoder[Drive_R] = 0;
//	nMotorEncoder[Drive_L] = 0;

//	nMotorEncoderTarget[Drive_R] = distance;
// 	nMotorEncoderTarget[Drive_L] = distance;

//	motor[Drive_R] = drive_power;
//	motor[Drive_L] = drive_power;

//	while((nMotorRunState[Drive_L] != runStateIdle) && (nMotorRunState[Drive_R] != runStateIdle)){wait1Msec(1);}

//	motor[Drive_R] = 0;
//	motor[Drive_L] = 0;

//	nMotorEncoder[Drive_R] = 0;
//	nMotorEncoder[Drive_L] = 0;
//}

//void drive_point(int hor, int ver)
//{
//    float distance = sqrt(hor^2+ver^2)
//}
