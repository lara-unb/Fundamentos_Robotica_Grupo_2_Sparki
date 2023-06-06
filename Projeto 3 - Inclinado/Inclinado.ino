#include <Sparki.h> // include the sparki library
 
void setup()
{
}
 
void loop()
{
    float x = sparki.accelX();
    float y = sparki.accelY();
 
    // is Sparki already facing downhill or uphill?
    if ( (x < 0.75) && (x > -0.75) )
    {
      if ( y < -0.75 ) // if sparki is facing uphill
      {
        sparki.moveForward();
        delay(650);
      }
      if ( y > 1.25 ) // if sparki is facing downhill
      {
        sparki.moveRight();
      } 
      if (-0.75 < y && y < 1.25)
      {
        sparki.moveStop();
      }
    }
    else{ // if Sparki is not facing uphill or downhill, have Sparki turn until it is
      if ( x > 0.75 ) // if tilted right
      {
        sparki.moveLeft();
      }
      if ( x < -0.75 ) // if tilted left
      {
        sparki.moveRight();
      }   
    }
    delay(100);
}
