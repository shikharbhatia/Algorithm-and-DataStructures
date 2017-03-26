#include <bits/stdc++.h>

using namespace std;

void DFSutil(vector <list<int> > adjList, bool visited[], int s){
    visited[s] = true;
    cout<<s<<" ";

    list<int>::iterator i;

    for(i = adjList[s].begin(); i != adjList[s].end(); i++){
        if(!visited[*i])
            DFSutil(adjList, visited, *i);
    }
}

void DFS(vector <list<int> > adjList, int s){
    bool visited[100];
    int i;

    for(i = 0; i < 5; i++){
        visited[i] = false;
    }
    DFSutil(adjList, visited, s);
}
int main()
{
    vector<list<int> > adjList(5);

    adjList[0].push_back(1);
    adjList[0].push_back(4);

    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);

    adjList[2].push_back(1);
    adjList[2].push_back(3);

    adjList[3].push_back(1);
    adjList[3].push_back(4);
    adjList[3].push_back(2);

    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[4].push_back(3);

    DFS(adjList, 0);

    return 0;
}
