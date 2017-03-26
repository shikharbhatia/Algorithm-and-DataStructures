#include <bits/stdc++.h>

using namespace std;

/* The output of this function is stored at *x and *y */
void getTwoElements(int arr[], int n, int *x, int *y)
{
  int xor1;   /* Will hold xor of all elements and numbers from 1 to n */
  int set_bit_no;  /* Will have only single set bit of xor1 */
  int i;
  *x = 0;
  *y = 0;

  xor1 = arr[0];

  /* Get the xor of all array elements elements */
  for(i = 1; i < n; i++)
     xor1 = xor1^arr[i];

  /* XOR the previous result with numbers from 1 to n*/
  for(i = 1; i <= n; i++)
     xor1 = xor1^i;

  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xor1 & ~(xor1-1);

  /* Now divide elements in two sets by comparing rightmost set
   bit of xor1 with bit at same position in each element. Also, get XORs
   of two sets. The two XORs are the output elements.
   The following two for loops serve the purpose */
  for(i = 0; i < n; i++)
  {
    if(arr[i] & set_bit_no)
     *x = *x ^ arr[i]; /* arr[i] belongs to first set */
    else
     *y = *y ^ arr[i]; /* arr[i] belongs to second set*/
  }
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
     *x = *x ^ i; /* i belongs to first set */
    else
     *y = *y ^ i; /* i belongs to second set*/
  }

  /* Now *x and *y hold the desired output elements */
}

/* Driver program to test above function */
int main()
{
  int arr[] = {1, 3, 4, 5, 5, 6, 2};
  int *x = (int *)malloc(sizeof(int));
  int *y = (int *)malloc(sizeof(int));
  int  n = sizeof(arr)/sizeof(arr[0]);
  getTwoElements(arr, n, x, y);
  printf(" The two elements are %d and %d", *x, *y);
  getchar();
}
