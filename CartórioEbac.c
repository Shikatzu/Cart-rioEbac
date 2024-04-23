#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

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
	
	strcpy(arquivo, cpf); //responsável por copiar o valor das strings
	
	FILE *file; //criação do arquivo
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
		printf("Não foi possivel abrir o arquivo, não localizado! .\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do user: ");
		printf("%s", conteudo);
		printf("\n\n");	
	} 
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Escolha o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Esse arquivo não existe, coloque um CPF válido.\n");
		system("pause");
	}
	
	printf ("\n\nUsuário deletado.\n\n");
	system ("pause"); 
}

int main ()
{
	int opcao = 0; //definição de variáveis 
	int x=1;
	
	for(x=1;x=1;) //inicio for
	{
		
		system("cls"); //responsável por fazer a limpeza da tela 
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf ("### Cartório da EBAC ###\n\n");
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t1- Registrar nomes\n\n");
		printf ("\t2- Consultar nomes\n\n");
		printf ("\t3- Deletar nomes\n\n");
		printf ("\t4- Sair do sistema\n\n");
		printf ("Opção: ");
		
		scanf("%d", &opcao); //armazenamento e escolha do usuário
		
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
			printf("Essa opção não está disponivel, favor utilizar os números estipulados no menu.\n");
			system("pause");
			break;
				
		} //switch
	} //fim for
}
