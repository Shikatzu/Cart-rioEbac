#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para realizar o cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar o valor das strings
	
	FILE *file; //cria��o do arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! .\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do user: ");
		printf("%s", conteudo);
		printf("\n\n");	
	} 
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Escolha o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse arquivo n�o existe, coloque um CPF v�lido.\n");
		system("pause");
	}
	
	printf ("\n\nUsu�rio deletado.\n\n");
	system ("pause"); 
}

int main ()
{
	int opcao = 0; //defini��o de vari�veis 
	int x=1;
	
	for(x=1;x=1;) //inicio for
	{
		
		system("cls"); //respons�vel por fazer a limpeza da tela 
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf ("### Cart�rio da EBAC ###\n\n");
		printf ("Escolha a op��o desejada do menu: \n\n");
		printf ("\t1- Registrar nomes\n\n");
		printf ("\t2- Consultar nomes\n\n");
		printf ("\t3- Deletar nomes\n\n");
		printf ("\t4- Sair do sistema\n\n");
		printf ("Op��o: ");
		
		scanf("%d", &opcao); //armazenamento e escolha do usu�rio
		
		system("cls");
		
		switch(opcao) //switch
		{
			case 1:
			registro();
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
			printf("Essa op��o n�o est� disponivel, favor utilizar os n�meros estipulados no menu.\n");
			system("pause");
			break;
				
		} //switch
	} //fim for
}
