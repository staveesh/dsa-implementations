// Finds max element in an array that first increases, then decreases
#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int lo, int hi){
	if(hi == lo)
		return arr[lo];
	if(hi == lo+1 && arr[lo] >= arr[hi])
		return arr[lo];
	if(hi == lo+1 && arr[lo] <= arr[hi])
		return arr[hi];

	int mid = lo+(hi-lo)/2;
	while(hi-lo > 1){
		if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
			return arr[mid];
		else if(arr[mid] >= arr[mid-1] && arr[mid] <= arr[mid+1]){
			return search(arr,mid,hi);
		}
		else{
			return search(arr,lo,mid);
		}
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << search(arr,0,n-1) << endl;
	return 0;
}