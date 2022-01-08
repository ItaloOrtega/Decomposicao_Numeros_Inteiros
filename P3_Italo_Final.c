#include <stdio.h>
#include <stdlib.h>

void vetor(int *NV, int N, char l);//Função para definir os valores de N e M
void percorre(int NV[], int MV[], int N, int M);//Função que irá percorrer o vetor N, para criar os conjuntos de M
void comb(int mv[],int m,int tam,int i,int aux[],int y, int val, int *p, FILE *arq);//Função recursiva que monta os conjuntos

int main(){
  int N = 0, M = 0;
  
  while(N<1 || M < 5|| N > 100 || M > 20){//While para que sejam criados somente: 0<N<101 e 4<M<21
    printf("\nDigite N e M respectivamente:\n");
    scanf("%d %d",&N, &M);
  }
  int NV[N], MV[M];

  vetor(MV, M, 'M');//Cria os valores de M

  vetor(NV, N, 'N');//Cria os valores de N

  percorre(NV, MV, N, M);//Mostra as combinações possíveis

  return 0;
}

void vetor(int *NV, int N, char l){//Escreve os valores para N/M
  int i = 0;
  int flag = 1, floor = 1;//Variavel de erro e Variavel de chão dos valores
  if(l == 'M')//Caso l == M, o menor valor possivel é 0
    floor = 0;
  while(flag == 1){//While para criar dados até ter somente dados validos
    flag = 0;//Desativa a flag de erro
    i = 0;//Para iniciar na primeira posição
    printf("\nDigite os %d numeros de %c:\n", N, l);
    while(i < N){//While para ler os N valores
      scanf(" %d", &NV[i]);
      int y = 0;
      while(y < i){//While para verificar se existe já o valor que acabou de ser escrito no vetor
        if(NV[y] == NV[i]){//Tendo um valor já escrito, ativa a flag
          flag = 1;
          printf("\nErro! Valor %d duplicado!\n",NV[i]);
        }
        y++;
      }
      if(NV[i] < floor || NV[i] > 1000000){//Erro caso o valor for menor que o chão ou maior que 10^6
        printf("\nErro! Valor %d nao valido!\n",NV[i]);//Será necessário colocar novos dados novamentes
        flag = 1;//Aciona a flag
      }
      i++;
    }
  }
}

void percorre(int NV[], int MV[], int N, int M){//Vai montar todas as combinações possíveis de N com valores de M
  int i = 0;
  FILE *arq;//Criação do arquivo de escrita

  arq = fopen("conjuntos.txt", "w");//Cria o arquivo para escrita

  if(arq == NULL){//Dando algum erro com o arquivo
    printf("Nao foi possivel abrir o arquivo!!!\n");
    exit(0);
  }

  while(i < N){//While para fazer todos os valores de N
    int y = 1;//Váriavel que é o tamanho do conjunto atual, começa com 1
    int soma = 0;//Variavel que mostra se a combinação é uma composição válida
    fprintf(arq, "\n----- Valor = %d -----\n",NV[i]);//Escreve o valor atual que estamos procurando o conjunto
    while(y < M+1){//while que vai aumentando o tamanho do conjunto
      int aux[y];//Vetor auxiliar possui o tamanho do conjunto de decomposição atual, ou seja, decomposição com 1 número, 2 números, etc...
      comb(MV, M, y, 0, aux, 0, NV[i], &soma, arq);//Envia o vetor de conjunto, o tamanho do vetor de conjunto, tamanho da decomposição, posição atual do vetor de conjunto,
      //vetor auxiliar, posição atual do vetor auxiliar, o valor que será decomposto e o endereço da váriavel de soma
      y++;
    }
    printf("\nValor N = %d | Qtd. de Conjuntos = %d\n", NV[i], soma);
    i++;
  }
  fclose(arq);//Fecha o arquivo
}

void comb(int mv[],int m,int tam,int i,int aux[],int y, int val, int *p, FILE *arq){
  int soma = 0, j = 0;//Variavel soma
  if (i == tam){//i sendo igual ao tamanho total do vetor de conjunto, significa que montamos um conjunto 
    while(j<tam){//Faz a soma dos valores que estão no vetor auxiliar
      soma = soma + aux[j];//A soma é feita para ver se a sua combinação resulta ou não no valor que esta sendo decomposto
      j++;
    }
    if (soma == val){//Soma sendo igual o valor que está sendo decomposto, é incrementado 1 a váriavel
      j = 0;
      fprintf(arq, "(");
      while(j<tam){//While para escrever no arquivo os valores do conjunto
        if(j == tam-1)//Caso for o ultimo valor
          fprintf(arq, " %d",aux[j]);
        else//Se não
          fprintf(arq, " %d,",aux[j]);
        j++;
      }
      fprintf(arq, " )\n");
      *p = *p + 1;//Aumenta em 1 os conjuntos validos para o valor
    }
    return;
  }
 
  if (y >= m)//Quando não tem mais valores no vetor aux, logo é retornado pois já não é mais possível criar um conjunto, pois seria algum com valores a menos
    return;
 
  aux[i] = mv[y];//Posição atual do vetor auxiliar recebe o valor da posição atual do vetor de conjunto
  comb(mv, m, tam, i+1, aux, y+1, val, p, arq);//Posição atual do vetor de conjunto e do auxiliar são icrementadas e a função é chamada denovo.
  //Ou seja uma combinação que irá possuir o valor que acabou de ser alocado no vetor aux.
 
  comb(mv, m, tam, i, aux, y+1, val, p, arq);//Somente a posição atual do vetor conjunto é incrementada e a função é chamada novamente
  //Uma combinação que vai possuir um valor diferente, pois o valor que acabou de ser alocado em aux, será realocado

  //Ou seja, é basicamente uma arvore, onde a cada iteração você faz a escolha de pegar o valor atual ou não, assim gerando conjuntos diferentes que não se repetem.
  //Assim gerando combinações válidas ou não, por não serem do tamanho desejado.
}