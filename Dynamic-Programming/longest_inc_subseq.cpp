#include <bits/stdc++.h>

using namespace std;
// Top-down approach -> need not compute all values
int rec(int i,int arr[]){
	int *L;
	L = (int*)malloc(sizeof(int)*i);
	if(i == 0){
		L[i] = 1;
		return L[i];
	}
	int mx = -1,ind = -1;
	for(int j = 0; j < i;j++){
		if(arr[j] > mx && arr[j] < arr[i]){
			mx = arr[j];
			ind = j;
		}
	}
	if(ind == -1)
		L[i] = 1;
	else
		L[i] = rec(ind,arr) + 1;
	return L[i];
}
// Bottom-up approach -> calculates all values
vector<int> subs[112345];
int top_down(int n,int arr[]){
	int *L;
	L = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		L[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && L[i] < L[j]+1){
				L[i] = L[j]+1;
				subs[i].push_back(arr[j]);
			}
		}
		subs[i].push_back(arr[i]);
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
	int n,x;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	//cout << top_down(n,arr) << endl;
	int m = -1;
	for(int i = 0; i < n; i++){
	 x=rec(i,arr);
		if(x > m){
			m = x;
		}
		
	}
	cout<<m<<endl;
	/*for(int i = 0; i < subs[n-1].size();i++)
		cout << subs[n-1][i] << " ";
	cout << endl;
	return 0;*/
}
