#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <locale.h>

#include "funcoes.h"

using namespace std;

/*
    FUNÇÃO MENU
*/

int Menu()
{
    int opc;
    system("cls");
    cout << "\n ------------ MENU DE OPERAÇÕES ------------";
    cout << "\n |  [1] CADASTRAR VEÍCULO                  |";
    cout << "\n |  [2] EXIBIR VEÍCULOS CADASTRADOS        |";
    cout << "\n |  [3] BUSCAR VEÍCULO                     |";
    cout << "\n |  [4] EDITAR CADASTRO DE VEÍCULO         |";
    cout << "\n |  [5] EXCLUIR CADASTRO DE VEÍCULO        |";
    cout << "\n |  [6] OPÇÕES AVANÇADAS                   |";
    cout << "\n |  [7] SAIR DO PROGRAMA                   |";
    cout << "\n -------------------------------------------";
    cout << "\n   ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    return opc;
}

/*
    MENU EDITAR
*/

int MenuEditar()
{
    int opc;
    system("cls");
    cout << "\n ------------ QUAL INFORMAÇÃO DESEJA EDITAR? ------------";
    cout << "\n | [1] PREÇO                                            |";
    cout << "\n | [2] COR                                              |";
    cout << "\n | [3] CONDIÇÃO                                         |";
    cout << "\n | [4] KM rodados                                       |";
    cout << "\n --------------------------------------------------------";
    cout << "\n   ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    return opc;
}

/*
    MENU AVANÇADO
*/

int MenuAvancado()
{
    int opc;
    system("cls");
    cout << "\n ------------ QUAL INFORMAÇÃO DESEJA EDITAR? ------------";
    cout << "\n | [1] APAGAR TODO O BANCO DE DADOS                     |";
    cout << "\n | [2] APARENCIA                                        |";
    cout << "\n --------------------------------------------------------";
    cout << "\n   ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    return opc;
}

/*
    MENU APARENCIA
*/

int MenuAparencia()
{
    int opc;
    system("cls");
    cout << "\n ------------ APARENCIA ------------";
    cout << "\n | [1] DARK MODE                   |";
    cout << "\n | [2] LIGHT MODE                  |";
    cout << "\n -----------------------------------";
    cout << "\n   ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    return opc;
}

/*
    FUNÇÃO CADASTRAR
*/

void Cadastrar(FILE *arq, Veiculo vei2[100], int pos, int n)
{
    int i = 0;
    while (i < n)
    {
        i++;
        cout << "\n CADASTRO DO VEÍCULO [" << i << "]" << endl;
        ;
        cout << " Chassi: ";
        cin.ignore();
        cin.getline(vei2[pos + i].chassi, 20);
        cout << " Marca: ";
        cin >> vei2[pos + i].marca;
        cout << " Modelo: ";
        cin >> vei2[pos + i].modelo;
        cout << " Cor: ";
        cin >> vei2[pos + i].cor;
        cout << " Condicao: ";
        cin >> vei2[pos + i].condi;
        cout << " Quantidade: ";
        cin >> vei2[pos + i].quantidade;
        cout << " Preco: ";
        cin >> vei2[pos + i].preco;
        cout << " Quilometragem: ";
        cin >> vei2[pos + i].KM;
        fwrite(&vei2[pos + i], sizeof(Veiculo), 1, arq);
    }
    fclose(arq);
}

/*
    FUNÇÃO ABRIR ARQUIVO
*/

int IniciarArquivo(FILE *arq, Veiculo vei2[100])
{
    int cont = 0;
    arq = fopen("dados.bin", "rb");
    if (arq != NULL)
    {
        while (fread(&vei2[cont], sizeof(Veiculo), 1, arq) != 0)
            cont++;
    }
    else
    {
        arq = fopen("dados.bin", "wb");
        cout << "Arquivo Criado com sucesso!";
    }
    return cont;
}

/*
    FUNÇÃO EXIBIR VEICULOS
*/

