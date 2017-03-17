#include <bits/stdc++.h>

using namespace std;

int rec(int arr[], int l, int h){
	if(h == l)
		return 0;
	if(arr[l] == 0)
		return INT_MAX;
	int mn = INT_MAX;
	for(int i = l+1; i <= h && i <= l+arr[l]; i++){
		int steps = rec(arr,i,h);
		if(steps != INT_MAX && steps+1 < mn)
			mn = steps+1;
	}
	return mn;
}
int dp(int arr[], int n){
	int tab[n];
	tab[n-1] = 0;
	vector<int> vec;
	for(int i = n-2; i >= 0; i--){
		if(arr[i] == 0){
			tab[i] = INT_MAX;
			continue;
		}
		int mn = INT_MAX;
		for(int j = i+1; j < n && j <= i+arr[i]; j++){
			int steps = tab[j];
			if(steps != INT_MAX && steps+1 < mn){
				mn = steps+1;
			}
		}
		tab[i] = mn;
	}
	for(int i = 0; i < n; i++)
		cout << tab[i] << " ";
	cout << endl;
	cout << arr[0] << "->";
	for(int i = 0; i < n-1;){
		int mn = INT_MAX;
		int next = -1;
		for(int j = i+1; j <= i+arr[i] && j < n;j++){
			if(tab[j] < mn){
				mn = tab[j];
				next = j;
			}
		}
		if(mn == 0){
			cout << arr[n-1] << endl;
			break;
		}
		cout << arr[next] << "->";
		i = next;
	}
	return tab[0];
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << rec(arr,0,n-1) << endl;
	cout << dp(arr,n) << endl;
	return 0;
}