#include <bits/stdc++.h>
#define V 6

using namespace std;

vector<list<int> >adjList(V);

void addEdge(int u, int v){
    adjList[u].push_back(v);
}

void topologicalSortUTIL(int i, bool visited[], stack<int> &s){
    visited[i] = true;
    list<int>::iterator it;

    for(it = adjList[i].begin(); it != adjList[i].end(); it++){
        if(!visited[*it])
            topologicalSortUTIL(*it, visited, s);
    }
    s.push(i);
}
void topologicalSort(){
    stack <int> s;
    bool visited[V];
    int i;

    for(i = 0; i < V; i++){
        visited[i] = false;
    }

    for(i = 0; i < V; i++){
        if(!visited[i])
            topologicalSortUTIL(i, visited, s);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    addEdge(5,2);
    addEdge(5,0);
    addEdge(4,0);
    addEdge(4,1);
    addEdge(2,3);
    addEdge(3,1);

    cout<<"Topologically Sorted Order :"<<endl;
    topologicalSort();

}
