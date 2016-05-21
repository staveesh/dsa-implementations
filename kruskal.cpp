#include <bits/stdc++.h>

using namespace std;

int arr[112345],size[112345];

void initialize(int n){
	for(int i = 1;i <= n; i++){
		arr[i] = i;
		size[i] = 1;
	}
}
int root(int a){
	while(arr[a] != a){
		arr[a] = arr[arr[a]];
		a = arr[a];
	}
	return a;
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
	priority_queue<pair<int, pair<int, int> > > q;
	pair<int, pair<int, int> > p;
	int n, m, source,sum=0;
	cin >> n >> m;
    initialize(n);
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		p.first = -w;
		p.second.first = u;
		p.second.second = v;

		q.push(p);
	}
	cin >> source;

	while(!q.empty()){
        int u,v,w;
		p = q.top();
		q.pop();
		w = p.first;
		u = p.second.first;
		v = p.second.second;
		if(!find(u,v)){
			Union(u,v);
			sum -= w;
		}
	}
	cout << sum << endl;
	return 0;
}