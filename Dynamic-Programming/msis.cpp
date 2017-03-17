#include <bits/stdc++.h>

using namespace std;

// Bottom-up approach -> calculates all values
vector<int> subs[112345];
int top_down(int n,int arr[]){
	int *L;
	L = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		L[i] = arr[i];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && L[i] < L[j]+arr[i]){
				L[i] = L[j]+arr[i];
			}
		}
	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		if(L[i] > mx)
			mx = L[i];
	}
	free(L);
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