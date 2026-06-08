
#include <stdio.h>
#include <string.h>

//define o uma constante que limita a agenda para 100 contatos
#define MAX 100

//agrupa várias informações relacionadas, como uma ficha de cadastro, onde o STRUCT cria a estrutura e o TYPEDEF cria um apelido
typedef struct
{
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

//vetor que guarda vários contatos, de informações agrupadas
Contato agenda[MAX];

int totalContatos = 0;

void incluirContato()
{
    if (totalContatos >= MAX)
    {
        printf("\nAgenda cheia!\n");
        return;
    }

    printf("\nINCLUIR CONTATO\n");

    printf("Nome: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);

    printf("Telefone: ");
    scanf(" %[^\n]", agenda[totalContatos].telefone);

    printf("Email: ");
    scanf(" %[^\n]", agenda[totalContatos].email);

    totalContatos++;

    printf("\nContato cadastrado com sucesso!\n");
}

void listarContatos()
{
    int i;

    printf("\nLISTA DE CONTATOS\n");

    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    for (i = 0; i < totalContatos; i++)
    {
        printf("\nContato %d\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Email: %s\n", agenda[i].email);
    }
}

void consultarContato()
{
    char nomeBusca[50];
    int i;
    int encontrado = 0;

    printf("\nCONSULTAR CONTATO\n");

    printf("Digite o nome: ");
    scanf(" %[^\n]", nomeBusca);

    for (i = 0; i < totalContatos; i++)
    {
        if (strcmp(nomeBusca, agenda[i].nome) == 0)
        {
            printf("\nContato encontrado!\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);

            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("\nContato nao encontrado.\n");
    }
}

void excluirContato()
{
    char nomeExcluir[50];
    int i, j;
    int encontrado = 0;

    printf("\nEXCLUIR CONTATO\n");

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nomeExcluir);

    for (i = 0; i < totalContatos; i++)
    {
        if (strcmp(nomeExcluir, agenda[i].nome) == 0)
        {
            for (j = i; j < totalContatos - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }

            totalContatos--;
            encontrado = 1;

            printf("\nContato excluido com sucesso!\n");
            break;
        }
    }

    if (encontrado == 0)
    {
        printf("\nContato nao encontrado.\n");
    }
}

int main()
{
    int opcao;

    do
    {
        printf("AGENDA DE CONTATOS\n");
        printf("1 - Incluir contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Consultar contato\n");
        printf("4 - Excluir contato\n");
        printf("5 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                incluirContato();
                break;

            case 2:
                listarContatos();
                break;

            case 3:
                consultarContato();
                break;

            case 4:
                excluirContato();
                break;

            case 5:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}

