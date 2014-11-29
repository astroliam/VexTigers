#pragma config(Motor,  port2,           leftDrive,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftScissor,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           rightScissor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive,    tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous() // prototype autonomous program
{
	//if (SensorValue(dgtl1) == 0) //turn left
	//{
	//	motor[clawMotor] = 50; //hold cube tightly
	//  motor[leftScissor] = 127; //lift up scissor lift
	//  motor[rightScissor] = 127;
	//  wait1Msec(2000); //wait 2 seconds
	//  motor[leftScissor] = 0;
	//  motor[rightScissor] = 0;

 // 	motor[leftDrive] = -63; //turn left
 // 	motor[rightDrive] = 63;
 // 	wait1Msec(700); //wait 0.7 seconds
 //		motor[leftDrive] = 0;
 //	 	motor[rightDrive] = 0;
 // 	wait1Msec(1000); //wait 1 second

 //	 	motor[leftDrive] = 40; //drive forward
 //	 	motor[rightDrive] = 40;
 // 	wait1Msec(500); //wait 0.5 seconds
 // 	motor[leftDrive] = 0;
 // 	motor[rightDrive] = 0;
 //		wait1Msec(1000); //wait 1 second

 // 	motor[leftScissor] = -127; //lower scissor lift
 // 	motor[rightScissor] = -127;
 // 	wait1Msec(1500); //wait 1.5 seconds
 // 	motor[leftScissor] = 0;
 // 	motor[rightScissor] = 0;

	//	motor[clawMotor] = -127; // open claw
 // 	wait1Msec(500); //wait 0.5 seconds
 // 	motor[clawMotor] = 0;
 // }
 // else if (SensorValue(dgtl1) == 1) //turn right
	//{
		motor[clawMotor] = 50; // hold cube tightly
	  motor[leftScissor] = 127; //lift up scissor lift
	  motor[rightScissor] = 127;
	  wait1Msec(2000); //wait 2 seconds
	  motor[leftScissor] = 0;
	  motor[rightScissor] = 0;

  	motor[leftDrive] = 63; //turn right
  	motor[rightDrive] = -63;
  	wait1Msec(700); //wait 0.7 seconds
 		motor[leftDrive] = 0;
 	 	motor[rightDrive] = 0;
  	wait1Msec(1000); //wait 1 second

 	 	motor[leftDrive] = 40; //drive forward
 	 	motor[rightDrive] = 40;
  	wait1Msec(500); //wait 0.5 seconds
  	motor[leftDrive] = 0;
  	motor[rightDrive] = 0;
 		wait1Msec(1000); //wait 1 second

  	motor[leftScissor] = -127; //lower scissor lift
  	motor[rightScissor] = -127;
  	wait1Msec(1500); //wait 1.5 seconds
  	motor[leftScissor] = 0;
  	motor[rightScissor] = 0;

		motor[clawMotor] = -127; // open claw
  	wait1Msec(500); //wait 0.5 seconds
  	motor[clawMotor] = 0;
  //}

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	while (true)
	{
	  motor[leftDrive] = (vexRT[Ch2] + vexRT[Ch1]) / 2; //drive control
	  motor[rightDrive] = (vexRT[Ch2] - vexRT[Ch1]) / 2;

	  if (vexRT[Btn8UXmtr2] == 1) // scissor lift move up
	  {
	  	motor[leftScissor] = 127;
	  	motor[rightScissor] = 127;
	  }
	  else if (vexRT[Btn8DXmtr2] == 1) // scissor lift move down
	  {
	  	motor[leftScissor] = -127;
	  	motor[rightScissor] = -127;
		}
		else // scissor lift stop moving
		{
			motor[leftScissor] = 0;
	  	motor[rightScissor] = 0;
		}

		if (vexRT[Btn7UXmtr2] == 1) // claw open
	  {
	  	motor[clawMotor] = 127;
	  }
	  else if (vexRT[Btn7DXmtr2] == 1) // claw close
	  {
	  	motor[clawMotor] = -127;
		}
		else // claw stop moving
		{
			motor[clawMotor] = 0;
		}


	}
}
