#include <bits/stdc++.h>

using namespace std;

int rod_cutting(int val[],int l){
	if(l <= 0)
		return 0;
	else{
		int mx = 0;
		for(int i = 0; i < l; i++){
			int len = val[i]+rod_cutting(val,l-i-1);
			if(len > mx)
				mx = len;
		}
		return mx;
	}
}

int dp_rod(int val[], int l){
	int L[l+1];
	L[0] = 0;
	for(int i = 1; i <= l; i++){
		int mx = 0;
		for(int j = 0; j < i; j++){
			int len = val[j] + L[i-j-1];
			if(len > mx)
				mx = len;
		}
		L[i] = mx;
	}
	return L[l];
}
int main(){
	int l;
	cin >> l;
	int val[l];
	for(int i = 0; i < l; i++)
		cin >> val[i];
	cout << rod_cutting(val,l) << endl;
	cout << dp_rod(val,l) << endl;
}