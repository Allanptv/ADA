
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int timer; //Variável Global
#define MAXTAM 10000

int* criaVetorVertices(int n){
	int* vet = new int[n];

	for(int i = 0; i < n; i++){
		vet[i] = 999999999.0;
	}
	return vet;
}


/*void pointVectors(int* x, int* y, int n){
	int i;

	for(i = 0; i < n; i++){
		cin >> x[i];
		cin >> y[i];
	}
}

int distanceBetweenTwoPoints(int x1, int x2, int y1, int y2){
	int distance = 0.0, difference1 = 0.0, difference2 = 0.0;
	
	difference1 = x2-x1;
	difference2 = y2-y1;

	distance = sqrt(pow(difference1,2) + pow(difference2,2)); 	
	return distance;
}*/

int** adjacenciesMatrixCreate(int n){
	int i = 0, j = 0, k, l;
	int** matrix = new int*[MAXTAM];
	int* x = new int[n];
	int* y = new int[n];
	
	//pointVectors(x, y, n);
	
	for(i; i< MAXTAM; i++){
		matrix[i] = new int[MAXTAM];
	}
	for(k = 0; k < n; k++){
		for(l = 0; l < n; l++){
			matrix[k][l] = 0;
		}
	}
	return matrix;
}

void fillMatrix(int** matrix, int n){
	int v1;

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			cin >> v1;
			if(v1 != -1){
				matrix[i][j] = v1;
				matrix[j][i] = v1;
			}
		}
	}
}

int posMin(int* q, int n){
	int menor = 99999999;
	int  i, pos = 0 ;
	for(i = 0; i < n; i++){
		if((q[i] < menor) && (q[i] != -1)){
			menor = q[i];
			pos = i;
		
		}
	}	
	return pos;
}

void prim(int** matrix, int n){
	int i, u = 0, counter = 0;
	int tamanhoTeia = 0;
	
	int* q = criaVetorVertices(n);
	q[0] = -1;
	while(counter < n-1){
		for(i = 0; i < n; i++){
			if((u != i) && (q[i] != -1) && (matrix[u][i] != 0)){
				if(matrix[u][i] < q[i]){
					q[i] = matrix[u][i];
				}
			}
		}
		u = posMin(q, n);
	       	tamanhoTeia += q[u]; 
		q[u] = -1;
		counter++;	
	}
	
	cout << tamanhoTeia << endl ;
	free(q);
}

void printMatrix(int** matrix, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

int main(void){
	int n = 0;
	cin >> n;
	int** matrix;
	while(n != 0){
		
		
		matrix = adjacenciesMatrixCreate(n);
		
        fillMatrix(matrix, n);
        
        //printMatrix(matrix, n);	
		
        prim(matrix, n);
		cin >> n;
		for(int i = 0; i < n; i++){
			free(matrix[i]);
		}	
		free(matrix);
	}
	return 0;
}

