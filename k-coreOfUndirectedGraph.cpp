#include <bits/stdc++.h>
#define V 9

using namespace std;

vector<list<int> > adjList(V);

void addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

bool DFS(int v, vector<bool>&visited, vector<int>&vdegree, int k){
    visited[v] = true;

    list<int>::iterator it;

    for(it = adjList[v].begin(); it != adjList[v].end(); it++){
        if(vdegree[v] < k){
            vdegree[*it]--;
        }
        if(!visited[*it]){
            if(DFS(*it, visited, vdegree, k))
                vdegree[v]--;
        }
    }
    return (vdegree[v] < k);
}
void printKcores(int k){
    vector<bool>visited(V,false);
    vector<int>vdegree(V);
    int startidx;
    int mindeg = INT_MAX;
    int i;

    for(i = 0; i < V; i++){
        vdegree[i] = adjList[i].size();
        if(vdegree[i] < mindeg){
            startidx = i;
            mindeg = vdegree[i];
        }
    }
    DFS(startidx, visited, vdegree, k);

    for(i = 0; i < V; i++){
        if(!visited[i])
            DFS(i, visited, vdegree, k);
    }

    for(i = 0; i < V; i++){
        if(vdegree[i] >= k){
            cout<<i<<" ";
            list<int>::iterator it;
            for(it = adjList[i].begin(); it != adjList[i].end(); it++){
                if(vdegree[*it] >= k){
                    cout<<"->"<<*it;
                }
            }
            cout<<endl;
        }
    }
}
int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(3, 4);
    addEdge(3, 6);
    addEdge(3, 7);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(5, 6);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(6, 8);

    int k = 3;

    printKcores(k);

    return 0;
}
