#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	char nome, email;
	int menu, telefone;
	
	printf(" 1 - Incluir contato\n 2 - Listar contatos\n 3 - Consultar contato pelo nome\n 4 - Excluir contato\n 5 - Sair\n");
	printf("Escolha a opcao desejada: ");
	scanf("%d", &menu);
	
	switch (menu){
		
		case 1: //add contatos
			printf("Digite seu nome");
			scanf("%c", &nome);
			printf("Digite seu email");
			scanf("%c", &email);
			printf("Digite seu numero de telefone(sem caracteres especiais)");
			scanf("%i", &telefone);
			break;
		
		case 2: //listar contatos
			printf("voce entrou na opcao 2");
			break;
			
		case 3: //pesquisar contatos
			printf("Digite o nome para pesquisa");
			scanf("%c", &nome);
			break;
		
		case 4: //excluir contatos
			printf("voce entrou na opcao 4");
			break;
			
		case 5: //sair
			printf("Encerrando.... ");
			break;
			
		default:
			printf("opcao invalida");
	}
	
	return 0;
}