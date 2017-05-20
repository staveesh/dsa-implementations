#include <bits/stdc++.h>

using namespace std;

int getSum(int BITree[], int index){
	index += 1;
	int sum = 0;
	while(index > 0){
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}
// Add val to index i
int update(int BITree[], int n, int val, int index){
	index += 1;
	while(index > 0 && index <= n){
		BITree[index] += val;
		index += index & (-index);
	}
}

int* construct(int arr[], int n){
	int* BITree = new int[n+1];
	for(int i = 0; i < n+1; i++)
		BITree[i] = 0;

	for(int i = 0; i < n; i++){
		update(BITree,n,arr[i],i);
	}
	return BITree;
}

int main(){
	int arr[16] = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
	int* BITree = construct(arr,16);
	update(BITree,16,-4,0);
	cout << getSum(BITree,15) << endl;
}