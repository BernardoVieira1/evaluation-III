#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "funcoes.h"

using namespace std;

Carro car[100];
FILE *arquivo;
int TAM;

/*
    Função para Criar arquivo
*/

void CriarArquivo(char *NArquivo)
{
  arquivo = fopen(NArquivo, "ab");
  if (arquivo != NULL)
  {
    cout << "Arquivo criado com sucesso";
  }
  else
  {
    cout << "Erro ao criar o arquivo";
  }
  fclose(arquivo);
}

int main()
{
  int opc;
  do
  {
    opc = Menu();
    switch (opc)
    {
    case 1:
      cout << "5";
      break;
    case 2:
      cout << "5";
      break;
    case 3:
      cout << "5";
      break;
    case 4:
      cout << "5";
      break;
    case 5:
      cout << "5";
      break;
    case 6:
      cout << "Programa finalizado";
      break;

    default:
      cout << "Opcao invalida!";
      break;
    }

  } while (opc != 1);
}