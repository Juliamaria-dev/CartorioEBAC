#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,","); 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coleta do nome do usu�rio 
	scanf("%s",nome); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,nome); //salva a vari�vel nome 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,","); 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome do usu�rio 
	scanf("%s",sobrenome); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo sobrenome e o "a" significa atualizar 
	fprintf(file,sobrenome); //salva a vari�vel sobrenome 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando o cargo do usu�rio 
	scanf("%s",cargo); //%s refere-se a string 
	
	file = fopen(arquivo, "a"); //abre o arquivo cargo e o "a" significa atualizar 
	fprintf(file,cargo); //salva a vari�vel cargo 
	fclose(file); //fecha o arquivo 
	
    system("pause"); //pausa o sistema

}

int consulta() //fun��o de consulta 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //fun��o define cpf 
	char conteudo[200]; //fun��o que limita caracteres a serem inseridos pelo usu�rio 
	
	printf("Digite o CPF a ser consultado: "); //coletando o cpf do usu�rio 
	scanf("%s",cpf); //%s refere-se a string 
	
	FILE *file; //procura arquivo no sistema 
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o arquivo cpf for nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //imprimir na tela do usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //imprimir as informa��es na tela do usu�rio
		printf("%s", conteudo); //%s refere-se a string 
		printf("\n\n");
	}
	
	fclose(file); //fecha o arquivo 
	system("pause"); //pausa o sistema 


}

int deletar() //fun��o deletar cpf 
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta o cpf do usu�rio 
	scanf("%s",cpf); //%s refere-se a string 
		
		
	
	FILE *file;	//procura arquivo no sistema 
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o cpf do usu�rio for nulo 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //imprimir msg na tela do usu�rio 
		system("pause"); //pausa o sistema 
	}
	else
	{
		fclose(file);
		remove(cpf); //fun��o deletar cpf 
		FILE *file;	//abre o arquivo cpf 
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso!.\n"); //imprime ao usu�rio que o cpf foi deletado com sucesso. 
			system("pause"); //pausa o sistema 
		}
	}
	fclose(file); //fecha arquivo 
	
}
	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{	

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");//fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
			system("cls"); //responsavel por limpar a tela
	
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
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
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			} //fim da sele��o
		}
	}
	
	else
		printf("Senha incorreta!");	//imprime mensagem ao usu�rio 

}
