#include <bits/stdc++.h>

typedef std::vector<int> list;
typedef std::vector<std::vector<list> > adj;


void dijkstra(adj & graph, int src, std::vector<long long int> & memo, int * vis){
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> cola(
        [&](int a, int b) {
            return memo[a] > memo[b];
        }
    );
    int tot_w = 0;
    int temp;
    int size;
    
    cola.push(src);
    while(!cola.empty()){
        temp = cola.top();
        tot_w = memo[temp];
        vis[temp] = 1;
        size = graph[temp].size();
        for(list i : graph[temp]){
            if(memo[i[0]] > tot_w + i[1])memo[i[0]] = tot_w + i[1];
            if(!vis[i[0]]){cola.push(i[0]); vis[i[0]] = 1;}
        }
        cola.pop();
    }
}

// int main(){
//     int v, e;
//     int src;
//     std::cin >> v >> e;
//     std::cin>>src;
//     list memo(v, (1 << 30));
//     memo[src] = 0;
//     adj graph(v);
//     int a, b, weight;
//     list temp;
//     for(int i = 0; i < e; i ++){
//         std::cin >> a >> b >> weight;
//         temp.push_back(b);
//         temp.push_back(weight);
//         graph[a].push_back(temp);
//         temp.clear();
//         temp.push_back(a);
//         temp.push_back(weight);
//         graph[b].push_back(temp);
//         temp.clear();
//     }
//     int vis[v];
//     for(int i = 0; i < v ; i++)vis[i] = 0;
//     dijkstra(graph, src, memo, vis);

//     for(int i : memo){
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;



//     return 0;
// }