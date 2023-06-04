#include <Sparki.h> // include the sparki library

  int LED=21;
  int Tenta=0;
  
void setup() 
{
}

void loop() {
  int threshold = 500;

  int lineEsquerda   = sparki.lineLeft();   // measure the left IR sensor
  int lineMei = sparki.lineCenter();        // measure the center IR sensor
  int lineDireita = sparki.lineRight();     // measure the right IR sensor

  if ( lineMei < threshold ) // if line is below left line sensor
  {  
    Tenta=0;
    sparki.moveForward(); // vai meu fi
    if (LED > 10)
    {
      sparki.RGB(RGB_GREEN);
    }
    else
    {
      sparki.RGB(75,100,0);
      LED = LED + 1;
    }
  }

  if ((lineMei > threshold)&&( lineDireita < threshold ))  // if line is below right line sensor
  {  
    sparki.moveRight(); // Vira meu fi, pra direita
    sparki.RGB(75,100,0);
    LED = 0;
  }

  if ((lineMei > threshold)&&(lineEsquerda < threshold))
  {
    sparki.moveLeft(); // Vira meu fi, pra esquerda
    sparki.RGB(75,100,0);
    LED = 0;
  }

  // Se nenhuma linha for detectada, procurar:

  if ((lineMei > threshold) && (lineEsquerda > threshold) && (lineDireita > threshold))
  {
    sparki.RGB(RGB_BLUE);
    if (Tenta < 1)
    {
      sparki.moveForward(5);
    }
    if (Tenta < 9) // Virando 90º para ver se há alguma linha à direita
    {
      sparki.moveRight(10);
      Tenta = Tenta + 1;  
    }
    else if (Tenta < 27) // Virando 180º para ver se há alguma linha à esquerda
    {
      sparki.moveLeft(10);
      Tenta = Tenta + 1;
    }
    else
    {
      sparki.RGB(RGB_RED);
      sparki.moveStop();
    }
  }

delay(100); // wait 0.1 seconds
}
