#include <bits/stdc++.h>

using namespace std;

int calc(int arr[], int n){ // Really shitty name for a function xD
	int ans[n][n];
	ans[0][0] = arr[0]*arr[1]*arr[2];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){

		}
	}
}

int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i]; // p[i-1]*p[i]*p[i+1] means 2 matrices of dimensions p[i-1] X p[i] & p[i] X p[i+1]

	return 0;
}