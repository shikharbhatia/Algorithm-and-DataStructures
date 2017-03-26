#include <bits/stdc++.h>

using namespace std;

long long int countNonDecreasing(int n)
{
    int N = 10;

    // Compute value of N*(N+1)/2*(N+2)/3* ....*(N+n-1)/n
    long long count = 1;
    for (int i=1; i<=n; i++)
    {
        count *= (N+i-1);
        count /= i;
    }

    return count;
}

// Driver program
int main()
{
    int n = 3;
    cout << countNonDecreasing(n);
    return 0;
}
