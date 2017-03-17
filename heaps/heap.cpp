#include <bits/stdc++.h>

using namespace std;

void swap(int a, int b,int arr[]){
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

void max_heapify(int arr[], int i, int n){
  int left = 2*i;
  int right = 2*i+1;
  int largest = 1e5;
  if(left <= n && arr[left] > arr[i])
    largest = left;
  else
    largest = i;
  if(right <= n && arr[right] > arr[largest])
    largest = right;
  if(largest != i){
    swap(i, largest, arr);
    max_heapify(arr, largest, n);
  }
}

void build_max_heap(int arr[], int n){
  for(int i = n/2; i >= 1; i--) // As [n/2 + 1] to n are leaf nodes.
    max_heapify(arr, i, n);
}

void heap_sort(int arr[], int n){   // O(nlogn)
  int heap_size = n;
  build_max_heap(arr, n);
  for(int i = n; i >= 2; i--){
    swap(arr[1], arr[i]);
    heap_size--;
    max_heapify(arr, 1, heap_size);
  }
}
// Max priority queue
int maximum(int arr[]){
  return arr[1];
}

int extract_maximum(int arr[], int l){  // O(log n)
  if(l == 0)
    return -1;
  int mx = arr[1];
  arr[1] = arr[l];
  l--;
  max_heapify(arr, 1, l);
  return mx;
}
void increase_value(int arr[], int i, int val){ // O(log n)
  if(val < arr[i]){
    return;
  }
  arr[i] = val;
  while(i > 1 && arr[i/2] < arr[i]){
    swap(i/2, i, arr);
    i /= 2;
  }
}
void insert_value(int arr[], int l, int val){
  l += 1;
  arr[l] -= 1;
  increase_value(arr, l, val);
}
int main(){
  int arr[] = {0,4,3,7,1,8,5};
  heap_sort(arr,6);
  for(int i = 1; i <= 6; i++)
    cout << arr[i] << " ";
  return 0;
}
