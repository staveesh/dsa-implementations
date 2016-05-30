#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int visited[112345];
int grey[112345];

bool dfs(int src){

	if(!visited[src]){
		visited[src] = true;
		grey[src] = true;
		for(int i = 0; i < graph[src].size(); i++){
				if(!visited[graph[src][i]] && dfs(graph[src][i])){
					return true;
				}
				else if(grey[graph[src][i]]){
					return true;
				}
		}
	}
	grey[src] = false;

	return false;
}
bool util(int n){
	for(int i = 0; i < n; i++){
		if(dfs(i)){
			return true;
		}
	}
	return false;
}
int main(){
	int m, n;
	cin >> m >> n;
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	cout << util(n) << endl;
	return 0;
}