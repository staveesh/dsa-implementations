#include <bits/stdc++.h>

using namespace std;

int longestSubseqWithDiffOne(int arr[], int n){
	int *L;
	L = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		L[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(abs(arr[i]-arr[j]) == 1 && L[i] < L[j]+1)
				L[i] = L[j]+1;
		}
	}
	int mx = INT_MIN;
	for(int i = 0; i < n; i++)
		if(L[i] > mx)
			mx = L[i];
	free(L);
	return mx;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << longestSubseqWithDiffOne(arr,n) << endl;
	return 0;
}