#include <stdio.h>
#include <string.h>
#define tamanhoRCA 256

/*
int * prga(int S[]){
  int iterI = 0;
  int iterJ = 0;
  int stream[tamanhoRCA];

  for(int contador; contador <= tamanhoRCA; contador++){
    iterI = (iterI + 1) % tamanhoRCA;
    iterJ = (iterJ + S[iterI]) % tamanhoRCA;

    //swap
    S[iterI] = S[iterJ];
    S[iterJ] = S[iterI];

    int K = S[(S[iterI] + S[iterJ]) % tamanhoRCA];
    stream[contador] = K;
  }

  return stream;
}
*/

int main(void) {
  char key[] ="aaa";
  char plaintext[] = "Hoje"; 
  int S[tamanhoRCA];
  int * hashStream;

  for(int i; i <= tamanhoRCA; i++){
    S[i] = i;
  } 

  int j = 0;
  int numeroDeCaracteres = strlen(plaintext);
  for(int i; i <= tamanhoRCA; i++){
    j = (j + S[i] + plaintext[i % numeroDeCaracteres]) % tamanhoRCA;
    //SWAP
    S[i] = S[j];
    S[j] = S[i];
  }

  //stream = prga(S);
  //PRGA
  int iterI = 0;
  int iterJ = 0;
  int stream[tamanhoRCA];
  for(int contador; contador <= tamanhoRCA; contador++){
    iterI = (iterI + 1) % tamanhoRCA;
    iterJ = (iterJ + S[iterI]) % tamanhoRCA;
    //swap
    S[iterI] = S[iterJ];
    S[iterJ] = S[iterI];
    int K = S[(S[iterI] + S[iterJ]) % tamanhoRCA];
    stream[contador] = K;
  }

  for(int i; i <= numeroDeCaracteres; i++){
    printf("%x", (plaintext[i] ^ stream[i]));
  }

  return 0;
}