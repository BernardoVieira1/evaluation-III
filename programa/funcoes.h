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
void Cadastrarveiculo();

#endif
