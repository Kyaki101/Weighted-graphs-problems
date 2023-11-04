#include <bits/stdc++.h>
#include "dijkstra.cpp"
typedef std::vector<int> lista;
typedef std::vector<std::vector<lista>> adj;


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
        prel.push_back(b);
        prel.push_back(w);
        graph[a].push_back(prel);
        prel.clear();
        prel.push_back(a);
        prel.push_back(w);
        graph[b].push_back(prel);
        prel.clear();

    }
    std::vector<std::vector<long long int>> memo(nodes, std::vector<long long int>(nodes, (1<<30)));
    int vis[nodes][nodes];
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j ++) 
            vis[i][j] = 0;
    for(int i = 0; i < nodes; i ++){
        memo[i][i] = 0;
        dijkstra(graph, i, memo[i], vis[i]);
    }

    for(int i = 0; i < qs; i ++){
        std::cin >> a >> b;
        a--; b--;
        std::cout << memo[a][b] << '\n';
    }

    return 0;
}