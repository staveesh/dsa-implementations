#include <bits/stdc++.h>

using namespace std;

int partition(int arr[],int n){
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	if(sum %2 != 0)
		return false;
	bool part[sum/2+1][n+1];
	for(int i = 0; i <= n; i++){
		part[0][i] = true;
	}
	for(int i = 1; i <= sum/2;i++)
		part[i][0] = false;
	for(int i = 1; i <= sum/2; i++){
		for(int j = 1; j <= n; j++){
			part[i][j] = part[i][j-1];
			if(i >= arr[j]){
				part[i][j] = part[i][j] || part[i-arr[j-1]][j-1];
			}
		}
	}
	
     for (int i = 0; i <= sum/2; i++)  
     {
       for (int j = 0; j <= n; j++)  
          printf ("%4d", part[i][j]);
       printf("\n");
     }
	return part[sum/2][n];
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << partition(arr,n);
	return 0;
}