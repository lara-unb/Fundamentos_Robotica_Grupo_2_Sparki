## Projeto Sparki Grupo 2 - Line Following

![Proj2](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/189677b6-6a81-4afe-a7dd-97db679f776a)

## Noções Gerais

Nesta lição o objetivo é ensinar o Sparki a seguir a linha que estiver abaixo dele. Para isso, o Sparki conta com cinco sensores infravermelhos em sua parte inferior, como apresentado na figura abaixo. Os dois sensores de canto são utilizados para outra finalidade, portanto serão utilizados apenas os três sensores centrais: o direito, central e o esquerdo, nomeados respectivamente como *Line Right Sensor*, *Center Line Sensor* e *Right Line Sensor*.

<div align="center">
  
![Sensores](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/cdaa1b15-9bd1-4bea-a8bd-1872d2d0311a)

</div>

Além disso, nesse código será também usado o diodo emissor de luz (LED) que vem equipado com três cores, que a depender da intensidade, formam outras cores desejadas. No código em si, serão utilizadas 4 cores:

-  **Verde**, simbolizando a detecção da linha e seguindo sua direção;
-  **Amarelo**, simbolizando que o sensor central não identifica nenhuma linha mas um dos outros dois sensores identifica, então está fazendo a correção da direção, e  após corrigi-la, mantém por 1 segundo até que troque para verde;
-  **Azul**, simbolizando sua confusão, pois estava seguindo a linha, porém por algum motivo ele não detecta nenhuma em seus 3 sensores. Por isso, ele avança 5 centímetros, vira 90° à direita e então 180° à esquerda (para que retorne à direção original, e então mais 90°). Caso não encontre, ele desiste;
-  **Vermelho**, simbolizando que ele procurou a linha, mas não achou, então desistiu.
 
## Funcionamento dos sensores

  Os dois sensores do sparki são equipados com um fototransistor e um diodo emissor de luz, ou seja, o objetivo é emitir luz no espectro infravermelho com o LED, enquanto o fototransistor possui sua resistência variada de acordo com a intensidade da luz refletida sobre ele, como demonstrado na figura abaixo. A biblioteca **sparki.h** já faz os devidos cálculos que permitem que essa quantidade seja convertida em um valor inteiro, para que seja utilizado nos códigos. Os valores geralmente variam entre 1000 (valor médio para reflexão em uma folha branca padrão) e 0 (a detecção da borda geralmente retorna abaixo de 200), mas os valores podem variar de acordo com o ambiente.

<div align="center">
  
![Infrared-Sensor-Diagram](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/b3dc7bd1-df15-464b-9cee-819e7be4172f)
  
</div>
 
## Funcionamento dos LEDS

Como mencionado anteriormente, o LED RGB pode ser programado para apresentar a cor desejada a depender da intensidade dos três leds presentes na construção. Para mudança das cores utiliza-se a sintaxe *sparki.RGB(red, green, blue);*, onde cada cor varia de 0 a 100. O Sparki já possui algumas cores pré definidas:

<div align="center">

| Cor        | R   | G   | B   |
|------------|-----|-----|-----|
| RGB_RED    | 100 | 0   | 0   |
| RGB_ORANGE | 90  | 100 | 0   |
| RGB_YELLOW | 60  | 100 | 0   |
| RGB_GREEN  | 0   | 100 | 0   |
| RGB_BLUE   | 0   | 0   | 100 |
| RGB_PINK   | 90  | 0   | 100 |
| RGB_INDIGO | 20  | 0   | 100 |
| RGB_VIOLET | 60  | 0   | 100 |
| RGB_WHITE  | 60  | 100 | 90  |
| RGB_OFF    | 0   | 0   | 0   |

</div>

A roda abaixo apresenta as intensidades necessárias para a construção de cores que forem desejadas. Basta substituir o nome *red*, *green* ou *blue* pela intensidade aproximada

<div align="center">

![Rodadecores](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/955e5e83-7df5-4e2c-9a70-29b53daa1a8b)

</div>

