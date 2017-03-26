// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// solution structure
struct Interval
{
    long long int buy;
    long long int sell;
};

// This function finds the buy sell schedule for maximum profit
void stockBuySell(long long int price[], long long int n)
{
    // Prices must be given for at least two days
    if (n == 1)
        return;

    long long int count = 0; // count of solution pairs

    // solution vector
    Interval sol[n/2 + 1];

    // Traverse through given price array
    long long int i = 0;
    while (i < n-1)
    {
        // Find Local Minima. Note that the limit is (n-2) as we are
        // comparing present element to the next element.
        while ((i < n-1) && (price[i+1] <= price[i]))
            i++;

        // If we reached the end, break as no further solution possible
        if (i == n-1)
            break;

        // Store the index of minima
        sol[count].buy = price[i];
        i++;
        // Find Local Maxima.  Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i-1]))
            i++;

        // Store the index of maxima
        sol[count].sell = price[i-1];

        // Increment count of buy/sell pairs
        count++;
    }

    // print solution
    if (count == 0)
        printf("There is no day when buying the stock will make profit\n");
    else
    {
       long long int sum = 0;
       for (long long int i = 0; i < count; i++)
        sum += (sol[i].sell - sol[i].buy);

    cout<<endl;
    cout<<sum<<endl;
    }

    return;
}

// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    //int price[] = {100, 180, 260, 310, 40, 535, 695};
    //int n = sizeof(price)/sizeof(price[0]);
    long long int i, n;
    long long int price[1000];

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> price[i];
    }
    // fucntion call
    stockBuySell(price, n);

    return 0;
}
