#include <bits/stdc++.h>

using namespace std;
int foo(int n, vector<int>&f)
{
  /* Declare an array to store Fibonacci numbers. */
  int i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */

      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}
int fibsum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>fib(10000, -1);
    int x = foo(A,fib);
    cout<<x<<endl;

    vector<int>::iterator it;
    int c = 0;
    int idx;
    while(A > 0){
        it = lower_bound(fib.begin(), fib.end(), A);
        if(*it == A)
            A = A- (*it);
        else{
            it--;
            A = A - (*it);
        }
        c++;
    }
    return c;
}
int main(){
    cout<<fibsum(99);
}
