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
 int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado./n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do Usu�rio ou ID: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o Cpf do Usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
    remove (cpf); //deletar cpf do usu�rio
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio ID n�o se encontra no sistema!/n");
		system("pause");
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
	printf( "Op��o: " ); //fim do menu
	
	scanf( "%d",&opcao); //armazenando a escolha do usu�rio 
	
	system( "cls"); //respons�vel por limpar a tela
	
	
	switch(opcao) //in�cio da sele��o do menu
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
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
	    break;		
	} //fim da sele��o
	
		
}
	
}
