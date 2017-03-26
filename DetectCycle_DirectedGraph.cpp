#include <bits/stdc++.h>
#define V 5

using namespace std;

bool DetectCycleUtil(vector<list<int> > adjList, bool visited[], bool rec[], int s){
    if(visited[s] == false){

        visited[s] = true;
        rec[s] = true;

        list<int>::iterator it;
        for(it = adjList[s].begin(); it != adjList[s].end(); it++){
            if(!visited[*it] && DetectCycleUtil(adjList, visited, rec, *it))
                return true;
            else if(rec[*it])
                return true;
        }
    }
    rec[s] = false;
    return false;
}
bool DetectCycle(vector<list<int> > adjList){
    bool visited[V];
    bool rec[V];

    int i;

    for(i = 0; i < V; i++){
        visited[i] = false;
        rec[i] = false;
    }
    for(i = 0; i < V; i++){
        if(DetectCycleUtil(adjList, visited, rec, i))
            return true;
    }
    return false;
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

    bool ans = DetectCycle(adjList);
    if(ans)
        cout<<"yes, there is a cycle";
    else
        cout<<"No";

    return 0;
}
