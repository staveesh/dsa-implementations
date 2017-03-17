#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int W, int n){
	if(W == 0 || n == 0)
		return 0;
	if(wt[n-1] > W)
		return knapsack(wt,val,W,n-1);
	else
		return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
}
int dp_knapsack(int wt[], int val[], int W, int n){
	int table[n+1][W+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(wt[i-1] <= W)
				table[i][j] = max(table[i-1][j-wt[i-1]]+val[i-1],table[i-1][j]);
			else
				table[i][j] = table[i-1][j];
		}
	}
	return table[n][W];
}
int main(){
	int n;
	cin >> n;
	int val[n];
	int wt[n];
	for(int i = 0; i < n; i++)
		cin >> val[i];
	for(int i = 0; i < n; i++)
		cin >> wt[i];
	int W;
	cin >> W;
	cout << knapsack(wt,val,W,n) << endl;
	cout << dp_knapsack(wt,val,W,n) << endl;
	return 0;
}