
#include <stdio.h>
#include <windows.h>
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

//variável usada para saber quantos contatos existem
int totalContatos = 0;

void incluirContato()
{
    if (totalContatos >= MAX)
    {
        printf("\nAgenda cheia!\n");//caso já tenha 100 contatos
        return;
    }

    printf("\nINCLUIR CONTATO\n");

    printf("Nome: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);

    printf("Telefone: ");
    scanf(" %[^\n]", agenda[totalContatos].telefone);

    printf("Email: ");
    scanf(" %[^\n]", agenda[totalContatos].email);//[^\n] serve para ler textos com espaços

    totalContatos++; //adiciona mais um contato a quantidade

    printf("\nContato cadastrado com sucesso!\n");
}

void ordenarContatos()
{
    int i, j;
    Contato temp;//armazena um contato temporariamente durante a troca de posições

    for (i = 0; i < totalContatos - 1; i++)//percorre todos os contatos
    {
        for (j = i + 1; j < totalContatos; j++)//compara o i com quem vem depois dele
        {
            if (strcmp(agenda[i].nome, agenda[j].nome) > 0)//o STRCMP compara duas strings
            {
                temp = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = temp;
            }
        }
    }
}

void listarContatos()
{
    int i;

    printf("\nLISTA DE CONTATOS\n");

    if (totalContatos == 0)//caso não tenha nenhum contato cadastrado
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    ordenarContatos();

    for (i = 0; i < totalContatos; i++)//começa na primeira opção, continua enquanto houver contatos e pula para o próximo contato
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
    scanf(" %[^\n]", nomeBusca);//guarda o nome digitado

    for (i = 0; i < totalContatos; i++)//procua de contato em contato
    {
        if (strcmp(nomeBusca, agenda[i].nome) == 0)//mostra o contato cadastrado
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
    char nomeExcluir[50];//nome do usuário que quer excluir
    int i, j;//variáveis auxiliares
    int encontrado = 0;//variável de controle

    printf("\nEXCLUIR CONTATO\n");

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nomeExcluir);//lê o nome inteiro digitado

    for (i = 0; i < totalContatos; i++)//percorre todos os nomes cadastrados
    {
        if (strcmp(nomeExcluir, agenda[i].nome) == 0)//encontra onde o nome digitado está
        {
            for (j = i; j < totalContatos - 1; j++)//ele começa na posição onde o nome foi encontrado
            {
                agenda[j] = agenda[j + 1];//move o próximo contato par essa posição
            }

            totalContatos--;//diminue a quantidade total de contatos
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
                system("cls");
                incluirContato();
                break;//para que o programa não execute os próximos cases

            case 2:
                system("cls");
                listarContatos();
                break;

            case 3:
                system("cls");
                consultarContato();
                break;

            case 4:
                system("cls");
                excluirContato();
                break;

            case 5:
                system("cls");
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}

