#include <Sparki.h> // include the sparki library

void setup() 
{
}

void loop() {
    // Aparentemente a sensibilidade do sensor direito é maior do que o central, que é maior que o esquerdo, portanto serão feitas compensações:
  int left   = sparki.lightLeft();   // measure the left light sensor
  int center = sparki.lightCenter(); // measure the center light sensor
  int right  = sparki.lightRight();  // measure the right light sensor

  if ( (center > left) && (center > right) ){  // if the center light is the strongest
    sparki.RGB(RGB_GREEN);
    sparki.moveForward(5); // move Sparki Forward
  }

  if ( (left > center) && (left > right) ){    // if the left light is the strongest
    sparki.RGB(RGB_YELLOW);
    sparki.moveLeft(10); // move Sparki Left
  }

  if ( (right > center) && (right > left) ){   // if the right light is the strongest
    sparki.RGB(RGB_BLUE);
    sparki.moveRight(10); // move Sparki Right
  }

  delay(100); // wait 0.1 seconds
}
