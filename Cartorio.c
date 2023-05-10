#include<stdio.h > //biblioteca de comunicação com o usuário
#include<stdlib.h > //biblioteca de alocação de espaço de memória
#include <locale.h > //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidas das string

int registro () //Função responsável por cadastrar usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de string
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo nome e o "a" significa atualizar
	fprintf(file,nome); //salva a variavel nome 
	fclose(file); //fecha o arquivo 
	
    file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado:  "); //coletando sobrenome do usuário 
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a");//abre o arquivo sobrenome e o "a" significa atualizar
	fprintf(file,sobrenome); //salva a variavel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado:  "); //coletando cargo do usuário
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
	printf("Não foi possível abrir o arquivo, não localizado./n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do Usuário ou ID: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o Cpf do Usuário a ser deletado: ");
	scanf("%s",cpf);
	
    remove (cpf); //deletar cpf do usuário
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário ID não se encontra no sistema!/n");
		system("pause");
	}
}

int main ()
{
 int opcao=0;	//Definindo variáveis
 int laco=1;
	
	for( laco=1;laco=1;)
	{
	
	system("cls");	
		
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //ínício do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t 1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf( "Opção: " ); //fim do menu
	
	scanf( "%d",&opcao); //armazenando a escolha do usuário 
	
	system( "cls"); //responsável por limpar a tela
	
	
	switch(opcao) //início da seleção do menu
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
		
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
	    break;		
	} //fim da seleção
	
		
}
	
}
