# Projeto 1: Edge Avoidance

![Proj1](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/a6b7bcca-d114-4e65-b5dd-346332a3c92c)

## Noções Gerais

Nesta lição o objetivo é ensinar o Sparki a fugir dos cantos, pois podem ser
prejudiciais à ele. Para isso, o Sparki conta com cinco sensores infravermelhos em sua
parte inferior, como apresentado na figura abaixo. Os três sensores centrais são utilizados para
outra finalidade, portanto serão utilizados apenas dois sensores, o direito e o esquerdo,
nomeados respectivamente como *Edge Right Sensor* e *Edge Left Sensor*.

<div align="center">
  
![Sensores](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/c71a82d6-d997-4011-af15-5a0186444d7b)

</div>

## Funcionamento dos sensores

  Os dois sensores do sparki são equipados com um fototransistor e um diodo emissor de luz, ou seja, o objetivo é emitir luz no espectro infravermelho com o LED, enquanto o fototransistor possui sua resistência variada de acordo com a intensidade da luz refletida sobre ele, como demonstrado na figura abaixo. A biblioteca **sparki.h** já faz os devidos cálculos que permitem que essa quantidade seja convertida em um valor inteiro, para que seja utilizado nos códigos. Os valores geralmente variam entre 1000 (valor médio para reflexão em uma folha branca padrão) e 0 (a detecção da borda geralmente retorna abaixo de 200), mas os valores podem variar de acordo com o ambiente.

<div align="center">
  
![Infrared-Sensor-Diagram](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/b3dc7bd1-df15-464b-9cee-819e7be4172f)
  
</div>

## Construção do Código

  Inicialmente carrega-se a biblioteca *Sparki.h* para que as funções do Sparki sejam usadas. Em seguida, definem-se as constantes *angle* e *backwardDistance*=5, ou seja, ângulo de 20º e a distância para trás de 5 centímetros. Pegando o código básico, a ideia é simples: se o sensor retornar um valor abaixo de 200, então vai iniciar o processo de recuar, virar à direita (se detectada a borda pelo sensor da  esquerda) ou à esquerda (se detectada  borda pelo sensor da direita). Aí que está o problema em questão, pois em um canto o Sparki irá sempre retornar à borda anterior, ficando preso a um loop. Para isso foram feitas alterações no código original.

  São deletadas as constantes para que seja feita a modificação diretamente no código e adicionadas duas variáveis booleanas "Quina Direita" e "QuinaEsquerda", inicializadas como falsa e verdadeira, respectivamente:

```C++
#include <Sparki.h>

void setup()
{
}
  bool QuinaDireita;
  bool QuinaEsquerda;
 ```
 
  Para o código que será executado repetidamente são identificadas duas variáveis: *edgeLeft* e *edgeRight*, as quais recebem as leituras de seus respectivos sensores usando as diretivas *sparki.edgeLeft()* e *sparki.edgeRight()*, além de definir também a constante *threshold* para as comparações no código, como apresentado a seguir:
 
 ```C++
 void loop() {
  int edgeLeft   = sparki.edgeLeft();   // mede a borda esquerda com o sensor IV
  int edgeRight  = sparki.edgeRight();  // mede a borda direita com o sensor IV

  int threshold = 200; // se estiver abaixo desse valor, não há superfície
 ```
 
  Começando o código temos uma estrutura condicional para analisar se a borda esquerda foi detectada **e** a variável *QuinaDireita* possui o valor falso. Se sim, o Sparki recuará 5 cm, virará 20° à direita e guardará o valor verdadeiro na variável *QuinaEsquerda*, enquanto guardará o valor verdadeiro na variável *QuinaDireita*. Se não, entrará na outra condição caso seja detectada a borda esquerda **e** a variável *QuinaDireita* possui o valor verdadeiro, recuando 5 centímetros e virando 90° à direita. Se nenhuma das condições forem satisfeitas, quer dizer  que o sensor do lado direito que foi detectado, realizando as mesmas ações porém para o lado direito.
  Com esse código, além de detectar a borda, o Sparki irá detectar se a borda está sendo repetida, continuando assim seu caminho desviando, mas se houver uma troca de bordas, indica então um canto, sendo necessário virar mais do que os 20° convencionais, que nesse caso selecionamos 90°.

Para esquerda:

 ```C++
  if ((edgeLeft < threshold) && (QuinaDireita==false)) // Se não há superfície debaixo do sensor direito
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
 ```
 
 Para direita:
 
 ```C++
   if ((edgeRight < threshold) && (QuinaEsquerda==false))  // Se não há superfície debaixo do sensor direito
  {
    sparki.moveBackward(5);  // Recue 5 cm
    sparki.moveLeft(20);     // Vire para a esquerda 20°
    QuinaEsquerda=false;     // Apenas pegando o sensor da direita
    QuinaDireita=true;
  } else if ((edgeRight < threshold) && (QuinaEsquerda==true))
  {
    sparki.moveBackward(5);
    sparki.moveRight(90);
  }
 ```
 
 Se nenhuma das condições são satisfeitas, mantém o Sparki andando para frente.
 
  ```C++
  sparki.moveForward();
  delay(100);
 ```
 
 Finalizando assim o código.
 
 ## Referências
 
 - Edge Avoidance. ArcBotics, 2012-2016. Disponível em: <https://arcbotics.com/lessons/edge-avoidance/>. Acesso em 30 de junho de 2023.
- Infrared Reflectance Sensor. ArcBotics, 2012-2016. Disponível em: <https://arcbotics.com/products/sparki/parts/infrared-reflectance-sensor/>. Acesso em 30 de junho de 2023.
