#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variável 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,","); 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coleta do nome do usuário 
	scanf("%s",nome); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,nome); //salva a variável nome 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome do usuário 
	scanf("%s",sobrenome); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo sobrenome e o "a" significa atualizar 
	fprintf(file,sobrenome); //salva a variável sobrenome 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando o cargo do usuário 
	scanf("%s",cargo); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo cargo e o "a" significa atualizar 
	fprintf(file,cargo); //salva a variável cargo 
	fclose(file); //fecha o arquivo 
	
    system("pause"); //pausa o sistema

}

int consulta() //função de consulta 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //função define cpf 
	char conteudo[200]; //função que limita caracteres a serem inseridos pelo usuário 
	
	printf("Digite o CPF a ser consultado: "); //coletando o cpf do usuário 
	scanf("%s",cpf); //%s refere-se a string 
	
	FILE *file; //procura arquivo no sistema 
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o arquivo cpf for nulo 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //imprimir na tela do usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); //imprimir as informações na tela do usuário
		printf("%s", conteudo); //%s refere-se a string 
		printf("\n\n");
	}
	
	fclose(file); //fecha o arquivo 
	system("pause"); //pausa o sistema 


}

int deletar() //função deletar cpf 
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta o cpf do usuário 
	scanf("%s",cpf); //%s refere-se a string 
		
		
	
	FILE *file;	//procura arquivo no sistema 
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o cpf do usuário for nulo 
	{
		printf("O usuário não se encontra no sistema!.\n"); //imprimir msg na tela do usuário 
		system("pause"); //pausa o sistema 
	}
	else
	{
		fclose(file);
		remove(cpf); //função deletar cpf 
		FILE *file;	//abre o arquivo cpf 
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n"); //imprime ao usuário que o cpf foi deletado com sucesso. 
			system("pause"); //pausa o sistema 
		}
	}
	fclose(file); //fecha arquivo 
	
}
	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{	

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");//fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usuário
		
			system("cls"); //responsavel por limpar a tela
	
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
	
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			} //fim da seleção
		}
	}
	
	else
		printf("Senha incorreta!");	//imprime mensagem ao usuário 

}
