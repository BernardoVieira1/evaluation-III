#include "functions.h"

int main()
{
  int opc, fim = 1;
  do
  {
    printf("------------------------------");
    printf("--------Concessionária--------");
    printf("------------------------------");
    printf("-----------Caso 1-------------");
    printf("-----------Caso 2-------------");
    printf("-----------Caso 3-------------");
    printf("-------Sair do programa-------");
    printf("------------------------------");
    printf("Escolha uma opcao: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
      printf("-----------Caso 1-------------");
      break;
    case 2:
      printf("-----------Caso 2-------------");
      break;
    case 3:
      printf("-----------Caso 3-------------");
      break;
    case 4:
      printf("-------Sair do programa-------");
      fim = 0;
      break;

    default:
      printf("--------Opcao invalida--------");
      break;
    }

  } while (fim == 0);
}