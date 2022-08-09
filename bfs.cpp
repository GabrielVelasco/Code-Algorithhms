#include <bits/stdc++.h>

using namespace std;

int seen[100], a, b; /// seen == marca vertices alcancaveis a partir do start.
/// se seen[i] == 1, logo node '1' eh visitavel.
int dist[100]; /// dist[N] == menor dist possível de node 0 até N-1
vector<int> adj[100]; // lista adj

void bfs(int start){
	/// start == onde sera iniciado a busca.
	memset(seen, 0, sizeof(seen));
	memset(dist, -1, sizeof(dist));

	queue<int> qu;
	qu.push(start);
	seen[start] = 1; /// ja foi visitado
	dist[start] = 0;

	while(!qu.empty()){
		int u =  qu.front(); qu.pop();

		/// processa u
		printf("\nVertc %d liga: ", u);
		/// fim process

		for(auto x : adj[u]){
			printf("[%d] ", x);
			if(seen[x])
				continue;

			dist[x] = dist[u]+1;
			qu.push(x);
			seen[x] = 1;
		}
	}
}

int main(){
	/// ler o grafo
	int n, m; // n = V, m = E
	cin >> n >> m;

	/// para cada E teremos 2 V.
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b); /// liga A -> B
		adj[b].push_back(a); /// liga B -> A
	}
	/// termino leitura do grafo

	bfs(1);
	printf("\nDist: %d\n", dist[4]);

	return 0;
}