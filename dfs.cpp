#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int seen[100];
vector<int> adj[100];

void dfs(int u){
	/// It uses stack concepts.
	seen[u] = 1;

	for(auto x : adj[u]){
		cout << "Node " << u << " --> " << x << endl;
		if(seen[x]) continue;
		dfs(x);
	}
}

void dfsDesc(int start, int v){
	/// graph divided in two or more parts. 
	int count = 0;
	for(int i = 0; i < v; i++){
		if(seen[i]) continue;

		dfs(i);
		count ++;
	}
	cout << "Components: " << count << endl;
}

int main(){
	/// read graph
	int v, e, a, b;
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(seen, 0, sizeof(seen));
	int start = 0;
	//dfs(start);
	dfsDesc(start, v);

	return 0;
}