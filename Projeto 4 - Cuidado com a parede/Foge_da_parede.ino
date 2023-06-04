#include <Sparki.h>

void setup()
{
    sparki.servo(SERVO_CENTER); // Center the Servo
    sparki.beep();
}
 
void loop()
{
    sparki.RGB(RGB_GREEN); // turn the light green
    sparki.moveForward(); // move Sparki forward
    int cm = sparki.ping(); // measures the distance with Sparki's eyes
    // int cm = 21; //Teste
 
    if(cm != -1) // make sure its not too close or too far
    { 
        if(cm < 20) // if the distance measured is less than 20 centimeters
        {
            sparki.RGB(RGB_RED); // turn the light red
            sparki.beep(); // beep!
            sparki.moveStop();
            delay(500);
            sparki.RGB(75,100,0);
            sparki.moveBackward(10);// back up 10 centimeters
            sparki.moveRight(30); // rotate right 30 degrees
            delay(500);
        }
    }
    delay(100); // wait 0.1 seconds (100 milliseconds)
}
