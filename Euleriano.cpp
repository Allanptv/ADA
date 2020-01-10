#include <iostream>
using namespace std;
int timer;

int* criaVetorVertices(int n){
	int* vetorVertice = new int[n];
	
	for(int i = 0; i < n; i++){
		vetorVertice[i] = 0;	// Cada vertice do grafo é inicializado com cor branca "0";
	}	
	return vetorVertice;
}

int** adjacenciesMatrixCreate(int n){ //N é a quantidade de vertices do grafo
	int i = 0, j = 0;
	int** matrix = new int*[n];
	for(i; i < n; i++){
		matrix[i] = new int[n];
	}

	for(i = 0; i < n; i++){	
		for(j = 0; j < n; j++){	
			matrix[i][j] = 0;
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

void printMatrix(int ** matrix, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

void DFSVISIT(int** matrix, int u, int n, int* vetorVertices, int* aux){
	//char vertice = ' ';
	int* d = new int[10000000];
	int* f = new int[10000000];

	vetorVertices[u] = 1;
	aux[u] = 1;
	//vertice = (char)(u + 97);
	//cout << vertice << ",";
	timer++;
	d[u] = timer;

	for(int j = 0; j < n; j++){
		if((matrix[u][j] != 0) && (vetorVertices[j] == 0)){
			DFSVISIT(matrix, j, n, vetorVertices, aux);
		}
	}
	vetorVertices[u] = 2;
	f[u] = ++timer;
	free(d);
	free(f);
}

int DFS(int** matrix, int n){
	int* vetorVertices = criaVetorVertices(n);	
	int counter = 0;
	timer = 0;

	for(int i = 0; i < n; i++){
		if(vetorVertices[i] == 0){
			int* aux = criaVetorVertices(n);
			DFSVISIT(matrix, i, n, vetorVertices, aux);
			
			counter++;
		}// end if
	}// end for
	return counter;
	free(vetorVertices);
}// end method

void confere(int** matrix, int n, int components){
	bool ehEuleriano = true;
	int* grau = new int[n];
	
	if(components != 1){
		cout << "NAO" << "\n";
	}else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] != 0){
					grau[i]++;
				}
			}
		}
		for(int k = 0; k < n; k++){
			if(grau[k] % 2 != 0){
				ehEuleriano = false;
				k = n;
			}
		}
		if(ehEuleriano == true){
			cout << "SIM" << "\n";
		}else{
			cout << "NAO" << "\n";
		}
	}
}

int main(void){
    int n = 0, counter = 1;
	
    cin >> n;
	int components = 0;

	int e = n-1;
	int** matrix;
        while(n != 0){

            matrix = adjacenciesMatrixCreate(n);
            
            fillMatrix(matrix, n);
            
            //printMatrix(matrix, n);
            
            
            components = DFS(matrix, n);
            //cout << components << "\n";
			confere(matrix, n, components);

           e--;
           cin >> n; 
        }   
    return 0;
}
