#include <bits/stdc++.h>
#define V 6

using namespace std;

vector<list<int> >adj(V);
vector<int>indegree(V, 0);

void addEdge(int u, int v){
    adj[u].push_back(v);
    indegree[v]++;
}

void alltopologicalutil(vector<bool>visited, vector<int>&res){
    bool flag = 0;

    for(int i = 0; i < V; i++){
        if(indegree[i] == 0 && !visited[i]){
            list<int>::iterator j;

            for(j = adj[i].begin(); j != adj[i].end(); j++){
                indegree[*j]--;
            }

            visited[i] = true;
            res.push_back(i);
            alltopologicalutil(visited, res);

            visited[i] = false;
            res.erase(res.end()-1);

            for(j = adj[i].begin(); j != adj[i].end(); j++){
                indegree[*j]++;
            }

            flag = true;
        }
    }

    if(!flag){
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}

void alltopological(){
    vector<bool>visited(V, false);
    vector<int>res;

    alltopologicalutil(visited, res);
}
int main(){
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    alltopological();

    return 0;
}
