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
#define flagpos nmotorencoder[flag]

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define avg(a,b) ((a+b)/2)

typedef struct{
	int full_power;
	int norm_power;

	int current_power;

	tMotor mmotor;
} drive_train_motor;


typedef struct{
	int upper_bound;
	int lower_bound;

	int norm_power;
	int current_power;

	tMotor mmotor;

} mechanism_motor;

drive_train_motor ltread;
drive_train_motor rtread;

mechanism_motor lift;
mechanism_motor trough;
mechanism_motor paddle;
mechanism_motor flag;

int deadband = 5;
bool kill = false;

void configure()
{
	rtread.mmotor = Rtread;
	rtread.full_power = 100;
	rtread.norm_power = 50;

	ltread.mmotor = Ltread;
	ltread.full_power = 100;
	ltread.norm_power = 50;

	lift.mmotor = Lift;
	lift.norm_power = 5;
	lift.lower_bound = 0;
	lift.upper_bound = 100;

	trough.mmotor = Trough;
	trough.norm_power = 25;
	trough.lower_bound = 0;
	trough.upper_bound = 100;

	paddle.mmotor = Paddle;
	paddle.norm_power = 75;
	paddle.lower_bound = 0;
	paddle.upper_bound = 100;

	flag.mmotor = Flag;
	flag.norm_power = 100;
}
