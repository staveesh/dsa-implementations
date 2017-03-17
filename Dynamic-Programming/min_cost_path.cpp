#include <bits/stdc++.h>
//You can only traverse down, right and diagonally 
//lower cells from a given cell, i.e., from a given 
//cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed.
using namespace std;
#define M 3
#define N 3
int cost(int arr[M][N], int a, int b){
	int C[M][N];
	C[0][0] = arr[0][0];
	for(int i = 1; i <= a; i++)
		C[i][0] = C[i-1][0] + arr[i][0];
	for(int j = 1; j <= b; j++)
		C[0][j] = C[0][j-1] + arr[0][j];
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
				C[i][j] = min(C[i][j-1],min(C[i-1][j],C[i-1][j-1]))+arr[i][j];
		}
	}
	return C[a][b];
}

int main(){
	int mat[M][N] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	int a,b;
	cin >> a >> b;
	cout << cost(mat,a,b) << endl;
	return 0;
}