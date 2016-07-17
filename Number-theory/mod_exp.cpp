#include <bits/stdc++.h>

// To calculate a^b % c
using namespace std;

#define ll long long

// Naive approach - O(b)
ll exp1(ll a, ll b, ll c){
  ll ans = 1;
  for(int i = 0; i < b; i++){
    ans *= a;
    ans %= c;
  }
  return ans;
}
// O(log b) Approach

ll exp2(ll a, ll b, ll c){
  ll ans = 1;
  while(b != 0){
    if(b == 1){
      ans *= a;
      ans %= c;
    }
    a = a*a;
    a %= c;
    b /= 2;
  }
  return ans;
}
int main(){
  ll a1 = exp1(5,59,19);
  ll a2 = exp2(5,59,19);

  cout << a1 << endl;
  cout << a2 << endl;
  return 0;
}
