#include <bits/stdc++.h>

using namespace std;

int arr[9] = {1,2,3,4,5,6,7,8,9};

int search(int s, int lo, int hi){
	if(hi >= lo){
		int mid = lo + (hi-lo)/2;
		if(arr[mid]== s)
			return mid;
		if(arr[mid] > s)
			return search(s,lo,mid-1);
		if(arr[mid] < s)
			return search(s,mid+1,hi);
	}
	return -1;
}

int main(){
	int toSearchFor;
	cin >> toSearchFor;
	int ans = search(toSearchFor, 0, 8);
	if(ans >= 0)
		cout << ans << endl;
	else
		cout << "Not found" << endl;
}