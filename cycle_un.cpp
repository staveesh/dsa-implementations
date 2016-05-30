#include <bits/stdc++.h>

using namespace std;

int arr[112345];
int size[112345];
pair<int, int> edges[112345];

int root(int i){
  while(i != arr[i]){
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void Union(int a, int b){
  int ra = root(a);
  int rb = root(b);

  if(size[ra] >= size[rb]){
    arr[rb] = ra;
    size[ra] += size[rb];
  }
  else{
    arr[ra] = rb;
    size[rb] += size[ra];
  }
}

bool find(int a, int b){
  return (root(a) == root(b));
}

int main(){
  int m,n;
  cin >> n >> m;
  pair<int, int> p;

  int x = -1;

  while(m--){
    int u,v;
    cin >> u >> v;
    p.first = u;
    p.second = v;
    edges[++x] = p;
  }
  for(int i = 0; i < n; i++){
    arr[i] = i;
  }

  bool f = false;

  for(int i = 0; i <= x; i++){
    if(find(edges[i].first, edges[i].second)){
      f = true;
      break;
    }
    Union(edges[i].first, edges[i].second);
  }
  cout << f << endl;

  return 0;
}
