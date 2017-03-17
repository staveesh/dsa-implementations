#include <bits/stdc++.h>

using namespace std;
//Given two strings str1 and str2 and below operations that can performed on str1. 
//Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
//Insert
//Remove
//Replace
int func(string s1, string s2, int m, int n){
	int L[m+1][n+1];
	for(int i = 0; i < m+1; i++){
		for(int j = 0; j < n+1; j++){
			if(i == 0)
				L[i][j] = j;
			else if(j == 0)
				L[i][j] = i;
			else if(s1[i-1] == s2[j-1])
				L[i][j] = L[i-1][j-1];
			else
				L[i][j] = 1+min(min(L[i][j-1],
								  L[i-1][j-1]),
								  L[i-1][j]);
		}
	}
	return L[m][n];
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	cout << func(s1,s2,s1.length(),s2.length()) << endl;
}