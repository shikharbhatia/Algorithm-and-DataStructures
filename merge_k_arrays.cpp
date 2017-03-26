#include <bits/stdc++.h>

using namespace std;

struct val
{
    int arr[12];
};

struct val Merger(struct val p, struct val q, int size1, int size2){
    int i,j, v;
    i = j = v = 0;
    struct val result;
    while(i < size1 && j < size2){
        if(p.arr[i] <= q.arr[j]){
            result.arr[v] = p.arr[i];
            v++;
            i++;
        }
        if(p.arr[i] > q.arr[j]){
            result.arr[v] = q.arr[j];
            v++;
            j++;
        }
    }
        while(i < size1){
            result.arr[v] = p.arr[i];
            v++;
            i++;
        }
        while(j < size2) {
            result.arr[v] = q.arr[j];
            v++;
            j++;
        }
    return result;
}
void mergeKarrays(int a[][4], int k, int n)
{
    struct val p;
    struct val t1;
    struct val t2;
    struct val r;
    int i,j;
    int size1 = -4;
    int size2 = 4;
    stack<struct val> s;

    for(i = 0; i < k; i++)
    {
        for(j = 0; j < n; j++)
        {
            p.arr[j] = a[i][j];
            s.push(p);
        }
    }
    cout<<"size"<<s.size();
    while(!s.empty()){
        cout<<"here";
        t1 = s.top();
        size1 = size1+4;
        cout<<size1;
        s.pop();
        t2 = s.top();
        s.pop();
        r = Merger(t1, t2, size1, 4);
        s.push(r);
    }

    t1 = s.top();

    for(i = 0; i < n*k; i++){
        cout<<t1.arr[i]<<" ";
    }
}

int main()
{

    int n = 4;
    int a[][4] =  {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};

    int k = sizeof(a)/sizeof(a[0]);

    mergeKarrays(a, k, 4);

    return 0;
}
