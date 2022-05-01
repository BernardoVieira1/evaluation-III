#ifndef _FUNCOES_H
#define _FUNCOES_H

/*
|   Struct carros
*/
struct Carro
{
  char chassi[20];
  char marca[20];
  int quantidade;
  float preco;
  char cor[20];
  float quilometragem;
};

/*
|   Definindo funções
*/

int Menu();
int CriarArquivo(FILE *arquivo, Carro car2[100]);
void CadastrarVeiculo(FILE *arquivo, Carro car2[100], int pos, int n);
void MostrarVeiculos(Carro car0, int i);
int BuscarVeiculo(FILE *arquivo, Carro car[100], char CHASSI[20]);

#endif