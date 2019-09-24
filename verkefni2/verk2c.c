#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           leftMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           rightMotor,     tmotorNormal, openLoop, reversed)
#define BASETIME 650
#define BASEDIST 420
#define BASEDEG 2
//Umml dekksins er: 32.9867228627
	void drive_time(int drive_time,bool b_f){
		int dir = (b_f)? (1):(-1);
		motor(rightMotor) = dir*127;
		motor(leftMotor) = dir*127;
		wait1Msec(drive_time);
	}
	void turnL(int deg){
		while(deg*BASEDEG>SensorValue[leftEncoder]){
			motor[rightMotor]=-40;
			motor[leftMotor]=40;
		}
	}
	void turnR(int deg){
		while(deg*BASEDEG>SensorValue[rightEncoder]){
			motor[rightMotor]=40;
			motor[leftMotor]=-40;
		}
	}

	void reset_encoder(){
		SensorValue[rightEncoder]=0;
		SensorValue[leftEncoder]=0;
	}
	void stop_motors(int pop_time){
		motor[leftMotor]=0;
		motor[rightMotor]=0;
		wait1Msec(pop_time);
	}
	void drive(int dist, bool b_f){
		int dir =(b_f)?(1):(-1);
		while(dist>abs(SensorValue[rightEncoder]))
		{
			if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
			{
				// Move Forward
				motor[rightMotor] = dir*60;		    // Right Motor is run at power level 80
				motor[leftMotor]  = dir*60;		    // Left Motor is run at power level 80
			}
			else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
			{
				// Turn slightly right
				motor[rightMotor] = dir*40;		    // Right Motor is run at power level 60
				motor[leftMotor]  = dir*60;		    // Left Motor is run at power level 80
			}
			else	// Only runs if leftEncoder has counted more encoder counts
			{
				// Turn slightly left
				motor[rightMotor] = dir*60;		    // Right Motor is run at power level 80
				motor[leftMotor]  = dir*40;		    // Left Motor is run at power level 60
			}
		}
}
task main()
{
	wait1Msec(2000);

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnL(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();

		turnR(90);
		reset_encoder();

		drive(BASEDIST,true);
		stop_motors(1000);
		reset_encoder();





	}
