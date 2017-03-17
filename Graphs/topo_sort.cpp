#include <bits/stdc++.h>

using namespace std;

vector<int> graph[112345];
int visited[112345];
stack<int> st;

void dfs(int source){
	visited[source] = 1;
	for(int i = 0; i < graph[source].size(); i++){
		if(!visited[graph[source][i]]){
			visited[graph[source][i]] = 1;
			dfs(graph[source][i]);
		}
	}
	st.push(source);
}

int main(){

	int m,n;
	cin >> m >> n;
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])
			dfs(i);
	}
	while(!st.empty()){
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}
