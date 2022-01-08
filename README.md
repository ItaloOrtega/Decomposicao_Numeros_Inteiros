# Decomposicao_Numeros_Inteiros
Projeto em C em que dado uma quantidade N e M de números inteiros, calcula-se as decomposições possíveis dos N números pelos M números. 

Definições do Projeto:

1 Defini¸c˜ao

N´umeros inteiros podem ser decompostos em conjuntos de n´umeros inteiros
distintos, como por exemplo, podemos decompor o inteiro 10 em conjuntos com
dois (7 e 3, por ex.), trˆes (1, 3 e 6, por ex.) ou quatro inteiros (1, 2, 3 e 4).
De outro modo, dado um conjunto de inteiros podemos utilizar subconjuntos
deles para formar outros inteiros, como por exemplo, dados os inteiros 2, 3 e 4
podemos formar os inteiros 2, 3, 4, 5, 6, 7 e 9.
Assim, dado um conjunto de inteiros ´e poss´ıvel determinar se um outro
n´umero inteiro pode ser obtido por uma combina¸c˜ao dos n´umeros daquele conjunto. Essa determina¸c˜ao, feita de forma recursiva, ´e bastante eficiente, desde
que se identifique o processo de gera¸c˜ao das combina¸c˜oes.

2 O que deve ser feito

Escreva um programa que ir´a receber inicialmente dois inteiros, N e M, sendo
que N ´e o n´umero de n´umeros a serem decompostos e M ´e a quantidade de
n´umeros dispon´ıveis para a descomposi¸c˜ao, recebendo em seguida os M inteiros
e, posteriormente, os N n´umeros para decompor.
Escreva uma fun¸c˜ao recursiva para determinar de quantos modos diferentes
podemos combinar os n´umeros do conjunto, SEM REPETIC¸ OES, para gerar ˜
um dado n´umero. Por exemplo, para o conjunto composto por (1, 2, 3, 4, 5)
podemos gerar o n´umero 10 de 3 formas diferentes ((1, 2, 3, 4), (1, 4, 5), (2, 3, 5)).
No caso de n˜ao ser poss´ıvel gerar o n´umero N, ent˜ao seu programa deve
responder com o valor 0.

3 Entrada de dados

O programa deve receber trˆes linhas de dados. Na primeira linha temos dois
inteiros, N e M, descritos acima.
Na segunda linha temos M inteiros, que formam o conjunto de n´umeros que
podem ser usados para decompor um inteiro positivo qualquer.
1
Na terceira linha temos N inteiros Ki
, que devem ser decompostos na forma
descrita acima.
1 ≤ Ki ≤ 106
, 1 ≤ N ≤ 100, 5 ≤ M ≤ 20.

4 Sa´ıda de dados

Seu programa deve produzir uma linha para cada Ki
, contendo a quantidade de
combina¸c˜oes geradoras daquele n´umero, usando os n´umeros do conjunto dado
ou o valor 0 caso n˜ao seja poss´ıvel decompor o n´umero Ki
.
