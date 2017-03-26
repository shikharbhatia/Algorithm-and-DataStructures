#include <bits/stdc++.h>
#define V 3
#define E 3

using namespace std;

vector < list<int> > adjList(V);


struct subset
{
    int parent;
    int rank;
};

void addEdge(int u, int v){
    adjList[u].push_back(v);
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

    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool isCycle(){
     struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );

     for(int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
     }

    list<int>::iterator it;

    for(int i = 0; i < V; i++){
        for(it = adjList[i].begin(); it != adjList[i].end(); it++){
            int x = findSub(subsets, i);
            int y = findSub(subsets, *it);

            if(x == y){
                return 1;
            }
            Union(subsets, x, y);
        }
    }
    return 0;
}
int main(){

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 2);

    if(isCycle()){
        cout<<"yes";
    }
    else
        cout<<"no";

    return 0;
}