## Construção do código 
 
 Inicialmente carrega-se a biblioteca Sparki.h para que as funções do Sparki sejam usadas. Em seguida são definidas duas variáveis para auxílio do código: *LED*, com valor inicial 21, e *Tenta* com valor inicial 0. Os valores iniciais são explicados posteriormente. Essas variáveis foram definidas aqui pois precisamos desses valores apenas na inicialização do código, e definindo fora do *setup* faz com que sejam variáveis **globais**, acessáveis também no loop.

```C++
#include <Sparki.h> // inclui a biblioteca Sparki

  int LED=21;
  int Tenta=0;
```

  Iniciando o loop, é definida a variável *threshold* como 500. A decisão é semelhante ao exemplo do *[Edge Avoidance](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/tree/main/Projeto%201%20-%20Fugir%20da%20quina)*, com a diferença que nesse caso seleciona-se 500 para que uma linha pouco menos escura, que ainda reflita alguma luminosidade, seja considerada linha. Além disso, outras três variáveis são definidas para receber o valor numérico dos três sensores descritos anteriormente: *lineEsquerda*, *lineMei* e *lineDireita*, usando respectivamente *sparki.lineLeft()*, *sparki.lineCenter()* e *sparki.lineRight()*.
  
```C++
void loop() {
  int threshold = 500;

  int lineEsquerda   = sparki.lineLeft();   // mede o sensor IV esquerdo
  int lineMei = sparki.lineCenter();        // mede o sensor IV central
  int lineDireita = sparki.lineRight();     // mede o sensor IV direito
```

Em seguida é construída a primeira estrutura condicional, onde é testado se há linha sendo percebida pelo sensor central se o valor for menor que o definido no *threshold*. Se sim, a variável *Tenta* é resetada (volta para 0) e o sparki mantém andando para frente. Para mudança do LED encontra-se dentro dessa mesma estrutura outra estrutura condicional, onde testa se a variável *LED* já passou de 10, mudando para verde, se não, mantém em amarelo e soma 1 à contagem do valor da variável *LED*. Isso acontece pois ao final do código geral deve-se esperar 0.1 segundos, ou seja, a cada 0.1 segundos soma-se 1 a *LED*, fazendo com que se o Sparki está a aproximadamente 1 segundo andando sem interrupções, o LED mude de amarelo para verde. 

```C++
  if ( lineMei < threshold ) 
  {  
    Tenta=0;
    sparki.moveForward(); 
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
```

Se essa condição não for verdadeira, testa-se se **não há** linha no sensor central e se há linha no sensor direito. Se sim, então o Sparki irá virar para a direita até que essa condição seja insatisfeita (ou seja, detectou-se a linha no sensor central), além de mudar o LED para amarelo e resetar a variável *LED* (volta para 0).

Se essa condição não for verdadeira, é então testada a mesma condição para o sensor esquerdo, fazendo virar para a esquerda, mudando o LED para amarelo e resetando *LED* (voltando para 0).

```C++
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
```

Caso nenhuma dessas condições seja detectada, indica que não há linhas em nenhum dos três sensores. Quando isso ocorre, foi programado um estado de "confusão" do sparki, fazendo com que ele ative o LED na cor azul. A primeira estrutura condicional testa se nenhum dos três sensores detecta a linha. Se sim, o LED muda para azul, e em seguida encontra-se outra estrutura condicional testando se a variável *Tenta* é menor que 1 - ou seja, 0, indicando que é a primeira vez que entra na estrutura após tanto tempo estando seguindo uma linha -, fazendo com que o sparki avance 5 cetímetros. As próximas condições testam se o valo de *Tenta* é menor que 9 e 27, para que o Sparki vire 90° à direita e depois 180° para a esquerda. Se nenhuma das condições for satisfeita o sparki liga o LED vermelho e fica parado, indicando desistência.

```C++
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
```

## Referências

- Line Following. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/lessons/line-following/. Acesso em 30 de junho de 2023.
- Infrared Reflectance Sensor. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/infrared-reflectance-sensor/. Acesso em 30 de junho de 2023.
- RGB LED. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/rgb-led/. Acesso em 30 de junho de 2023.

## Link do Vídeo

O vídeo correspondente à execução do código pelo Sparki se encontra no seguinte link:

"Projeto Sparki Grupo 2 - Line Following" - https://youtu.be/vDYGgxufhh4
