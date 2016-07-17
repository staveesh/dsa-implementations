#include <bits/stdc++.h>
#define MAX 100000
#define ll long long
using namespace std;

ll cache[MAX];

ll fib(ll n){
  cache[0] = 1;
  cache[1] = 1;
  for(int i = 2; i <= n; i++){
    cache[i] = cache[i-1]+cache[i-2];
  }
  return cache[n];
}

int main(){
  char c;
  while(1){
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    cin >> c;
    if(c == 'n')
      break;
  }
  return 0;
}
