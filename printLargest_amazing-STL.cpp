#include <bits/stdc++.h>

using namespace std;

int myfunction(string x, string y) {
    string xy = x.append(y);
    string yx = y.append(x);

    return xy.compare(yx) > 0 ? 1:0;
}
int main()
{

    vector<string> myvector;

    myvector.push_back("54");
    myvector.push_back("546");
    myvector.push_back("548");
    myvector.push_back("60");

    sort(myvector.begin(), myvector.end(),myfunction);

    for(int i = 0; i < myvector.size(); i++){
        cout<<myvector[i];
    }
    return 0;
}
