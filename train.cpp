#include <bits/stdc++.h>
typedef std::vector<int> lista;
typedef std::vector<std::vector<lista>> adj;
#define INF 1e9
#define ll long long int
int N;
#define MAX_V 110
typedef std::pair<int, int> ii;
std::vector<ii> G[MAX_V];
std::vector<std::vector<ll>> dist(MAX_V, std::vector<ll>(MAX_V, INF));
//To add an edge use
#define add(a, b, w) G[a].push_back(std::make_pair(w, b))
std::vector<std::vector<bool>> vis(MAX_V, std::vector<bool>(MAX_V, 0));


void dijkstra(int s){
	std::priority_queue<ii, std::vector<ii>, std::greater<ii> > Q;
	Q.push(std::make_pair(0, s)); dist[s][s] = 0;
	while(!Q.empty()){
		ii p = Q.top(); Q.pop();
        vis[s][p.second] = true;
		for(ii i : G[p.second])
			if(dist[s][p.second] + i.first < dist[s][i.second]){
				dist[s][i.second] = dist[s][p.second] + i.first;
                if(!vis[s][i.second]){Q.push(std::make_pair(dist[s][i.second], i.second));}
                }
	}
}

int main(){
    int nodes, edges, qs;
    std::cin >> nodes >> edges >> qs;
    int a, b, w;
    lista prel;
    adj graph(nodes);

    for(int i = 0; i < edges; i ++){
        std::cin >> a >> b >> w;
        a--;
        b--;
        add(a, b, w);
        add(b, a, w);

    }
    for(int i = 0; i < nodes; i ++){
        dijkstra(i);
    }

    for(int i = 0; i < qs; i ++){
        std::cin >> a >> b;
        a--; b--;
        std::cout << dist[a][b] << '\n';
    }

    return 0;
}