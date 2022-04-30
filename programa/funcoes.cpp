#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "funcoes.h"

using namespace std;

/*
    Função do menu
*/

void Menu()
{
    int opc;
    cout << "\n------------------------------";
    cout << "\n--------Concessionária--------";
    cout << "\n------------------------------";
    cout << "\n-----------[1]CADASTRO-----------";
    cout << "\n-----------[2]BUSCAR-------------";
    cout << "\n-----------[3]EDITAR-------------";
    cout << "\n-----------[4]EXCLUIR------------";
    cout << "\n-------[5]Sair do programa-------";
    cout << "\n------------------------------";
    cout << "\nEscolha uma opcao: ";
    cin >> opc;
}

/*
    Função para cadastrar
*/

void Cadastrarveiculo()
{
}

/*
    Função para Criar arquivo
*/

void CriarArquivo(char *NArquivo)
{
    FILE *arquivo;
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

/*
    Função para iniciar o arquivo
*/

/*
    Função para editar um cadastro
*/

/*
    Função para excluir um cadastro
*/

/*
    Função para mostrar todos os dados
*/

/*
    Função para buscar registros
*/

/*
    Função para
*/