#include <bits/stdc++.h>

using namespace std;

int arr[9] = {1,2,3,4,5,7,8,9,10};

// Returns the smallest number >= the given key.
int search(int s, int hi, int lo){
	while(hi - lo > 1){
		int mid = lo + (hi-lo)/2;
		if(arr[mid] >= s)
			hi = mid;
		else
			lo = mid;
	}
	return arr[hi];
}
int ceiling(int s, int size){
	if(s < arr[0])
		return -1;
	else
		return search(s,size, 0);
}
int main(){
	int toSearchFor;
	cin >> toSearchFor;
	int result = ceiling(toSearchFor,9);
	cout << result << endl;
	return 0;
}