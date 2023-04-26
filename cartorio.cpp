#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//Fun��o de respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //cadastra o nome do usu�rio 
	scanf("%s", nome); //refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //salva a informa��o do nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // cadastra o sobrenome do usu�rio
	scanf("%s", sobrenome); //refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);//salva a informa��o do sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo que vai ser cadastrado: ");//salva a informa��o a ser cadastrada
	scanf("%s", cargo);//refere-se a string
	
	file =fopen(arquivo, "a");
	fprintf(file, cargo);//salva d informa��o do cargo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{ 
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");//informa��o a ser consultada
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
	fclose(file);
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL);
	{ 
		printf("Usu�rio n�o encontrado!.\n\n");
		system("pause");
	}
	
}

int main()
    {
	int opcao=0;//definindo vari�veis
	int laco=1;			
	
	for(laco=1;laco=1;)
	
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n");//in�cio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu	
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela 
		
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamda de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}//fim da sele��o
	}
	
}
