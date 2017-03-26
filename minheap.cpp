#include <bits/stdc++.h>

using namespace std;

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return (2*i+1);
}

int right(int i){
    return (2*i+2);
}

int arr[1000];
int heap_size = 0;

void minheapify(int i){
    int l = left(i);
    int r = right(i);
    int mn = i;

    if(l < heap_size && arr[l] < arr[i])
        mn = l;
    if(r < heap_size && arr[r] < arr[mn])
        mn = r;

    if(mn != i){
        swap(arr[mn], arr[i]);
        minheapify(mn);
    }
}
void insertkey(int k){
    if(heap_size == 1000)
        return;

    heap_size++;

    int i = heap_size-1;
    arr[i] = k;

    while(i != 0 && arr[parent(i)] > arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void decreasekey(int i, int new_val){
    arr[i] = new_val;

    while(i != 0 && arr[parent(i)] > arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int extractMin(){
    if(heap_size <= 0)
        return INT_MAX;

    if(heap_size == 1){
        heap_size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    minheapify(0);

    return root;
}

void deletekey(int i){
    decreasekey(i, INT_MIN);
    int x = extractMin();
}


int main(){

    insertkey(3);
    insertkey(2);
    deletekey(1);
    insertkey(15);
    insertkey(5);
    insertkey(4);
    insertkey(45);

    cout<<extractMin();
}
