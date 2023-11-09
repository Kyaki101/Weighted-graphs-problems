#include <bits/stdc++.h>
#include "dijkstra.cpp"
typedef std::vector<int> lista;
typedef std::vector<lista> mat;
typedef std::vector<mat> adjacency;
typedef std::unordered_map<int, mat> map;
typedef std::queue<mat> cola;
map membrain;
adjacency memo(5040);
int covered = 0;
cola align;
int vis[5040] = {0};
int target = 0;
std::unordered_map<long long int, int> record;

int swap(mat & temp, int i, int j, int x, int y) {
    int pre = 0;
    pre = temp[i][j];
    temp[i][j] = temp[x][y];
    temp[x][y] = pre;
    return temp[i][j] + temp[x][y];
}

int moves[8][4] = {
    {0, 1, 0, 2}, 
    {0, 1, 1, 1}, 
    {0, 2, 1, 2}, 
    {1, 1, 1, 2}, 
    {1, 1, 2, 1}, 
    {1, 1, 1, 0}, 
    {1, 0, 2, 0},
    {2, 0, 2, 1}
};


size_t hash_combine(size_t lhs, size_t rhs) {
    return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
}


size_t hasher(const mat & matrix) {
    size_t hash = 0;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            hash = hash_combine(hash, std::hash<int>{}(matrix[i][j]));
        }
    }

    return hash;
}
void printMat(mat & temp){
    for(list i : temp){
        for(int j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

bool cmp(mat & a, mat & b){
    for(int i = 0 ; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(a[i][j] != b[i][j])return false;
        }
    }
    return true;
}


void fillPerm(mat current, int assigned, mat & end){
    mat temp(current);
    list preliminar;
    int cost;
    for(int i = 0; i < 8; i ++){
        cost = swap(temp, moves[i][0], moves[i][1], moves[i][2], moves[i][3]);
        long long int key = static_cast<long long int>(hasher(temp));
        auto mem = membrain.find(key);
        if(mem == membrain.end()){
            align.emplace(temp);
            covered ++;
            if(!target && cmp(temp, end)) target = covered;
            record[key] = covered;
            preliminar.push_back(covered);
            preliminar.push_back(cost);

            memo[assigned].push_back(preliminar);
            preliminar.clear();
            // preliminar.push_back(assigned);
            // preliminar.push_back(cost);
            // memo[covered].push_back(preliminar);
            // preliminar.clear();
        }
        else{
            preliminar.push_back(record[key]);
            preliminar.push_back(cost);

            memo[assigned].push_back(preliminar);
            preliminar.clear();
            // preliminar.push_back(assigned);
            // preliminar.push_back(cost);
            // memo[covered].push_back(preliminar);
            // preliminar.clear();
        }
        membrain[key] = temp;
        temp = current;

    }
    align.pop();


}

int main(){
    mat start(3, lista(3, 0));
    std::cin >> start[0][1];
    std::cin >> start[0][2];
    std::cin >> start[1][0];
    std::cin >> start[1][1];
    std::cin >> start[1][2];
    std::cin >> start[2][0];
    std::cin >> start[2][1];
    mat end(3, lista(3, 0));
    std::cin >> end[0][1];
    std::cin >> end[0][2];
    std::cin >> end[1][0];
    std::cin >> end[1][1];
    std::cin >> end[1][2];
    std::cin >> end[2][0];
    std::cin >> end[2][1];
    int counter = 0;
    align.push(start);
    while(!align.empty()){
        fillPerm(align.front(), counter, end);
        counter++;
    }

    // for(mat i: memo){
    //     for(list j : i){
    //         for(int k : j){
    //             std::cout << "(" << k << ")";
    //         }
    //         std::cout << " ";
    //     }
    //     std::cout << "end" << std::endl;
    // }
    std::vector<long long int> memory(5040, (1 << 30));
    memory[0] = 0;
    dijkstra(memo, 0, memory, vis);

    std::cout << memory[target] << '\n';
    // for(int i:memory)std::cout << i << std::endl;
    

    return 0;
}