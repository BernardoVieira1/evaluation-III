#ifndef _FUNCOES_H
#define _FUNCOES_H

/*
|   Struct carros
*/
struct Veiculo
{
  char chassi[20];
  char marca[30];
  char modelo[20];
  char cor[20];
  char condi[10];
  float preco;
  int quantidade;
  float KM;
};

/*
|   Definindo funções
*/

int Menu();
int MenuEditar();
int MenuAvancado();
int MenuAparencia();
int IniciarArquivo(FILE *arq, Veiculo vei2[100]);
void ExibirVeiculos(Veiculo vei0, int i);
void Cadastrar(FILE *arq, Veiculo vei2[100], int pos, int n);
int BuscarVeiculo(FILE *arq, Veiculo vei2[100], char CHASS[20]);
void EditarCadastro(FILE *arq, Veiculo vei2[100], int opc);
void ExcluirVeiculo(FILE *arq, Veiculo vei2[100], char CHASS[20]);

#endif