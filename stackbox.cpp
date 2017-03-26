#include <bits/stdc++.h>

using namespace std;

struct box{
    int l;
    int w;
    int h;
};

bool comp(struct box a, struct box b){
    int x = ((b.w * b.l)-(a.w * a.l));
    if(x > 0)
        return 0;
    return 1;
}
int maxStackHeight(struct box arr[] ,int n){
    int index=0;
    int i,j;
    struct box rot[3*n];

    for(i = 0; i < n; i++){
        rot[index] = arr[i];
        index++;

        rot[index].h = arr[i].l;
        rot[index].w = max(arr[i].w, arr[i].h);
        rot[index].l = min(arr[i].w, arr[i].h);
        index++;

        rot[index].h = arr[i].w;
        rot[index].w = max(arr[i].l, arr[i].h);
        rot[index].l = min(arr[i].l, arr[i].h);
        index++;
    }

    n = 3*n;

    sort(rot, rot+n, comp);

    int lis[n];

    for(i = 0; i < n; i++){
        lis[i] = rot[i].h;
    }

    for(i = 1; i < n; i++){
        for(j = 0; j < i; j++){
            if(rot[i].w < rot[j].w && rot[i].l < rot[j].l && lis[i] < lis[j]+rot[i].h){
                lis[i] = lis[j] + rot[i].h;
            }
        }
    }

    int mx = lis[0];

    for(i = 1; i < n; i++){
        if(lis[i] > mx)
            mx = lis[i];
    }
    return mx;
}
int main(){
    struct box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };

    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The maximum possible height of stack is %d\n", maxStackHeight(arr, n));

    return 0;
}
