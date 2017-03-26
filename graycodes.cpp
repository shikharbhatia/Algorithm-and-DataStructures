#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// This function generates all n bit Gray codes and prints the
// generated codes
int to_decimal(string s){
    int i = 0;
    int n=0;
    int x,k = 0;
    for(i = s.size()-1; i >= 0; i--){
        x = (int) (s[i] - '0');
        cout<<"x = "<<x<<endl;
        n += x*(pow(2,k));
        k++;
    }
    return n;
}
vector<int>grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string>v;
    vector<int>sol;

    v.push_back("0");
    v.push_back("1");
    int i, j;

    for(i = 2; i <(1<<A); i = (i<<1)){
        for(j = i-1; j >= 0; j--){
            v.push_back(v[j]);
        }
        for(j = 0; j < i; j++){
            v[j] = "0"+v[j];
        }
        for(j = i; j < (2*i); j++){
            v[j] = "1"+v[j];
        }
    }
    for(i = 0; i < v.size(); i++){
        sol.push_back(to_decimal(v[i]));
    }
    return sol;
}

// Driver program to test above function
int main()
{
    vector<int>sol;
    sol = grayCode(4);

    for(int i = 0; i < sol.size(); i++){
        cout<<sol[i]<<" ";
    }
    return 0;
}
