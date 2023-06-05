# Projeto 3: Hill Climb

 ![Proj3](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/111db638-4216-4f96-838c-e4674699fcdd) 
 
## Noções Gerais

Nesta lição o objetivo é ensinar o Sparki a andar até o topo de alguma inclinação, até que estabilize. Para isso, o sparki conta com um acelerômetro como apresentado na figura abaixo. O acelerõmetro será usado para indicar a inclinação do sparki em qual direção, e a partir disso tomar as decisões para que avance ou se posicione corretamente. O código original foi adaptado para diminuir a sensibdade à inclinação, pois o código original fazia com que mesmo em cima da mesa continuasse a tentar "subir" como se estivesse inclinado, quando o ideal seria parar.

## Funcionamento do Acelerômetro

O acelerômetro do Sparki conta com estruturas microscópicas que medem a variação angular usando molas. De acordo com a inclinação feita, essas molas vão extender ou comprimir, assim variando a distância entre as placas fixas do capacitor e da mola em si (na figura é apontado como massa).

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

Inicialmente carrega-se a biblioteca Sparki.h para que as funções do Sparki sejam usadas. 

## Referências

- Hill Climbing. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/lessons/hill-climb/. Acesso em 30 de maio de 2023.
- Accelerometer. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/accelerometer/. Acesso em 30 de maio de 2023.
- Disponível em: https://www.digikey.com.br/pt/articles/apply-sensor-fusion-to-accelerometers-and-gyroscopes. Acesso em 5 de junho de 2023
- Disponível em: https://www.if.ufrgs.br/tex/fis142/mod01/m_s03.html#:~:text=e0%3D8.85x10-12,denominada%20permissividade%20elétrica%20no%20vácuo. Acesso em 5 de junho de 2023.

## Link do Vídeo

O vídeo correspondente à execução do código pelo Sparki se encontra no seguinte link:

"Projeto Sparki Grupo 2 - Hill Climbing" - ??
