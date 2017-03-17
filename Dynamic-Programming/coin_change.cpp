#include <bits/stdc++.h>

using namespace std;

int cnt(int m, int n, int arr[]){
	int num[n+1][m];
	int x,y;
	for(int i = 0; i < m; i++)
		num[0][i] = 1;

	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < m; j++){
			x = (i-arr[j] >= 0)? num[i-arr[j]][j] : 0;
			y = (j >= 1)? num[i][j-1] : 0;
			num[i][j] = x+y;
		}
		
	}
	return num[n][m-1];
}

int main(){
	int arr[] = {1,2,3};
	cout << cnt(3,4,arr) << endl;
	return 0;
}