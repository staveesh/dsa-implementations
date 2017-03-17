#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int clr[112345];
queue<int> q;

bool bipartite(int source){
  clr[source] = 1;
  q.push(source);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < graph[u].size(); i++){
      if(clr[graph[u][i]] == -1){
        clr[graph[u][i]] = 1 - clr[u];
        q.push(graph[u][i]);
      }
      else if(clr[graph[u][i]] == clr[u]){
        return false;
      }
    }
  }
  return true;
}

int main(){

  int m, n;
  cin >> m >> n;
  while(m--){
    int u,v;
    cin >> u >> v;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  fill(clr, clr+n, -1);
  cout << bipartite(0) << endl;
  return 0;
}
