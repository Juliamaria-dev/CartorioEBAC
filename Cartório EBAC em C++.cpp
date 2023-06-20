#include<stdio.h > //biblioteca de comunica��o com o usu�rio
#include<stdlib.h > //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h > //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das string

int registro () //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,nome); //salva a variavel nome 
	fclose(file); //fecha o arquivo 
	
    file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado:  "); //coletando sobrenome do usu�rio 
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a");//abre o arquivo sobrenome e o "a" significa atualizar
	fprintf(file,sobrenome); //salva a variavel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado:  "); //coletando cargo do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo cargo e o "a" significa atualizar
	fprintf(file,cargo); //salva a variavel cargo
	fclose(file); //fecha o arquivo 
	
	system("pause"); //pausa o sistema
}
 int consulta() //fun��o de consulta 
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //fun��o que pede o cpf ao usu�rio
	char conteudo[200]; //limite de n�meros inteiros a serem cadastrados pelo usu�rio
	
	printf("Digite o Cpf a ser consultado: "); //imprimir ao usu�rio o cpf a ser cadastrado 
	scanf("%s",cpf);
	
	
	FILE *file; //procura no programa
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o arquivo do cpf for nulo 
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado./n"); //imprimir na tela do usu�rio 
	}
	
	while(fgets(conteudo,200,file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do Usu�rio ou ID: "); //imprimir na tela do usu�rio suas informa��es 
		printf("%s",conteudo); 
		printf("\n\n"); //imprimir conte�do das informa��es do usu�rio
	}
	
	system("pause"); //fun��o de pausar o sistema
}

int deletar () //fun��o caso o usu�rio deseje deletar o seu cpf 
{
	char cpf[40]; //fun��o que pede o cpf ao usu�rio
	
	printf("Digite o Cpf do Usu�rio a ser deletado: "); //imprimir na tela do usu�rio o cpf a ser deletado 
	scanf("%s",cpf);
	
    remove (cpf); //deletar cpf do usu�rio
	
	FILE*file; //procura no programa 
	file = fopen(cpf,"r"); //abre o arquivo cpf 
	
	if(file == NULL) //se o arquivo do cpf for nulo 
	{
		printf("O usu�rio ID n�o se encontra no sistema!/n"); //imprimir na tela do usu�rio 
		system("pause"); //fun��o de pausar o sistema 
	}
}

int main ()
{
 int opcao=0;	//Definindo vari�veis
 int laco=1;
	
	for( laco=1;laco=1;)
	{
	
	system("cls");	
		
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //�n�cio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t 1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf("\t4-Sair do sistema\n\n");
	printf( "Op��o: " ); //fim do menu
	
	scanf( "%d",&opcao); //armazenando a escolha do usu�rio 
	
	system( "cls"); //respons�vel por limpar a tela
	
	
	switch(opcao) //in�cio da sele��o do menu
	{
		case 1:
		registro(); //fun��o registro do usu�rio 
		break;
		
		case 2:
		consulta(); //fun��o consulta do usu�rio 
		break;
	
		case 3:
		deletar(); //fun��o deletar do usu�rio 
		break;
		
		case 4:
		printf ("Obrigado por utilizar o sistema!\n"); //imprimir na tela do usu�rio 
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n"); //imprimir na tela do usu�rio 
		system("pause");
	    break;		
	} //fim da sele��o
	
		
}
	
}
