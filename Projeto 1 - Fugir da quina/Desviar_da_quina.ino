#include <Sparki.h> // include the sparki library

void setup()
{
}
  bool QuinaDireita = false;
  bool QuinaEsquerda = true;
  
void loop() {
  int edgeLeft   = sparki.edgeLeft();   // measure the left edge IR sensor
  int edgeRight  = sparki.edgeRight();  // measure the right edge IR sensor

  int threshold = 200; // if below this value, no surface underneath
  
  if ((edgeLeft < threshold) && (QuinaDireita==false)) // if no surface underneath left sensor
  {
    sparki.moveBackward(5);
    sparki.moveRight(20);// turn right
    QuinaEsquerda=true;// Apenas pegando o sensor da esquerda
    QuinaDireita=false;
  } else if ((edgeLeft < threshold) && (QuinaDireita==true))
  {
    sparki.moveBackward(5);
    sparki.moveLeft(90);
  }

  if ((edgeRight < threshold) && (QuinaEsquerda==false))  // if no surface underneath right sensor
  {
    sparki.moveBackward(5);
    sparki.moveLeft(20); // turn left
    QuinaEsquerda=false;// Apenas pegando o sensor da esquerda
    QuinaDireita=true;
  } else if ((edgeRight < threshold) && (QuinaEsquerda==true))
  {
    sparki.moveBackward(5);
    sparki.moveRight(90);
  }

  sparki.moveForward(); // move forward
  delay(100); // wait 0.1 seconds
}
