#include <bits/stdc++.h>

using namespace std;

int eggdrop(int n,int k){   // gives worst case estimate for no of trials
	if(k == 1 || k == 0)
		return k;
	if(n == 1)
		return k;
	int mn = INT_MAX;
	for(int i = 1; i <= k; i++){
		int ans = max(eggdrop(n-1,i-1),eggdrop(n,k-i));
		if(ans < mn){
			mn = ans;
		}
	}
	return mn+1;
}

int main(){
	int n,k;
	cin >> n >> k; // no of eggs and floors
	int drops = eggdrop(n,k);
	cout <<  drops << endl;
	for(int i = 1; i <= k;i++){
		if(eggdrop(n-1,i) == drops-1){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}