#include <bits/stdc++.h>

using namespace std;

vector<int>graph[112345];
int visited[112345];

void bfs(int source){
	queue<int> q;
	visited[source] = 1;
	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < graph[u].size(); i++){
			if(!visited[graph[u][i]]){
				q.push(graph[u][i]);
				visited[graph[u][i]] = 1;
			}
		}
	}
}

int main(){
	int n,m,source;
	cin >> n >> m >> source;
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	bfs(source);
	return 0;
}