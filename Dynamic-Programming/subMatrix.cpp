#include <bits/stdc++.h>

using namespace std;
#define m 9			// jajn  z m j  zn z zjnzjv12345xz nkvzk  z n{n}
#define n 10
int subMat(int M[m][n]){
	int N[m][n];
	for(int i = 0; i < m; i++)
		N[i][0] = M[i][0];
	for(int j = 0; j < n; j++)
		N[0][j] = M[0][j];
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(M[i][j] == 1)
				N[i][j] = 1+min(N[i-1][j],min(N[i][j-1],N[i-1][j-1]));
			else
				N[i][j] = 0;
		}
	}
	int mx = -1;
	pair<int,int> coord;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(N[i][j] > mx){
				mx = N[i][j];
				coord.first = i;
				coord.second = j;
			}
		}
	}
	for(int i = coord.first; i > coord.first-mx-1; i--){
		for(int j = coord.second; j > coord.second-mx-1; j--){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	return mx;
}

int main(){
	int M[m][n];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> M[i][j];
	cout << subMat(M) << endl;
	return 0;
}