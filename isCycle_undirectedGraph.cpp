#include <bits/stdc++.h>
#define V 3

using namespace std;

bool isCycleUtil(int arr[V][V], int v, vector<bool>&visited, int parent){
    visited[v] = true;

    for(int j = 0; j < V; j++){
        if(arr[v][j] == 1){
            if(!visited[j]){
                if(isCycleUtil(arr, j, visited, v))
                    return true;
            }
            else if(parent != j)
                return true;
        }
    }
    return false;
}
bool isCycle(int arr[V][V]){
    vector<bool>visited(V, false);
    int parent = -1;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(isCycleUtil(arr, i, visited, parent))
                return true;
        }
    }
    return false;
}
int main(){
    int arr[V][V] = {{1,1,0},
                     {1,0,1},
                     {0,1,0}};

    cout<<isCycle(arr);

    return 0;
}
