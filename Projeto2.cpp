#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int E, V;
vector<int> parent;

struct Edge{
    int u, v, w;
    bool operator< (const Edge &next) const{
        return w > next.w;
    }
};

void make_set(){
    for (int i = 0; i < E; i++){
        parent[i] = i;
    }
}

int find_set(int x){
    if (x == parent[x]){ 
      return x;
    }
    return parent[x] = find_set(parent[x]);
}

void make_union(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x == y){
      return;
    }
    parent[x] = y;
}

int main(){
    vector<Edge> edges;
    int u, v, w;
    int weight = 0;
    scanf("%d %d", &E, &V);
    for (int i = 0; i < V; i++){
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());
    parent.resize(E+1);
    make_set();

    for (int i = 0; i < V; i++){
        int a = edges[i].u, b = edges[i].v;
        if (find_set(a) != find_set(b)){
            make_union(a, b);
            weight += edges[i].w;
        }
    }

    printf("%d\n", weight);
    return 0;
}