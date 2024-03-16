#include <stdio.h> // biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de memoria
#include <locale.h> // biblioteca de alocacoes de texto por regiao
#include <string.h> // bibliteca de criacao de string

int registro()// fun��o responsavel por cadastrar usuarios no sistema
{
	// Inicio cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis
	
	printf(" Digite o cpf a ser cadastrado:");// coletando informa��es do usu�rio
	scanf("%s",cpf);// %s refere-se a strings
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo (arquivo de texto)
	file = fopen(arquivo,"w"); // nomeia o arquivo de texto com o valor da string
	fprintf(file,cpf); // salva o valor da string dentro do arquivo de texto
	fclose(file); // fecha o arquivo
	
	file=fopen(arquivo,"a");// abre o arquivo e atualiza 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // definindo local da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado! ");
	scanf("%s", cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf(" N�o foi poss�vel abrir o arquivo. N�o localizado!");
		
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuario a ser deletado:");
	scanf("%s",cpf);
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{ 
		printf("O usuario nao se encontra no sistema!\n");
		system("pause");	
	}
}

int main()
	{
	int opcao=0; // definindo variaveis
	int x=1;
	char senhadigitada[]="a";
	int comparacao;
	
	
	printf(" ### Cartorio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite sua senha:");
	scanf("%s",senhadigitada);
	comparacao= strcmp(senhadigitada,"admin");
		
	if(comparacao == 0)
	
	{
	
		for(x=1;x=1;)
		{
			setlocale(LC_ALL,"Portuguese"); // definindo local da linguagem
	
			printf("### Cart�rio da EBAC ### \n\n");// inicio do menu
			printf("Escolha a op��o desejada do menu\n\n");// inicio da selecao
			printf("\t1 - Registrar nomes\n");// opcao de registrar nomes
			printf("\t2 - Consultar nomes\n");// opcao de consultar nomes
			printf("\t3 - Deletar nomes\n\n");// opcao de deletar nomes
			printf("\t4 - Sair do sitema\n\n");// Opcao de sair do sistema
			printf("opcao: ");//fim do menu

			scanf("%d", &opcao);
	
			system("cls");// opcao de limpar a tela depois de digitar
		
			switch(opcao)
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
			printf("Obrigado por utilizar o sistema!");
				return 0;
			break;
				
			default:
			printf("essa opcao nao esta disponivel");
			system("pause");
			break;
			system("cls");
			}
			
		
		}
	
	}
	else
		printf("Senha incorreta!");
	return 0;
		
	
}

