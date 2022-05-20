#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <locale.h>

#include "funcoes.h"

using namespace std;

Veiculo vei[100];
FILE *arq;
int TAM;

/*
  FUNÇÃO PARA CRIAR ARQUIVO
*/

void CriarArquivo(char *NArquivo)
{
  arq = fopen(NArquivo, "ab");
  if (arq != NULL)
  {
    printf("\n  [ O ARQUIVO FOI ABERTO ]\n");
  }
}

int main()
{

  setlocale(LC_ALL, "portuguese");

  int opc, opc2, opc3, n, i, reg, senha;
  char CHASS[20];
  TAM = IniciarArquivo(arq, vei);

  system("color f0");

  do
  {
    opc = Menu();
    switch (opc)
    {
    case 1:
      CriarArquivo("dados.bin");
      cout << "\nDIGITE A QUANTIDADE DE VEÍCULOS PARA CADASTRAR: ";
      cin >> n;
      Cadastrar(arq, vei, TAM, n);
      fclose(arq);
      break;
    case 2:
      system("cls");
      TAM = IniciarArquivo(arq, vei);
      cout << "\n-------------------------------------------------------------" << endl;
      cout << " NUMERO DE REGISTROS NO BANCO DE DADOS: " << TAM << endl;
      cout << "-------------------------------------------------------------" << endl;
      for (i = 0; i < TAM; i++)
      {
        ExibirVeiculos(vei[i], i);
      }
      cout << "\n";
      system("pause");
      break;
    case 3:
      cout << " -------------------------------------------------------------";
      cout << "\n DIGITE O CHASSI PARA BUSCAR O VEÍCULO: ";
      cin >> CHASS;
      reg = BuscarVeiculo(arq, vei, CHASS);
      if (reg != -1)
      {
        ExibirVeiculos(vei[reg], reg);
        system("pause");
      }
      break;
    case 4:
      opc2 = MenuEditar();
      EditarCadastro(arq, vei, opc2);
      break;
    case 5:
      cout << "\n DIGITE O CHASSI DO VEÍCULO QUE DESEJA EXCLUIR: ";
      cin >> CHASS;
      ExcluirVeiculo(arq, vei, CHASS);
      fclose(arq);
      break;
    case 6:
      opc2 = MenuAvancado();
      if (opc2 == 1)
      {
        cout << "Digite a senha: ";
        cin >> senha;
        if (senha == 17)
        {
          arq = fopen("dados.bin", "w");
        }
      }
      if (opc2 == 2)
      {
        opc3 = MenuAparencia();
        if (opc3 == 1)
        {
          system("color 0f");
        }
        else
        {
          system("color f0");
        }
      }
      break;
    case 7:
      break;
    default:
      cout << "O VALOR INFORMADO É INVÁLIDO!";
      break;
    }
  } while (opc != 7);
}