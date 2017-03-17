#include <bits/stdc++.h>

using namespace std;

// Bottom-up approach -> calculates all values
int top_down(int n,int arr[]){
	int *L;
	L = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		L[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
				if(arr[j] < arr[i] && L[i] < L[j] + 1){
					L[i] = L[j]+1;
				}
		}
	}
	int *M;
	M = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		M[i] = 1;
	for(int i = n-2; i >= 0; i--){
		for(int j = n-1; j > i; j--){
				if(arr[j] < arr[i] && M[i] < M[j] + 1){
					M[i] = M[j]+1;
				}
		}
	}
	int mx = L[0]+M[0]-1;
	for(int i = 0; i < n; i++){
		if(L[i]+M[i]-1 > mx)
			mx = L[i]+M[i]-1;
	}
	free(L);
	free(M);
	return mx;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << top_down(n,arr) << endl;
	return 0;
}