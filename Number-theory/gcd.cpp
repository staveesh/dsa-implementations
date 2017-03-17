#include <bits/stdc++.h>

using namespace std;

int x, y, d;
// Naive approach - O(min(a,b))
int GCD1(int a, int b){
  int m = min(a, b);
  for(int i = m; i > 0; i--){
    if(a%i == 0 && b%i == 0){
      return i;
    }
  }
}
// Euclid's Algorithm(Recursive) - O(log(max(a,b)))
int GCD2(int a, int b){
  if(b == 0)
    return a;
  else
    return GCD2(b,a%b);
}
// Extended Euclid's Algorithm(Recursive) - O(log(max(a,b)))
void GCD3(int a, int b){
  if(b == 0){
    d = a;
    x = 1;
    y = 0;
  }
  else{
    GCD3(b, a%b);
    int temp = x;
    x = y;
    y = temp - (a/b)*y;
  }
}
int main(){
  int a,b;
  cin >> a >> b;
  int gcd1 = GCD1(a,b);
  cout << "GCD1 " << gcd1 << endl;
  int gcd2 = GCD2(a, b);
  cout << "GCD2 " << gcd2 << endl;
  GCD3(a, b);
  int gcd3 = d;
  cout << "GCD3 " << gcd3 << endl;
  cout << "Coefficients :" << x << " " << y << endl;
}
