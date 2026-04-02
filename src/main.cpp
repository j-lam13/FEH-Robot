#include <FEH.h>
#include <Arduino.h>
#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHLCD.h>
#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

// RCS Delay time
#define RCS_WAIT_TIME_IN_SEC 0.35

// Defines for pulsing the robot
#define PULSE_TIME 20
#define PULSE_POWER 25

// Define for the motor power
#define POWER 25

// Orientation of AruCo Code
#define PLUS 0
#define MINUS 1


//Declarations for encoders & motors
<<<<<<< HEAD
DigitalEncoder left_encoder(FEHIO::Pin10);
DigitalEncoder right_encoder(FEHIO::Pin8);
FEHMotor right_motor(FEHMotor::Motor2,9.0);
FEHMotor left_motor(FEHMotor::Motor0,9.0);
AnalogInputPin Cds(FEHIO::Pin5);
FEHServo lever(FEHServo::Servo0);
DigitalInputPin front_left_bumper(FEHIO::Pin1);
DigitalInputPin front_right_bumper(FEHIO::Pin2);
DigitalInputPin back_left_bumper(FEHIO::Pin3);
DigitalInputPin back_right_bumper(FEHIO::Pin4);

=======
DigitalEncoder right_encoder(FEHIO::Pin10);
DigitalEncoder left_encoder(FEHIO::Pin8);
FEHMotor right_motor(FEHMotor::Motor2,9.0);
FEHMotor left_motor(FEHMotor::Motor0,9.0);
AnalogInputPin Cds(FEHIO::Pin14);
>>>>>>> main

void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
<<<<<<< HEAD
    left_motor.SetPercent(percent+ 2);
    right_motor.SetPercent(-percent + 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts )
    {
        // If either of the front bumpers are pressed, break out of the loop to stop the robot
        if(front_left_bumper.Value() == 0 && front_right_bumper.Value() == 0)
        {
            break;
        }
        if (back_left_bumper.Value() == 0 && back_right_bumper.Value() == 0)
        {
            break;
        }
    }
=======
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent - 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);
>>>>>>> main

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void moveUpRamp(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
<<<<<<< HEAD
    right_motor.SetPercent(-percent + 2); 
=======
    right_motor.SetPercent(-percent - 3);
>>>>>>> main

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void turn_right(int percent, int counts) //using encoders

{

//Reset encoder counts

right_encoder.ResetCounts();

left_encoder.ResetCounts();

//Set both motors to desired percent

//hint: set right motor backwards, left motor forward

    right_motor.SetPercent(-percent);    
    left_motor.SetPercent(-percent);

//While the average of the left and right encoder is less than counts,

//keep running motors

    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);


//Turn off motors

right_motor.Stop();

left_motor.Stop();

}
void turn_left(int percent, int counts) //using encoders

{

//Reset encoder counts

right_encoder.ResetCounts();

left_encoder.ResetCounts();

//Set both motors to desired percent


    right_motor.SetPercent(percent);    
    left_motor.SetPercent(percent);


//While the average of the left and right encoder is less than counts,

//keep running motors



    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);


//Turn off motors

right_motor.Stop();

left_motor.Stop();

}

void moveBackward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
<<<<<<< HEAD
    right_motor.SetPercent(percent - 1);
    left_motor.SetPercent(-percent - 2);
=======
    right_motor.SetPercent(percent + 1);
    left_motor.SetPercent(-percent);
>>>>>>> main

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts) {
                if(front_left_bumper.Value() == 0 && front_right_bumper.Value() == 0)
        {
            break;
        }
        if (back_left_bumper.Value() == 0 && back_right_bumper.Value() == 0)
        {
            break;
        }
    }

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void moveWithLight(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent - 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts && Cds.Value() > 1.2); //keep moving until you reach the expected counts or the light value is less than 2.5 volts, adjust this value as necessary

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

<<<<<<< HEAD
/*
 * Pulse forward a short distance using time
 */
