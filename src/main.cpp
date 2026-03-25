#include <FEH.h>
#include <Arduino.h>
#include <FEHUtility.h>
#include <FEHServo.h>
#include <FEHLCD.h>
#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

//Declarations for encoders & motors
DigitalEncoder right_encoder(FEHIO::Pin10);
DigitalEncoder left_encoder(FEHIO::Pin8);
FEHMotor right_motor(FEHMotor::Motor2,9.0);
FEHMotor left_motor(FEHMotor::Motor0,9.0);
AnalogInputPin Cds(FEHIO::Pin14);

void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    left_motor.SetPercent(percent);
    right_motor.SetPercent(-percent - 1);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

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
    right_motor.SetPercent(-percent - 3);

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
    right_motor.SetPercent(percent + 1);
    left_motor.SetPercent(-percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

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



void ERCMain()
{
    int motor_percent = 25; //Input power level here
    int expected_counts = 62*22; //Multiply this by the number of inches, initial value subject to change 

    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);


           LCD.WriteLine("Waiting for light...");
    while(Cds.Value() > 1.0) //wait for light to be less than 2.5 volts, adjust this value as necessary
    {
 
    }

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

}

expected_counts = 62*18; //move back to go back down
moveBackward(motor_percent, expected_counts);
expected_counts = 62*2;
move_forward(motor_percent, expected_counts);
expected_counts = 240; //turn 90 degrees
turn_left(motor_percent, expected_counts);
expected_counts = 62*35; //move down the ramp
move_forward(motor_percent, expected_counts);


}
