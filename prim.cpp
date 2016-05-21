#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, pair<int, int> > > q;  

vector<pair<int, pair<int, int> > > graph[112345] ;      // Adjacency list that stores edges and their weights.

int visited[112345];

int main() {
    pair<int, pair<int, int> > p,p1;
    
    int n,m,u,v,w,s,sum=0;
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        p.first = -w;
        p.second.first = u;
        p.second.second = v;
        graph[u].push_back(p);
        
        p.second.first = v;
        p.second.second = u;
        graph[v].push_back(p);
    }
    int vertex_count = 0;   // Stores no. of vertices currently in min-heap.
    cin >> s;
    vertex_count++;
    for(int i = 0; i < graph[s].size(); i++){
        q.push(graph[s][i]);
    }
    visited[s] = 1;
    
    while(vertex_count < n){
        p1 = q.top();
        q.pop();
        int current = p1.second.second;
        int weight = p1.first;
        
        if(!visited[current]){
            visited[current] = 1;
            sum -= weight;
            for(int i = 0; i < graph[current].size(); i++){
                if(!visited[graph[current][i].second.second])
                    q.push(graph[current][i]);
            }
            vertex_count++;
        }
    }
    cout << sum << endl;
    return 0;
}