void pulse_forward(int percent, float seconds) 
{
    // Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(percent);

    // Wait for the correct number of seconds
    Sleep(seconds);

    // Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

/*
 * Pulse counterclockwise a short distance using time
 */
void pulse_counterclockwise(int percent, float seconds) 
{
    // Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(-percent);

    // Wait for the correct number of seconds
    Sleep(seconds);

    // Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void bucket(int percent, float counts) {
      //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent - 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts )
    {
        // If either of the front bumpers are pressed, break out of the loop to stop the robot
        if(front_right_bumper.Value() == 0)
        {
            break;
        }
    }
}

/* 
 * Use RCS to move to the desired x_coordinate based on the orientation of the AruCo code
 */
void check_x(float x_coordinate, int orientation)
{
    // Determine the direction of the motors based on the orientation of the AruCo code 
    int power = PULSE_POWER;
    if(orientation == MINUS){
        power = -PULSE_POWER;
    }

    RCSPose* pose = RCS.RequestPosition();

    // Check if receiving proper RCS coordinates and whether the robot is within an acceptable range
    for (int i = 0; i < 10; i++) {
        if(pose >=0 && (pose->x < x_coordinate - 1 || pose->x > x_coordinate + 1))
        {
            if(pose->x < x_coordinate - 1)
            {
                // Pulse the motors for a short duration in the correct direction
                pulse_forward(-power, PULSE_TIME);
            }
            else if(pose->x > x_coordinate + 1)
            {
                // Pulse the motors for a short duration in the correct direction
                pulse_forward(power, PULSE_TIME);
            }
            Sleep(RCS_WAIT_TIME_IN_SEC);

            pose = RCS.RequestPosition();
        }
}
}


/* 
 * Use RCS to move to the desired y_coordinate based on the orientation of the QR code
 */
void check_y(float y_coordinate, int orientation)
{
    // Determine the direction of the motors based on the orientation of the QR code
    int power = PULSE_POWER;
    if(orientation == MINUS){
        power = -PULSE_POWER;
    }

    RCSPose* pose = RCS.RequestPosition();

    // Check if receiving proper RCS coordinates and whether the robot is within an acceptable range
    for (int i = 0; i < 10; i++) {
        while(pose >= 0 && (pose->y < y_coordinate - 1 || pose->y > y_coordinate + 1))
        {
            if(pose->y < y_coordinate - 1)
            {
                // Pulse the motors for a short duration in the correct direction
                pulse_forward(-power, PULSE_TIME);
            }
            else if(pose->y > y_coordinate + 1)
            {
                // Pulse the motors for a short duration in the correct direction
            pulse_forward(power, PULSE_TIME);
            }
            Sleep(RCS_WAIT_TIME_IN_SEC);
            
            pose = RCS.RequestPosition();
        }
    }   
}

/* 
 * Use RCS to move to the desired heading
 */
void check_heading(float heading)
{
    RCSPose* pose = RCS.RequestPosition();
while (pose >= 0 && (pose->heading < heading - 1 || pose->heading > heading + 1))
    {
        RCSPose* pose = RCS.RequestPosition();
        if(pose >= 0 && (pose->heading < heading - 1 || pose->heading > heading + 1))
        {
            if(pose->heading < heading - 1)
            {
                // Pulse the motors for a short duration in the correct direction
                pulse_counterclockwise(-PULSE_POWER, PULSE_TIME);
            }
            else if(pose->heading > heading + 1)
            {
                // Pulse the motors for a short duration in the correct direction
                pulse_counterclockwise(PULSE_POWER, PULSE_TIME);
            }
            Sleep(RCS_WAIT_TIME_IN_SEC);
        }
    }
    
}
void move_forward_middle(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent - 1);
    float start_time = TimeNow();
    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts )
    {
       if(TimeNow() - start_time > 1.5) 
       {
        break;
    }
    
    }

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}



=======
>>>>>>> main


void ERCMain()
{
    int motor_percent = 25; //Input power level here
    int expected_counts = 62*22; //Multiply this by the number of inches, initial value subject to change 
<<<<<<< HEAD
    float A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y, E_x, E_y;
    float A_heading, B_heading, C_heading, D_heading, E_heading;
    lever.SetMax (2500);
    lever.SetMin (500);
    // RCS.InitializeTouchMenu("1240E8QWF");
=======
>>>>>>> main

    // FEHFile* fptr = SD.FOpen("milestoneFourLocations.txt", "r");
    // SD.FScanf(fptr, "%f%f%f", &A_x, &A_y, &A_heading); //A is apple stump
    // SD.FScanf(fptr, "%f%f%f", &B_x, &B_y, &B_heading); //B is apple dropoff
    // SD.FScanf(fptr, "%f%f%f", &C_x, &C_y, &C_heading); //C is Left lever
    // SD.FScanf(fptr, "%f%f%f", &D_x, &D_y, &D_heading); //D is middle lever
    // SD.FScanf(fptr, "%f%f%f", &E_x, &E_y, &E_heading); //E is right lever
    // SD.FClose(fptr);
    lever.SetDegree(91); //picks up bucket
    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);


           LCD.WriteLine("Waiting for light...");
    while(Cds.Value() > 1.0) //wait for light to be less than 2.5 volts, adjust this value as necessary
    {
 
    }
<<<<<<< HEAD
=======

// hit button on back
motor_percent = 25;
expected_counts = 62*1; //Multiply this by the number of inches, initial value subject to change
moveBackward(motor_percent, expected_counts);
// expected_counts = 31; //Multiply this by the number of inches, initial value subject to change
// move_forward(motor_percent, expected_counts);
expected_counts = 140; //turn 45 degrees, test this (this might go right not too sure)
turn_right(motor_percent, expected_counts);
expected_counts = 62*6; //forward to the ramp
move_forward(motor_percent, expected_counts);

