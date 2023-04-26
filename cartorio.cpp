#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro()//Função de responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//responsável por copiar valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //cadastra o nome do usuário 
	scanf("%s", nome); //refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //salva a informação do nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // cadastra o sobrenome do usuário
	scanf("%s", sobrenome); //refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);//salva a informação do sobrenome
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo que vai ser cadastrado: ");//salva a informação a ser cadastrada
	scanf("%s", cargo);//refere-se a string
	
	file =fopen(arquivo, "a");
	fprintf(file, cargo);//salva d informação do cargo
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
	
	printf("Digite o CPF a ser consultado: ");//informação a ser consultada
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL);
	{ 
		printf("Usuário não encontrado!.\n\n");
		system("pause");
	}
	
}

int main()
    {
	int opcao=0;//definindo variáveis
	int laco=1;			
	
	for(laco=1;laco=1;)
	
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n");//início do menu
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("Opção: "); //fim do menu	
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela 
		
		switch(opcao) // início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamda de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
				
		}//fim da seleção
	}
	
}
