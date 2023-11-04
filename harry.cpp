#include <bits/stdc++.h>
typedef std::vector<int> list;
typedef std::vector<std::vector<list>> adj;
bool visited[100000] = {0};

long long int prim(adj & graph){
    std::priority_queue<list, std::vector<list>, std::function<bool(list &, list &)>> cola(
        [](list  a, list  b){
            return a[1] > b[1];
        }
    );
    list holder = {0, 0};
    cola.push(holder);
    long long int counter = 0;
    int size = graph.size();
    int cont = 0;
    int node;
    while(!cola.empty() && size > cont){
        holder = cola.top();
        node = holder[0];
        cola.pop();
        if(!visited[node]){
            cont ++;
            counter += holder[1];
            visited[node] = true;
            for(list i : graph[node]){
                if(!visited[i[0]]){
                    cola.push(i);
                }
            }
        }
    }
    return counter;

}


int main(){
    int nodes, edges;
    std::cin >> nodes >> edges;
    adj graph(nodes);
    int i, j, w;
    list prelim;
    for(int e = 0; e < edges; e ++){
        std::cin >> i >> j >> w;
        i --;
        j --;
        prelim.push_back(j);
        prelim.push_back(w);
        graph[i].push_back(prelim);
        prelim.clear();
    }

    std::cout << prim(graph) << std::endl;

    return 0;
}