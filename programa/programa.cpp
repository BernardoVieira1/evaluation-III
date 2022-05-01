#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
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

void AbrirArquivo(char *NArquivo)
{
  arquivo = fopen(NArquivo, "ab");
  if (arquivo != NULL)
  {
    cout << "\nArquivo aberto com sucesso";
  }
  else
  {
    cout << "\nFalha ao abrir arquivo";
  }
}

int main()
{
  int opc, n, TAM, veiculo, reg;
  char CHASS[20];
  do
  {
    TAM = CriarArquivo(arquivo, car);
    opc = Menu();
    switch (opc)
    {
    case 1:
      AbrirArquivo("dados.bin");
      cout << "\nQuantos carros deseja cadastrar? ";
      cin >> n;
      CadastrarVeiculo(arquivo, car, TAM, n);
      // fclose(arquivo);
      break;
    case 2:
      TAM = CriarArquivo(arquivo, car);
      for (int i = 0; i < TAM; i++)
      {
        MostrarVeiculos(car[100], i);
      }
      // system("\npause");
      break;
    case 3:
      cout << "\n Digite o chassi para a Busca: ";
      cin >> CHASS;
      reg = BuscarVeiculo(arquivo, car, CHASS);
      MostrarVeiculos(car[reg], reg);
      // system("pause");

      // cout << "Digite o chassi do carro";
      // cin >> chassi[20];
      // veiculo = BuscarVeiculo(arquivo, car, chassi);
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

  } while (opc != 6);
}
