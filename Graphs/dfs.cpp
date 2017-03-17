#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int visited[112345];

void dfs(int source){
	visited[source] = 1;
	for(int i = 0; i < graph[source].size(); i++){
		if(!visited[graph[source][i]]){
			visited[graph[source][i]] = 1;
			dfs(graph[source][i]);
		}
	}
}

int main(){

	int m,n,source;
	cin >> m >> n >> source;
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(source);
	return 0;
}