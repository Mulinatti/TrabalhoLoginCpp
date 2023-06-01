No começo do semestre foi feita uma revisão para relembrar 
os conceitos básicos da linguagem C, onde foi visto sobre 
matrizes e ponteiros. Matriz são vetores multidimensionais
de linhas e colunas. Em C, um ponteiro é uma variável que 
armazena o endereço de memória de outra variável.
Ele permite acessar e manipular diretamente os dados armazenados na memória.
Ponteiros oferecem flexibilidade e eficiência, mas também requerem cuidado
para evitar erros de acesso inválido à memória. 

Posteriormente foi apresentado o contéudo sobre bibliotecas,
por exemplo a time.h, e como criar sua própria biblioteca. 
A biblioteca time.h fornece funções para trabalhar com informações 
relacionadas ao tempo e datas. Ela permite que os programadores acessem, 
manipulem e formem representações de tempo, além de realizar cálculos de data e hora. 

Para criar uma biblioteca em C, você precisa ter um arquivo ".h", um arquivo de cabeçalho,
que vai conter a declaração das funções. Posteriormente criar um arquivo ".c", que vai conter
todo o código das funções declaradas no arquivo de cabeçalho.
Após isso na seu arquivo main, você pode fazer a chamada dessas funções e utilizá-las. 

Foi abordado a manipulação de arquivos binários e txt utilizando C e C++,
através da biblioteca stdlib e fstream. A principal abordagem foi abrir estes arquivos
com a função "fopen", podendo escolher se vai ser do tipo write, read, append ou binary,
assim conseguindo alterar o contéudo do arquivo se desejar. 

Uma breve aula, com lógica de programação e início do conteúdo de gráficos com C/C++,
com a apresentação de várias bibliotecas, porém foi utilizado o GLFW, em que deveríamos
instalá-lo e criar uma simples janela com o GLFW. 

Por último foi apresentado um contéudo à programação utilizando um website para simular
um arduíno e manipulá-lo. Nas aulas foi utilizado um exemplo de um sensor de umidade 
que mostrava no display a porcentagem de umidade presente no solo.
Junto disto foi apresentado brevemente o contéudo acerca de manipulação de threads
e a biblioteca de criação de interfaces do próprio windows, chamada "windows.h".  