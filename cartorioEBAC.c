#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro() //função responsável por cadastrar usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando info do usuário
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	strcpy(arquivo, cpf); //responsável por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, nome); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, sobrenome); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, cargo); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa na tela e espera novo comando
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando info do usuário
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file==NULL)
	{
		printf("Arquivo não localizado.\n"); //informação de que usuário não foi encontrado
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: "); //coletando info do usuário
		printf("%s", conteudo); //salva valor da variável
		printf("\n\n"); //inserir espaço
	}
	
	system("pause"); //pausa na tela e espera novo comando
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando info do usuário
	scanf("%s", cpf); //%s refere-se a strings, armazenando
	
	remove(cpf); //comando para remover o CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" significa ler
	
	if(file== NULL); //se o número do CPF não existir
	{
		printf("O usuário não se encontra no sistema.\n"); //resposta para o usuário não encontrado
		system("pause"); //pausa na tela e espera novo comando
	}
	
	
	}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("*** Cartório EBAC ***\n\n"); //Início do menu
		printf("Escolher opção desejada do menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Deletar nomes\n\n");
		printf("\t4. Sair do programa\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário

		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf ("Obrigado por utilizar o programa.\n");
			return 0;
			break;
			
			default:
			printf("Ops! Essa opção não está disponível!\n"); //resposta para opção não disponível
			system("pause"); //pausa na tela e espera novo comando
			break;
		}
	
	
	}
}
