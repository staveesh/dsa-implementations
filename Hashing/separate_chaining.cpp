#include <bits/stdc++.h>

using namespace std;

int hashTabeSize = 26;
vector<int> hashTable[hashTabeSize];

int hashFunction(string key){
  return (key - 'a');
}

void insert(string value){
    int key = hashFunction(value);
    hashTable[key].push_back(value);
}

int search(string value){
  int key = hashFunction(value);

  for(int i = 0; i < hashTable[key].size(); i++){
    if(hashTable[key][i] == value){
      return i;
    }
  }
  return -1;
}

int main(){
  // Your code here.
  return 0;
}
