#include <bits/stdc++.h>

using namespace std;

struct box{
    int h;
    int d;
    int w;
};

bool comp(struct box a, struct box b){
    return((a.d*a.w) > (b.d*b.w));
}
int main(){
    int i, j;
    int n;

    cin >> n;

    struct box arr[n+1];

    for(i = 0; i < n; i++){
        cin >> arr[i].h;
        cin >> arr[i].w;
        cin >> arr[i].d;
    }
    //generation of all the rotations

    struct box rot[3*n + 1];

    int idx = 0;

    for(i = 0; i < n; i++){
        rot[idx] = arr[i];
        idx++;

        rot[idx].h = arr[i].w;
        rot[idx].d = max(arr[i].h, arr[i].d);
        rot[idx].w = min(arr[i].h, arr[i].d);
        idx++;

        rot[idx].h = arr[i].d;
        rot[idx].d = max(arr[i].h, arr[i].w);
        rot[idx].w = min(arr[i].h, arr[i].w);
        idx++;
    }

    sort(rot, rot + idx, comp);

    int dp[idx+1];

    for(i = 0; i < idx; i++){
        dp[i] = rot[i].h;
    }

    for(i = 1; i < idx; i++){
        for(j = 0; j < i; j++){
            if((rot[i].d < rot[j].d) && (rot[i].w < rot[j].w) && (dp[i] < dp[j]+rot[i].h))
                dp[i] = dp[j] + rot[i].h;
        }
    }
    int mx = -1;
    for(i = 0; i < idx; i++){
        if(mx < dp[i])
            mx = dp[i];
    }
    cout<<mx<<endl;

    return 0;
}
