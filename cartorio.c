#include<stdio.h> //bliblioteca de comunica��o com usuario
#include<stdlib.h> //espa�o de memoria quando trabalha com variaveis
#include<locale.h> // bliblioteca de localiza��o por regi�o
#include<string.h>//blioblioteca da strings



int registro(){
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digita seu cpf:  ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);//aqui estou puxando dados do cpf para a  variavel arquivo � um copia e cola de variaveis
	
	FILE *file;//A fun��o File est� criando um arquivo chamado file
	file=fopen(arquivo,"w");//Aqui ele abre o arquivo file criado e coloca nele o valor que esta na variavel arquivo que sera o cpf
	fprintf(file,cpf);//Aqui ele esta salvando o arquivo
	fclose(file);//aqui ele esta fechando o arquivo
	
	
	file=fopen(arquivo,"a");//abriu o arquivo open e pediu para escrever uma nova coisa
	fprintf(file,","); //abriu e colocou uma virgula
	fclose(file );//colocamos uma virgula para n�o ficar bagun�ado
	
	
	printf("Digite seu nome que ira ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");// aqui esta atualizando
	fprintf(file,nome);//aqui ele esta passando o conteudo da variavel nome para o file
	fclose(file);	
	
	
	file=fopen(arquivo,"a");//abriu o arquivo open e pediu para escrever uma nova coisa
	fprintf(file,","); //abriu e colocou uma virgula
	fclose(file );//colocamos uma virgula para n�o ficar bagun�ado
	
	printf("Digite seu sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");//abrindo o arquivo
	fprintf(file,sobrenome);//salvando o sobrenome no arquivo file
	fclose(file);//fechando o arquivo
	
	printf("digite o  cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,","); //abriu e colocou uma virgula
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //comando para avisar o programa a colocar acento e definindo a linguagem,tive que colocar aqui porque ele tem que estar dentro de cada fun��o  que for usar um printf
	
	char cpf[40];//crio um nova variavel de cpf
	char conteudo[200];//crio uma variavel de conteudo para colocar o cpf nele
	
	printf("Digite o cpf a ser : ");//pediu ao usuario o cpf
	scanf("%s",cpf);//leu o cpf
	
	FILE *file;//crio um file na pasta
	file=fopen(cpf,"r");//pediu para le o cpf
	
	if(file==NULL){
		printf("N�o foi possivel abrir o arquivo ,n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL){
		
		printf("\nEssas s�o as informa��es do usu�rios: ");
		printf("%s",conteudo);
		printf("\n\n");		
	}
	
		system("pause");
	
}

int deletar(){
		
	char cpf[40];
	printf("Digite o cpf que deseja ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);// este comando vai remover o cpf que foi lido e guardado na variavel.
	FILE *file;
	
	file=fopen(cpf,"r");
	
	
	if(file==NULL){
		printf("O usuario n�o se encontra no sistema.\n");
		system("pause");	
	}
	

	
}

int main(){
	
	int opcao=0;//definindo as variaveis
	int laco=1;
	
	
	for(laco=1;laco=1;){
		
		
		
		setlocale(LC_ALL, "Portuguese"); //comando para avisar o programa a colocar acento e definindo a linguagem
		
				system("cls");
		
			printf("###Cart�rio da Ebac###\n");
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1-Registrar nome\n\n");
			printf("\t2-Consultar nome\n\n");
			printf("\t3-Deletar nome\n\n");
			printf("\t4-Fechar o programa\n\n");
			printf("Op��o:");
			scanf("%d",&opcao);
		
		
			
			switch(opcao){
		
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
				printf("Muito obrigado por usar o nosso sistema\n");
				return 0; // serve para ele quebrar la�o ou se n�o para desligar qualquer tipo  de comando , ele vem do sistema binario ou seja 0 e 1 0 est� Desligado 1 est� ligado.
				break;
					
				default:
					printf("Esta op��o n�o existe!!! \n");
					system("pause");
					system("cls");
					break;
				
				}
	}
	
	

}
