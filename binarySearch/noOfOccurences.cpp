#include <bits/stdc++.h>

using namespace std;

int arr[10] = {1,2,2,2,2,2,2,2,2,9};

int getLeftPosition(int s, int hi, int lo){
	while(hi - lo > 1){
		int mid = lo + (hi - lo)/2;
		if(arr[mid] <= s)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}
int getRightPosition(int s, int hi, int lo){
	while(hi - lo > 1){
		int mid = lo + (hi - lo)/2;
		if(arr[mid] >= s)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main(){
	int l = getLeftPosition(2, 10, 0);
	int r = getRightPosition(2,9,-1);
	cout << l-r+1 << endl;
	return 0;
}