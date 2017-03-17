#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int visited[112345];

bool dfs(int source, int parent){
	visited[source] = 1;
	for(int i = 0; i < graph[source].size(); i++){
		if(!visited[graph[source][i]]){
			return dfs(graph[source][i], source);
		}
		else if(graph[source][i] != parent){
			return true;
		}
	}
	return false;
}

int main(){

	int m,n;
	cin >> m >> n;
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << dfs(0, -1) << endl;
	return 0;
}
