#include <bits/stdc++.h>
#define V 6

using namespace std;

vector < list< pair<int,int> > > adjList(V);

void addEdge(int u, int v, int weight){
    adjList[u].push_back(make_pair(v, weight));
}
int getDist(int u, int v){
    list< pair<int,int> >::iterator it;

    for(it = adjList[u].begin(); it != adjList[u].end(); it++){
        if((*it).first == v)
            break;
    }
    return (*it).second;
}
void topological(int i, bool visited[], stack <int> &s){
    visited[i] = true;

    list< pair<int,int> >::iterator it;

    for(it = adjList[i].begin(); it != adjList[i].end(); it++){
        if(!visited[(*it).first])
            topological((*it).first, visited, s);
    }
    s.push(i);
}
void longestPath(int src){
    bool visited[V];
    stack<int> s;
    int i;
    int dist[V];

    for(i = 0; i < V; i++)
        visited[i] = false;

    for(i = 0; i < V; i++)
        if(!visited[i])
            topological(i, visited, s);

    for(i = 0; i < V; i++){
        dist[i] = INT_MIN;
    }
    dist[src] = 0;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        list< pair<int,int> >::iterator jt;

        if(dist[u] != INT_MIN){
            for(jt = adjList[u].begin(); jt != adjList[u].end(); jt++){
                if(dist[(*jt).first] < dist[u] + getDist(u, (*jt).first))
                    dist[(*jt).first] = dist[u] + getDist(u, (*jt).first);
            }
        }
    }
    for(i = 0; i < V; i++){
        if(dist[i] == INT_MIN){
            cout<<"INF"<<" ";
        }
        else
            cout<<dist[i]<<" ";
    }
}
int main(){
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 6);
    addEdge(1, 2, 2);
    addEdge(2, 4, 4);
    addEdge(2, 5, 2);
    addEdge(2, 3, 7);
    addEdge(3, 5, 1);
    addEdge(3, 4, -1);
    addEdge(4, 5, -2);

    int s = 1;

    longestPath(s);

    return 0;
}
