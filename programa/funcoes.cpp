#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

#include "funcoes.h"

using namespace std;

/*
    Função do menu
*/

int Menu()
{
    int opc;
    cout << "\n------------------------------";
    cout << "\n--------Concessionária--------";
    cout << "\n------------------------------";
    cout << "\n-----------[1]CADASTRAR CARRO";
    cout << "\n-----------[2]EXIBIR LISTA DE CARROS";
    cout << "\n-----------[3]PESQUISAR CARRO";
    cout << "\n-----------[4]EDITAR UM  ";
    cout << "\n-----------[5]EXCLUIR";
    cout << "\n-------[6]Sair do programa-------";
    cout << "\n------------------------------";
    cout << "\nEscolha uma opcao: ";
    cin >> opc;
    return opc;
}

/*
    Função para cadastrar
*/

void CadastrarVeiculo(FILE *arquivo, Carro car2[100], int pos, int n)
{
    int i = 0;
    while (i < n)
    {
        i++;
        cout << "Dados do Carro [" << i << "]: " << endl;
        ;
        cout << "=======================================" << endl;
        cout << "Chassi: ";
        cin.ignore();
        cin.getline(car2[pos].chassi, 20);
        cout << "Marca: ";
        cin >> car2[pos].marca;
        cout << "Quantidade: ";
        cin >> car2[pos].quantidade;
        cout << "Preco: ";
        cin >> car2[pos].preco;
        cout << "Cor: ";
        cin >> car2[pos].cor;
        cout << "Quilometragem: ";
        cin >> car2[pos].quilometragem;
        fwrite(&car2[pos], sizeof(Carro), 1, arquivo);
    }

    fclose(arquivo);
}

/*
    Função para criar o arquivo
*/

int CriarArquivo(FILE *arquivo, Carro car2[100])
{
    int cont = 0;
    arquivo = fopen("dados.bin", "rb");
    if (arquivo != NULL)
    {
        while (fread(&car2[cont], sizeof(Carro), 1, arquivo) != 0)
            cont++;
    }
    else
    {
        arquivo = fopen("dados.bin", "wb");
        printf("Arquivo Criado com sucesso!");
    }
    return cont;
}

/*
    Função para mostrar todos os dados
*/

void MostrarVeiculos(Carro car0, int i)
{
    cout << "\n ----------Veiculo [" << i + 1 << "]----------";
    cout << "\nChassi: " << car0.chassi;
    cout << "\nMarca: " << car0.preco;
    cout << "\nMarca: " << car0.marca;
    cout << "\nQuantidade: " << car0.quantidade;
    cout << "\nCor: " << car0.cor;
    cout << "\nQuilometragem: " << car0.quilometragem;
}

/*
    Função para buscar registros
*/

int BuscarVeiculo(FILE *arquivo, Carro car[100], char CHASS[12])
{
    int achou = -1;
    int n_achou = -1;
    int pos = 0;
    int tam;
    tam = CriarArquivo(arquivo, car);
    while (pos < tam)
    {
        if (strcmp(car[pos].chassi, CHASS) == 0)
        {
            achou = pos;
            pos++;
        }
    }
    if (achou == -1)
    {
        cout << "\n Registro Inexistente!" << endl;
        // system("pause");
        return n_achou;
    }
    else
    {
        return achou;
    }
}

/*
    Função para editar um cadastro
*/

/*
    Função para excluir um cadastro
*/

/*
    Função para
*/