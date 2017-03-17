#include <bits/stdc++.h>

using namespace std;

int arr[10] = {3,1,7,4,2,6,9,0,5,8};

void swap(int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void sort(int n){
	for(int i = 0; i < n; i++){
		int min_ind = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[min_ind])
				min_ind = j;
		}
		swap(i,min_ind);
	}
}

int main(){
	sort(10);
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}