/*Given a list of N coins, their values (V1, V2, … , VN), and the total sum S.
Find the minimum number of coins the sum of which is S (we can use as many coins of one type as we want),
or report that it’s not possible to select coins in such a way that they sum up to S.*/
#include <bits/stdc++.h>

#define INF 100000
#define MAX_SIZE 1000
#define ll long long

using namespace std;

int main(){
  ll mn[MAX_SIZE];
  int n;
  cin >> n;
  ll v[n];
  for(int i = 0; i < n; i++)
    cin >> v[i];
  int s;
  cin >> s;
  for(int i = 1; i <= s; i++)
    mn[i] = INF;
  for(int i = 1; i <= s; i++){
    for(int j = 0; j <= n-1; j++){
      if(v[j] <= i && mn[i-v[j]]+1 < mn[i])
        mn[i] = mn[i-v[j]]+1;
    }
  }
  cout << mn[s] << endl;
  return 0;
}
