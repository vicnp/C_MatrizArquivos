#include <stdio.h>
#include <stdlib.h>

void get_data(int *m, int *n, int *p, int *q){
	printf("\n Informe a quantidade de linhas da matriz A : ");
	scanf("%d",m);
	printf("\n Informe a quantidade de colunas da matriz A : ");
	scanf("%d",n);
	printf("\n Informe a quntidade de linhas da matriz B : ");
	scanf("%d",p);
	printf("\n Informe a quantidade de colunas da matriz B : ");
	scanf("%d",q);
}

void fill_matriz(int q, int m,int n, int p, int matrizA[][50], int matrizB[][50]){
	int i, j;
	if(n==p){
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz A: ", i+1, 167, j+1, 167);
			scanf("%d", &matrizA[i][j]);
		}	
		printf("\n");
}

for(i=0; i<p; i++){
	for(j=0; j<q; j++){
		printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da 2%c Matriz B: ", i+1, 167, j+1, 167, 167);
		scanf("%d", &matrizB[i][j]);
	}
		printf("\n");
	}

}else{
	printf("\n\n Nao ha com multiplicar as matrizes dadas ");
}
}

void calcula(int m, int q, int p, int *Aux, int matrizA[][50],int matrizB[][50], int matrizC[][50]){
	int i,j,X;
	for(i=0; i<m; i++){
	for(j=0; j<q; j++){
		matrizC[i][j]=0;
		for(X=0; X<p; X++){
			*Aux += matrizA[i][X] * matrizB[X][j];
		}
		matrizC[i][j]=*Aux;
		*Aux=0;
	}

}
}

void imprime(int m, int n, int p, int q, int matrizA[][50], int matrizB[][50], int matrizC[][50]){
	int i, j;
	printf("\n\n");
	printf("***** Matriz \"A\" Gerada *****\n\n");

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d\t", matrizA[i][j]);
			}
				printf("\n\n");
			}

	printf("***** Matriz \"B\" Gerada *****\n\n");

	for(i=0; i<p; i++){
		for(j=0; j<q; j++){
			printf("%d\t", matrizB[i][j]);
		}
			printf("\n\n");
}
	printf(" Matriz Multiplicada\n\n");

	for(i=0; i<m; i++){
		for(j=0; j<q; j++){
			printf("%d\t", matrizC[i][j]);
		}
			printf("\n\n");
		}
		printf("\n\n");
}

void escreve_arquivo(int m, int n, int p, int q, int matrizA[][50], int matrizB[][50], int matrizC[][50]){
	int i,j,op;
	
	printf("Desaja salvar em um arquivo .txt ? \n 1 para SIM e 0 para NAO \n >>>> ");
	scanf("%d", &op);
	
if(op == 1){
	FILE *arq;
	arq = fopen("matriz_produto.txt","w");
	if(arq == NULL){
		printf("\n \n Houve um problema ao tentar criar o arquivo, tente novamente !\n \n ");
		exit(m);
	}
	fprintf(arq,"MATRIZ 1\n\n");
	for (i=0; i<m; i++) {
    	for(j=0; j<n; j++) {
        	fprintf(arq,"| %d ",matrizA[i][j]);
    	}
    	fprintf(arq,"|\n");
	}	
	fprintf(arq,"\n\n");
	fprintf(arq,"MATRIZ 2\n\n");
	for (i=0; i<m; i++) {
    	for(j=0; j<n; j++) {
        	fprintf(arq,"| %d ",matrizB[i][j]);
    	}
    	fprintf(arq,"|\n");
	}	
	fprintf(arq,"\n\n");
	fprintf(arq,"MATRIZ RESULTADO\n\n");
	for (i=0; i<m; i++) {
    	for(j=0; j<n; j++) {
        	fprintf(arq,"| %d ",matrizC[i][j]);
    	}
    	fprintf(arq,"|\n");
	}	
	
	fclose(arq);
	}
}

void retry(){
	int op;
	printf("Desaja fazer um novo calculo ? \n 1 para SIM e 0 para NAO \n >>>> ");
	scanf("%d", &op);
	if(op == 1){
		system("cls");
		main();
	}else{
		exit(0);
	}
}

int main(){
	int i,j, m, n, p, q,X,Aux=0;
	get_data(&m,&n,&p,&q);
	int matrizA[50][50],matrizB[50][50],matrizC[50][50];
	fill_matriz(q,m,n,p,matrizA, matrizB);
	calcula(m,q,p,&Aux,matrizA,matrizB,matrizC);
	imprime(m,n,p,q,matrizA,matrizB,matrizC);
	escreve_arquivo(m,n,p,q,matrizA,matrizB,matrizC);
	retry();
	system("pause");
}
