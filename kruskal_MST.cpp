#include <bits/stdc++.h>
#define V 4

using namespace std;

vector< list< pair< int, int> > > adjList(V);

struct subset{
    int parent;
    int rank;
};
void addEdge(int u, int v, int wt){
    adjList[u].push_back(make_pair(v, wt));
}
int findSub(struct subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = findSub(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y){
    int xroot = findSub(subsets, x);
    int yroot = findSub(subsets, y);

    if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(){
    struct subset *subsets = (struct subset*)malloc(V*sizeof(struct subset));
    bool visited[V];
    int edges[100];

    for(int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
   // yahan sort karna hai weight of edge ke basis pe.... function likho idhar....jo jo likha hai use comment kar dena


}
int main(){
    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);

    addEdge(1, 0, 10);
    addEdge(1, 3, 15);

    addEdge(3, 0, 5);
    addEdge(3, 2, 4);
    addEdge(3, 1, 15);

    addEdge(2, 0, 6);
    addEdge(2, 3, 4);

    kruskalMST();
}
