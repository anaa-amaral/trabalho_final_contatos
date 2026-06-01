#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	int menu;
	
	printf("escolha a opcao desejada\n 1 - Incluir contato\n 2 - Listar contatos\n 3 - Consultar contato pelo nome\n 4 - Excluir contato\n 5 - Sair\n");
	scanf("%d", &menu);
	
	switch (menu){
		
		case 1:
			printf("voce entrou na opcao 1");
			break;
		
		case 2:
			printf("voce entrou na opcao 2");
			break;
			
		case 3:
			printf("voce entrou na opcao 3");
			break;
		
		case 4:
			printf("voce entrou na opcao 4");
			break;
			
		case 5:
			printf("voce entrou na opcao 5");
			break;
			
		default:
			printf("opcao invalida");
	}
	
	return 0;
}