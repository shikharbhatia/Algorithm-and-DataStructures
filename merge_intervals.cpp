#include <bits/stdc++.h>

using namespace std;

struct pt
{
    int x;
    int y;
};

int myfunction(struct pt a, struct pt b)
{
    return a.x > b.x;
}

void mergeIntervals(struct pt arr[], int n)
{
    int i;
    struct pt p1;
    struct pt p2;
    struct pt p;
    stack <struct pt> s;

    sort(arr, arr+n, myfunction);

    for(i = 0; i < n; i++)
        s.push(arr[i]);

    while(s.size() > 1){
       p1 = s.top();
       s.pop();
       p2 = s.top();
       s.pop();

       if(p1.y > p2.x){
            p.x = min(p1.x, p2.x);
            p.y = max(p1.y, p2.y);
            s.push(p);
       }
       else{
            s.push(p2);
            cout<<p1.x<<" "<<p1.y<<endl;
       }
    }
    p = s.top();
    cout<<p.x<<" "<<p.y<<endl;
}


int main()
{
    struct pt arr[] = {{1,3}, {2,4}, {5,7}, {6,8} };
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}
