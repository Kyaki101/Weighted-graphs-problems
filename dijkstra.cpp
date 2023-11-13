#include <bits/stdc++.h>
#define INF 1e9
#define ll long long int
int N;
#define MAX_V 250001
typedef std::pair<int, int> ii;
std::vector<ii> G[MAX_V];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))


ll dijkstra(int s, int t, std::vector<ii> & graph){
	std::priority_queue<ii, std::vector<ii>, std::greater<ii> > Q;
	std::vector<ll> dist(N, INF); std::vector<int> dad(N, -1);
	Q.push(std::make_pair(0, s)); dist[s] = 0;
	while(!Q.empty()){
		ii p = Q.top(); Q.pop();
		if(p.second == t) break;
		for(ii i : G[p.second])
			if(dist[p.second] + i.first < dist[i.second]){
				dist[i.second] = dist[p.second] + i.first;
				dad[i.second] = p.second;
				Q.push(std::make_pair(dist[i.second], i.second));	}
	}
	return dist[t];
    }	