motor_percent = 40;
expected_counts = 62*27; //move up the ramp - test actual placement location and adjust expected counts accordingly
moveUpRamp(motor_percent, expected_counts);
motor_percent = 25;
expected_counts = 155; //move forward off the ramp
moveBackward(motor_percent, expected_counts);
expected_counts = 240; //turn 90 degrees, test this (this might go right not too sure)
turn_left(motor_percent, expected_counts); //turn left to face the target rv Was here and grant smells
expected_counts = 62*7; 
moveBackward(motor_percent, expected_counts); //move back against the wall to straighten out

expected_counts = 62*30;
moveWithLight(motor_percent, expected_counts); //move forward to the target
if (Cds.Value() < .9) {
    LCD.WriteLine("Light Found");
}
Sleep(3000);
if (Cds.Value() > .6) 
{
    LCD.WriteLine("Blue Found");
    expected_counts = 240; //turn 90 degrees, test this 
    turn_left(motor_percent, expected_counts); 
    expected_counts = 62*2; 
    move_forward(motor_percent, expected_counts);
    expected_counts = 240; //turn 90 degrees, test this 
    turn_right(motor_percent, expected_counts);
    expected_counts = 62*8;
    move_forward(motor_percent, expected_counts);

}
else
{
        LCD.WriteLine("Red Found");
    expected_counts = 240; //turn 90 degrees, test this 
    turn_right(motor_percent, expected_counts); 
    expected_counts = 62*2; 
    move_forward(motor_percent, expected_counts);
    expected_counts = 240; //turn 90 degrees, test this 
    turn_left(motor_percent, expected_counts);
    expected_counts = 62*8;
    move_forward(motor_percent, expected_counts);
>>>>>>> main

//hit button on back
//pid
lever.SetDegree(91); //picks up bucket
motor_percent = 25;
expected_counts = 62*3; //Multiply this by the number of inches, initial value subject to change
move_forward_middle(motor_percent, expected_counts);
expected_counts = 506; //arbitrary value
moveBackward(motor_percent, expected_counts);
expected_counts = 135;
turn_left(motor_percent, expected_counts);
expected_counts = 545; //move to the bucket (value is subject to change))
moveBackward(motor_percent, expected_counts);
lever.SetDegree(105); //keeps bucket there
Sleep(100); //slight pause to make sure bucket is secure
expected_counts = 62*17; //move back to the ramp
moveUpRamp(motor_percent, expected_counts);
expected_counts = 250;
turn_left(motor_percent, expected_counts);
expected_counts = 62*17; //move up the ramp until the wall things are hit (adjust method later to use bump switches)
move_forward(motor_percent, expected_counts);
expected_counts = 250; 
turn_left(motor_percent, expected_counts);
expected_counts = 62*7; //move to position in line of drop off
moveBackward(motor_percent, expected_counts);
expected_counts = 62*6;
move_forward(motor_percent, expected_counts); //move to the drop off
expected_counts = 250;
turn_right(motor_percent, expected_counts);
expected_counts = 62*3;
move_forward(motor_percent, expected_counts); //move to axis of drop off
expected_counts = 250;
turn_right(motor_percent, expected_counts);
expected_counts = 62*15; //move to drop off
bucket(motor_percent, expected_counts); 
lever.SetDegree(91); //drop
expected_counts = 62*3;
moveBackward(motor_percent, expected_counts);
expected_counts = 250;
turn_left(motor_percent, expected_counts);
expected_counts = 62*3; 
move_forward(motor_percent, expected_counts); //move to the levers
//RCS shenanigans
    // if(RCS.GetLever() == 0)
    // {
    //     check_x(C_x, PLUS);
    //     expected_counts = 270;
    //     turn_right(motor_percent, expected_counts);
    //     check_y(C_y, PLUS);
    //     check_heading(C_heading);
    //     expected_counts = 62; //move to the lever
    //     move_forward(motor_percent, expected_counts);
    //     //servo to flip
    // } 
    // else if(RCS.GetLever() == 1)
    // {
    //     check_x(D_x, PLUS);
    //     expected_counts = 270;
    //     turn_right(motor_percent, expected_counts);
    //     check_y(D_y, PLUS);
    //     check_heading(D_heading);
    //     expected_counts = 62; //move to the lever
    //     move_forward(motor_percent, expected_counts);
    //     //servo to flip
    // }
    // else if(RCS.GetLever() == 2)
    // {
    //     check_x(E_x, PLUS);
    //     expected_counts = 270;
    //     turn_right(motor_percent, expected_counts);
    //     check_y(E_y, PLUS);
    //     check_heading(E_heading);
    //     expected_counts = 62; //move to the lever
    //     move_forward(motor_percent, expected_counts);
    //     //servo to flip
    // }

//sleep 105, 95 degrees base
}
<<<<<<< HEAD
=======

expected_counts = 62*18; //move back to go back down
moveBackward(motor_percent, expected_counts);
expected_counts = 62*2;
move_forward(motor_percent, expected_counts);
expected_counts = 240; //turn 90 degrees
turn_left(motor_percent, expected_counts);
expected_counts = 62*35; //move down the ramp
move_forward(motor_percent, expected_counts);


}
>>>>>>> main
