#include <bits/stdc++.h>

using namespace std;

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

    vector<list<int> >::iterator it;
    list <int> li;
    for(it = adjList.begin(); it != adjList.end(); it++){

        li = *it;
        list<int>::iterator jt;


        for(jt = li.begin(); jt != li.end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}
