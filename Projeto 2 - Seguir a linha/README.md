## Projeto Sparki Grupo 2 - Line Following

![Proj2](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/189677b6-6a81-4afe-a7dd-97db679f776a)

## Noções gerais

Nesta lição o objetivo é ensinar o Sparki a seguir a linha que estiver abaixo dele. Para isso, o Sparki conta com cinco sensores infravermelhos em sua parte inferior, como apresentado na figura abaixo. Os dois sensores de canto são utilizados para outra finalidade, portanto serão utilizados apenas os três sensores centrais: o direito, central e o esquerdo, nomeados respectivamente como *Line Right Sensor*, *Center Line Sensor* e *Right Line Sensor*.

<div align="center">
  
![Sensores](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/cdaa1b15-9bd1-4bea-a8bd-1872d2d0311a)

</div>

Além disso, nesse código será também usado o diodo emissor de luz (LED) que vem equipado com três cores, que a depender da intensidade, formam outras cores desejadas. Para a seleção, utiliza-se como base a roda de cores abaixo, apresentando as intensidades necessárias de cada um dos três LEDs para que alcance a cor desejada.

<div align="center">

![Rodadecores](https://github.com/lara-unb/Fundamentos_Robotica_Grupo_2_Sparki/assets/130604394/955e5e83-7df5-4e2c-9a70-29b53daa1a8b)

</div>
 
No código em si, serão utilizadas 4 cores:

-  **Verde**, simbolizando a detecção da linha e seguindo sua direção;
-  **Amarelo**, simbolizando que o sensor central não identifica nenhuma linha mas um dos outros dois sensores identifica, então está fazendo a correção da direção, e  após corrigi-la, mantém por 1 segundo até que troque para verde;
-  **Azul**, simbolizando sua confusão, pois estava seguindo a linha, porém por algum motivo ele não detecta nenhuma em seus 3 sensores. Por isso, ele avança 5 centímetros, vira 90° à direita e então 180° à esquerda (para que retorne à direção original, e então mais 90°). Caso não encontre, ele desiste;
-  **Vermelho**, simbolizando que ele procurou a linha, mas não achou, então desistiu.
 
## Referências

- Line Following. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/lessons/line-following/. Acesso em 30 de junho de 2023.
- Infrared Reflectance Sensor. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/infrared-reflectance-sensor/. Acesso em 30 de junho de 2023.
- RGB LED. ArcBotics, 2012-2016. Disponível em: https://arcbotics.com/products/sparki/parts/rgb-led/. Acesso em 30 de junho de 2023.

## Link do Vídeo

O vídeo correspondente à execução do código pelo Sparki se encontra no seguinte link:

"Projeto Sparki Grupo 2 - Line Following" - https://youtu.be/vDYGgxufhh4
