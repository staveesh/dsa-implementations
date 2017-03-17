#include <bits/stdc++.h>

using namespace std;

// Naive Approach - O(a)
void isPrime1(int a){
    int count = 0;
    for(int i = 1; i <= a; i++){
      if(a%i == 0)
        count++;
    }
    if(count == 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
}
// An improvement to Naive Approach - O(sqrt(a))
void isPrime2(int a){
    int count = 0;
    for(int i = 1; i*i <= a; i++){
      if(a%i == 0){
        if(i*i == a)
          count++;
        else
          count += 2;
      }
    }
    if(count == 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
}
// Sieve of Eratosthenes - O(NloglogN). Also generates all prime numbers till a.
void isPrime3(int a){
  bool isPrime[a+1];
  for(int i = 1; i <= a; i++)
    isPrime[i] = true;
  isPrime[1] = false;

  for(int i = 1; i*i <= a; i++){
    if(isPrime[i]){
      for(int j = i*i; j <= a; j += i){
        isPrime[j] = false;
      }
    }
  }
  if(isPrime[a])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main(){
  isPrime1(10);
  isPrime1(7);
  isPrime2(10);
  isPrime2(7);
  isPrime3(788);
  isPrime3(101);
  return 0;
}
