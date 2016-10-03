#include <bits/stdc++.h>

using namespace std;

int arr[9] = {1,2,3,4,5,6,7,8,9};

int search(int s, int hi, int lo){
	while(hi - lo > 1){
		int mid = lo + (hi-lo)/2;
		if(arr[mid] <= s)
			lo = mid;
		else
			hi = mid;
	}
	if(arr[lo] == s)
		return lo;
	else
		return -1;
}

int main(){
	int toSearchFor;
	cin >> toSearchFor;
	int result = search(toSearchFor,8,0);
	if(result != -1)
		cout << result << endl
;	else
		cout << "Not found" << endl;
	return 0;
}