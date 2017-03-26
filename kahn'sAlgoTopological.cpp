#include <bits/stdc++.h>
#define V 6

using namespace std;

vector<list<int> >adj(V);

void addEdge(int u, int v){
    adj[u].push_back(v);
}
void topological(){
    vector<int>indegree(V, 0);

    list<int>::iterator it;

    for(int i = 0; i < V; i++){
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            indegree[*it]++;
        }
    }
    queue<int>q;

    for(int i = 0; i < V; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;    //visited nodes count
    vector<int>order;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(it = adj[u].begin(); it != adj[u].end(); it++){
            if(--indegree[*it] == 0){
                q.push(*it);
            }
        }
        cnt++;
    }

    if(cnt != V){
        cout<<"no ordering";
        return;
    }

    int k = 0;

    for(int i = 0; i < order.size(); i++){
        cout<<order[i]<<" ";
    }
}
int main(){
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topological();

    return 0;
}
