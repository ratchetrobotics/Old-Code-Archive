#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     DR,             tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     DL,             tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, PIDControl)

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


#include "main.c"
#include "subrutines.c"

typedef struct Undercarrage
{
   float left;
   float right;

   int power;
   int max_speed;
   int low_speed;
} Driver;

int deadband = 5;
