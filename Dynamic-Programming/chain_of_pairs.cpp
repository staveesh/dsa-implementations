#include <iostream>
#include <stdlib.h>
using namespace std;
struct pr{
	int x;
	int y;
};
int chain(struct pr arr[], int n){
	int *L;
	L = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		L[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j].y < arr[i].x && L[i] < L[j]+1)
				L[i] = L[j]+1; 
		}
	}
	int mx = 0;
	for(int i = 0; i < n; i++)
		if(L[i] > mx)
			mx = L[i];
	return mx;
}

int main(){
	int n;
	cin >> n;
	struct pr arr[n];
	for(int i = 0; i < n; i++){
		int ele1,ele2;
		cin >> ele1 >> ele2;
		arr[i].x = ele1;
		arr[i].y = ele2;
	}
	cout << chain(arr,n) << endl;
}