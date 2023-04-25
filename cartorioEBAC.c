#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, nome); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, sobrenome); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, cargo); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa na tela e espera novo comando
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file==NULL)
	{
		printf("Arquivo n�o localizado.\n"); //informa��o de que usu�rio n�o foi encontrado
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //coletando info do usu�rio
		printf("%s", conteudo); //salva valor da vari�vel
		printf("\n\n"); //inserir espa�o
	}
	
	system("pause"); //pausa na tela e espera novo comando
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	remove(cpf); //comando para remover o CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" significa ler
	
	if(file== NULL); //se o n�mero do CPF n�o existir
	{
		printf("O usu�rio n�o se encontra no sistema.\n"); //resposta para o usu�rio n�o encontrado
		system("pause"); //pausa na tela e espera novo comando
	}
	
	
	}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("*** Cart�rio EBAC ***\n\n"); //In�cio do menu
		printf("Escolher op��o desejada do menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Deletar nomes\n\n");
		printf("\t4. Sair do programa\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio

		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf ("Obrigado por utilizar o programa.\n");
			return 0;
			break;
			
			default:
			printf("Ops! Essa op��o n�o est� dispon�vel!\n"); //resposta para op��o n�o dispon�vel
			system("pause"); //pausa na tela e espera novo comando
			break;
		}
	
	
	}
}
