# Projeto 3: Hill Climb

 ![Proj3](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/111db638-4216-4f96-838c-e4674699fcdd) 
 
## Noções Gerais

Nesta lição o objetivo é ensinar o Sparki a andar até o topo de alguma inclinação, até que estabilize. Para isso, o sparki conta com um acelerômetro como apresentado na figura abaixo. O acelerômetro será usado para indicar a inclinação do sparki em qual direção, e a partir disso tomar as decisões para que avance ou se posicione corretamente. O código original foi adaptado para diminuir a sensibdade à inclinação, pois o código original fazia com que mesmo em cima da mesa continuasse a tentar "subir" como se estivesse inclinado, quando o ideal seria parar. Para isso o Sparki utiliza de um acelerômetro MEM, posicionado de acorod com a figura abaixo.

<div align="center">

![Accel_Top-300x226](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/8c5abafe-be54-4736-889e-190b07ed3488)

</div>

## Funcionamento do Acelerômetro

Um acelerômetro MEM (MicroElectroMechanical) conta com estruturas microscópicas que medem a variação angular usando molas. De acordo com a inclinação feita, essas molas vão extender ou comprimir, assim variando a distância entre as placas fixas do capacitor e da mola em si (na figura é apontado como massa).

<div align="center">

![article-2018january-apply-sensor-fusion-fig2](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/b000649c-50cd-4adf-b16b-ad5dc37aae71)

</div>


A capacitância é calculada de acordo com a fórmula abaixo:

$$C=\frac{\epsilon_0+\epsilon_r+L+W}{d} [pF]$$

Onde:

- $\epsilon_0$ = constante de permissividade elétrica no vácuo: = 8.85 x $10^{-12}$ C²/Nm²;
- $\epsilon_r$ = constante permissividade relativa do dielétrico entre as placas e a massa;
- L = tamanho das placas e da massa;
- W = espessura da placa e da massa;
- d = distância entre as placas do capacitor e a parte da mola entre os capacitores;

<div align="center">

![article-2018january-apply-sensor-fusion-fig3](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/00ffba56-1f55-477e-8110-c607fffeea8e)

</div>

Importante destacar que apenas um capacitor não oferece uma capacitância grande o suficiente para leitura, então são colocadas várias estruturas semelhantes em paralelo, retornando o valor da capacitância nesse eixo, permitindo calcular então a aceleração. O acelerômetro do Sparki é um acelerômetro de 3 eixos, ou seja, consegue detectar variações nos eixos X, Y e Z. A direção das setas mostra a direção positiva da leitura. Se a aceleração for na direção oposta, a leitura será negativa. Por exemplo, se o Sparki estiver parado em uma mesa nivelada, a leitura do eixo Z deve ser -9,8 m/s². Se Sparki for virado de cabeça para baixo, a leitura será positiva de 9,8 m/s².

<div align="center">
  
  ![3-Axis](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/83a269f8-cd2d-4eb8-9af3-fcd3a748ad34)

</div>

Com a figura abaixo fica mais simples de apresentar como vai ser trabalhado cada eixo do acelerômetro.

<div align="center">

![SparkiYTilt](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/566819ef-e728-46fb-8427-e9c7f3deb0bb)

</div>

## Construção do código

Inicialmente carrega-se a biblioteca Sparki.h para que as funções do Sparki sejam usadas. Em seguida, diretamente no loop, são criadas duas variáveis: *x*, a qual vai receber o valor retornado pela função *sparki.accelX()*, a qual será usada para testar se o Sparki está mais inclinado para a esquerda ou para a direita; e *y*, a qual vai receber o valor retornado pela função *sparki.accelY()*, a qual será usada para testar se o Sparki está mais inclinado para frente ou para trás. Essas funções retornam um valor "quebrado", então as variáveis são criadas flutuantes.

```C++
#include <Sparki.h> // include the sparki library
 
void setup()
{
}
 
void loop()
{
    float x = sparki.accelX();
    float y = sparki.accelY();
```

Prosseguindo, iniciam-se as estruturas condicionais. Primeiro é testado se x está entre -0,75 e 0,75, aumentando a sensibilidade do teste em relação ao código original que usa 1 e -1 nos limites. Assim é garantido que o Sparki evite subir na diagonal. Se essa condição for satisfeita, indicando que o Sparki não está inclinado, então testam-se mais 3 condições. Primeiro, se *y* for menor que -0.75, indicando que ele está "olhando para cima", então ele prosseguirá em linha reta.
> O Código original usa 0 como referência, mas troquei por -0.75 pois se a mesa não estiver 100% no nível o Sparki irá detectar esse desnivelamento e irá andar sem necessidade.

A segunda (não depende da primeira) testa se *y* é maior que 1,25, indicando que ele está inclinado para baixo, fazendo com que ele vire à direita até que fique inclinado para cima novamente. A diferença ser maior que para a primeira condição (para ser igual seria 0,75) decorre do fato de que o sparki não tem suporte na frente, então ele pode inclinar levemente para baixo devido a qualquer frenagem, que poderia ser detectada e assim ele ia ficar em um loop de andar para frente e para trás ininterruptamente.
> A mudança do código original de virar para a direita em vez de andar para trás foi só por opção pessoal do autor.

A terceira (não depende de nenhuma das outras duas) testa se *y* está entre os dois valores mencionados anteriormente (entre -0,75 e 1,25), indicando que ele está no "ponto mais alto do morro", estabilizando-se, então ele para seus movimentos.

```C++
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
```

Em seguida uma condicional para caso essa primeira não seja satisfeita, indicando que *x* é menor que -0,75 ou maior que 0,75. Nesse caso o Sparki está inclinado para a esquerda ou para a direita. Assim, em seguida tem duas estruturas condicionais independentes entre si: um testa se *x* é maior que 0.75, indicando que o Sparki está inclinado para a direita, então o Sparki virará para a esquerda; o outro testa se *x* é menor que -0.75, indicando que o sparki está inclinado para a esquerda, então ele virará para a esquerda.

```C++
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
```

No fim um delay de 0.1 segundo apenas para diminuir a frequência dos testes.

## Referências

- Hill Climbing. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/lessons/hill-climb/. Acesso em 30 de maio de 2023.
- Accelerometer. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/accelerometer/. Acesso em 30 de maio de 2023.
- Apply Sensor Fusion to Accelerometers and Gyroscopes. DigiKey, 1995-2023. Disponível em: https://www.digikey.com.br/pt/articles/apply-sensor-fusion-to-accelerometers-and-gyroscopes. Acesso em 5 de junho de 2023
- A lei de Coulomb. UFRGS. Disponível em: https://www.if.ufrgs.br/tex/fis142/mod01/m_s03.html#:~:text=e0%3D8.85x10-12,denominada%20permissividade%20elétrica%20no%20vácuo. Acesso em 5 de junho de 2023.

## Link do Vídeo

O vídeo correspondente à execução do código pelo Sparki se encontra no seguinte link:

"Projeto Sparki Grupo 2 - Hill Climbing" - https://www.youtube.com/watch?v=cX6GFu-HJf0
