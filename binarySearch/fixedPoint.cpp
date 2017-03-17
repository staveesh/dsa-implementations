// Returns an element such that arr[ele] = ele
#include <bits/stdc++.h>

using namespace std;

int fixedPoint(int arr[],int lo,int hi){
	
	while(lo <= hi){
		int mid = lo+(hi-lo)/2;
		if(arr[mid] > mid)
			return fixedPoint(arr,lo,mid-1);
		else if(arr[mid] == mid)
			return mid;
		else
			return fixedPoint(arr,mid+1,hi);	
	}
	return -1;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << fixedPoint(arr,0,n);
	return 0;
}