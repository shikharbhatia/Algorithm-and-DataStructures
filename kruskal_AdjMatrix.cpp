#include <bits/stdc++.h>
#define V 4

using namespace std;

struct edge{
    int u;
    int v;
    int wt;
};
struct subset{
    int parent;
    int rank;
};

int findSub(struct subset subsets[], int i){
    if(subsets[i].parent != i)
        subsets[i].parent = findSub(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y){
    int xroot = findSub(subsets, x);
    int yroot = findSub(subsets, y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool mycompare(struct edge e1, struct edge e2){
    return (e1.wt < e2.wt);
}

void kruskalMST(int adjMatrix[][V]){
    int i, j;
    int k = 0;
    struct edge result[V];
    struct subset *subsets = (struct subset *)malloc(V*sizeof(struct subset));
    struct edge *edges = (struct edge *)malloc(10*sizeof(struct edge));
    for(i = 0; i < V; i++){
        for(j = i+1; j < V; j++){
            if(adjMatrix[i][j] > 0){
                edges[k].u = i;
                edges[k].v = j;
                edges[k].wt = adjMatrix[i][j];
                k++;
            }
        }
    }
    sort(edges, edges+k, mycompare);

    for(int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int c = 0;

    while(e < V-1 && c < k){

        int x = findSub(subsets, edges[c].u);
        int y = findSub(subsets, edges[c].v);

        if(x != y){
            result[e++] = edges[c];
            Union(subsets, x, y);
        }
        c++;
    }
    for(int l = 0; l < e; l++){
        cout<<result[l].u<<"--"<<result[l].v<<"("<<result[l].wt<<")";
        cout<<endl;
    }
}
int main(){
    int adjMatrix[][V] = {{-1, 10, 6, 5},
                          {10, -1, -1, 15},
                          {6, -1, -1, 4},
                          {5, 15, 4, -1}};

    kruskalMST(adjMatrix);
}
