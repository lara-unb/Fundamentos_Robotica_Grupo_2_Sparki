# Projeto 3: Hill Climb

![Segue-a-luz-mané](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/1010dc98-408f-4b8d-8cca-aa7b56c5c089)

## Noções Gerais

Nesta lição o objetivo é ensinar o Sparki a fugir ou a ir em direção à luz. Para esse caso foi escolhido apenas que ele seguisse a luz. Para isso o Sparki conta com sensores de luz na parte anterior, como apresentado na imagem abaixo, nomeados *Light Left*, *Light Center* e *Light Right*. Com o auxílio dos sensores será detectada a direção da luz, e assim, a depender da intensidade o Sparki irá se posicionar a favor da detecção pelo sensor central.

<div align="center">

![Top-Light-Sensor2](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/1c2a6e5a-1202-46eb-8a09-2d3d5e772b24)

</div>
  
## Funcionamento do Sensor

Esses sensores são basicamente fototransistores. Um transistor comum permite a corrente entre o coletor e o emissor de acordo com a corrente na base. No caso do fototransistor a base é exposta, ou seja, a intensidade da luz exposta sobre a base é diretamente roporcional à corrente que passa do coletor ao emissor. 

<div align="center">

  ![Phototransistor-Symbol](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/a5a14778-8fca-4a37-9f4d-92c371566951) ![Photo-transisor](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/0930542c-838f-41f2-b13e-b52ff898ae9b)

</div>

No caso do Sparki, será utilizada a diferença de intensidade entre os 3 sensores para saber a direção da luz. 

- Se o sensor da esquerda detectar mais luz que os outros sensores, o Sparki irá virar para a esquerda (usou-se o LED amarelo);
- Se o sensor central detectar mais luz que os outros sensores, o Sparki irá andar para frente (usou-se o LED verde);
- Se o sensor da direita detectar mais luz que os outros sensores, o Sparki irá virar para a direita (usou-se o LED azul);

## Construção do Código

Inicialmente carrega-se a biblioteca Sparki.h para que as funções do Sparki sejam usadas. Em seguida, diretamente no loop, são definidas três variáveis: 

- *left*, que vai receber os valores do sensor *Light Left* usando *sparki.lightLeft()*;
- *center*, que vai receber os valores do sensor *Light Center* usando *sparki.lightCenter()*;
- *right*, que vai receber os valores do sensor *Light Right* usando *sparki.lightRight()*;

```C++
#include <Sparki.h> // include the sparki library

void setup() 
{
}

void loop() {
  int left   = sparki.lightLeft();   // measure the left light sensor
  int center = sparki.lightCenter(); // measure the center light sensor
  int right  = sparki.lightRight();
```

Em seguida foram iniciadas as estruturas condicionais independentes entre si, as quais são apenas 3. A primeira testa se o sensor central recebe luz mais intensa que os outros dois. Se sim, andará para frente 5 centímetros. Além disso, o LED RGB acende a cor verde.
> Os 5 centímetros, em relação ao 0 do código original, são para que o Sparki tenha mais tempo para estabilizar antes de testar as outras condições.

A segunda testa se o sensor esquerdo recebe luz mais intensa em relação aos outros dois sensores. Se sim, o Sparki irá virar 10° para a esquerda. Além disso, o LED RGB acende a cor amarela. Semellhante à segunda, a terceira testará se o sensor da direita recebe luz mais intensa do que os outros dois sensores. Se sim, o Sparki virará 10° para a direira. Além disso, o LED RGB acende a cor azul.
> Os 10 graus, também em relação ao 0 do código original, são para que o sparki não fique virando como se tivesse espasmos.

## Referências

- Follow and Avoid Light. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/lessons/follow-light/. Acesso em 30 de maio de 2023.
- Light Sensor. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/light-sensor/. Acesso em 30 de maio de 2023.
- What is a Phototransistor : Circuit Diagram & Its Working. ElProCus, 2013 - 2023. Disponível em: https://www.elprocus.com/phototransistor-basics-circuit-diagram-advantages-applications/. Acesso em 06 de junho de 2023.

## Link do Vídeo

O vídeo correspondente à execução do código pelo Sparki se encontra no seguinte link:

"Projeto Sparki Grupo 2 - Follow Light" - https://www.youtube.com/watch?v=ilLFo1vOrvk
