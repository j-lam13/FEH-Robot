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
DigitalEncoder right_encoder(FEHIO::Pin8);
DigitalEncoder left_encoder(FEHIO::Pin9);
FEHMotor right_motor(FEHMotor::Motor2,9.0);
FEHMotor left_motor(FEHMotor::Motor0,9.0);

void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(-percent);

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

    right_motor.SetPercent(percent);    
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


    right_motor.SetPercent(-percent);    
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
    right_motor.SetPercent(-percent);
    left_motor.SetPercent(percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void ERCMain()
{
    int motor_percent = 25; //Input power level here
    int expected_counts = 41*36; //Multiply this by the number of inches, initial value subject to change 

    int x, y; //for touch screen

    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Tap the screen to start");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    LCD.Clear(BLACK);
    
    //move forward (wall to wall), best to be above value a bit to ensure wall hit
    move_forward(motor_percent, expected_counts); 
    //stop and wait for touch and reposition    

    LCD.Write("Tap to start");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    LCD.Clear(BLACK);
    expected_counts = 41*16; //* number of inches needed;
    move_forward(motor_percent, expected_counts); //move forward again
    Sleep(1000); //wait for a second
    //move back the same amount
    expected_counts = 41*16; //* number of inches needed;
    moveBackward(motor_percent, expected_counts);
    LCD.Write("Complete");

}