void ExibirVeiculos(Veiculo vei0, int i)
{
    cout << "\n ------------------ DADOS DO VEICULO [" << i + 1 << "] -------------------";
    ;
    cout << "\n CHASSI: " << vei0.chassi;
    cout << "\n MARCA: " << vei0.marca;
    cout << "\n MODELO: " << vei0.modelo;
    cout << "\n COR: " << vei0.cor;
    cout << "\n CONDIÇÃO: " << vei0.condi;
    cout << "\n PREÇO: " << vei0.preco;
    cout << "\n QUANTIDADE: " << vei0.quantidade;
    cout << "\n KM: " << vei0.KM;
    cout << "\n";
}

/*
    FUNÇÃO BUSCAR VEICULO
*/

int BuscarVeiculo(FILE *arq, Veiculo vei2[100], char CHASS[20])
{
    int achou = -1, n_achou = -1, pos = 0, tam;
    tam = IniciarArquivo(arq, vei2);
    while (pos < tam)
    {
        if (strcmp(vei2[pos].chassi, CHASS) == 0)
        {
            achou = pos;
        }
        pos++;
    }
    if (achou == -1)
    {
        cout << "\n REGISTRO INEXISTENTE!" << endl;
        system("pause");
        return n_achou;
    }
    else
    {
        return achou;
    }
}

/*
    FUNÇÃO EDITAR CADASTRO
*/

void EditarCadastro(FILE *arq, Veiculo vei2[100], int opc)
{
    int pos, tam, i;
    char CHASS[20];
    char Cor[20];
    char Condi[10];
    float preco, quilo;
    cout << "\n Digite o CHASSI do veiculo que deseja alterar: ";
    cin >> CHASS;
    tam = IniciarArquivo(arq, vei2);
    pos = BuscarVeiculo(arq, vei2, CHASS);
    if (pos != -1)
    {
        if (opc == 1)
        {
            cout << "\n Digite o novo Valor do preco: ";
            cin >> preco;
            vei2[pos].preco = preco;
        }
        if (opc == 2)
        {
            cout << "\n Digite a nova cor: ";
            cin >> Cor;
            strcpy(vei2[pos].cor, Cor);
        }
        if (opc == 3)
        {
            cout << "\n Digite a nova condição do veiculo[novo/usado]: ";
            cin >> Condi;
            strcpy(vei2[pos].condi, Condi);
        }
        if (opc == 4)
        {
            cout << "\n Digite o novo Valor do preco: ";
            cin >> quilo;
            vei2[pos].KM = quilo;
        }
    }
    arq = fopen("dados.bin", "wb");
    for (i = 0; i < tam; i++)
    {
        fwrite(&vei2[i], sizeof(Veiculo), 1, arq);
    }
    fclose(arq);
}

/*
    FUNÇÃO PARA EXCLUIR VEICULO
*/

void ExcluirVeiculo(FILE *arq, Veiculo vei2[100], char CHASS[20])
{
    int pos, tam, i;
    char conf;
    tam = IniciarArquivo(arq, vei2);
    pos = BuscarVeiculo(arq, vei2, CHASS);
    if (pos != -1)
    {
        cout << "\n O ARQUIVO SERÁ EXCLUÍDO \n";
        cout << "\n CONFIRMAR? [s/n]:";
        cin >> conf;
        if ((conf == 'S') || (conf == 's'))
        {
            if (pos == 0)
            {
                for (i = 1; i < tam; i++)
                {
                    vei2[i - 1] = vei2[i];
                }
            }
            else
            {
                for (i = 0; i < tam; i++)
                {
                    if (i >= pos)
                    {
                        vei2[i] = vei2[i + 1];
                    }
                }
            }
            arq = fopen("dados.bin", "wb");
            for (i = 0; i < tam - 1; i++)
            {
                fwrite(&vei2[i], sizeof(Veiculo), 1, arq);
            }
            fclose(arq);
        }
    }
}