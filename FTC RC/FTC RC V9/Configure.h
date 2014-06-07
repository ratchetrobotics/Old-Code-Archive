#define resetbtn1 joy1Btn(3)
#define resetbtn2 joy2Btn(3)

#define killbtn (joystick.joy1_TopHat == 4) || (joystick.joy2_TopHat == 4)

#define overide1 joy1Btn(1)
#define overide2 joy2Btn(1)

#define boostbtn joy1Btn(6) || joy1Btn(8)
#define turnbtn joy1Btn(5) || joy1Btn(7)
#define togetherbtn joy1Btn(2)

#define leftjoy joystick.joy1_y1
#define rightjoy joystick.joy1_y2
#define troughjoy joystick.joy2_y1
#define liftjoy joystick.joy2_y2

#define unloadbtn joy2Btn(2)
#define paddle_for joy2Btn(7)
#define paddle_back joy2Btn(5)

#define flag_for joy2Btn(8)
#define flag_back joy2Btn(6)

#define liftpos nmotorencoder[lift]
#define troughpos nmotorencoder[trough]
#define paddlepos nmotorencoder[paddle]

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct{
  int full_power;
  int percision_power;
  int current_power;

  float left;
  float right;
} robot_drive_train;

typedef struct{
	int lift;
	int trough;
	int paddle;
	int flag;

	int lift_power;
	int trough_power;
	int paddle_power;
	int flag_power;
} robot_mechanism;

typedef struct{
	int lift_lower;
	int lift_upper;

	int trough_lower;
	int trough_upper;

	int paddle_lower;
	int paddle_upper;
} limiter;

robot_drive_train drive;
robot_mechanism mech;
limiter limit;

int deadband = 5;
bool kill = false;

void configure()
{
	drive.full_power = 100;
	drive.percision_power = 50;

	mech.lift_power = 5;
	mech.trough_power = 25;
	mech.paddle_power = 75;
	mech.flag_power = 100;

	limit.lift_lower = 0;
	limit.lift_upper = 100;

	limit.trough_lower = 0;
	limit.trough_upper = 100;

	limit.paddle_lower = 0;
	limit.paddle_upper = 100;
}
