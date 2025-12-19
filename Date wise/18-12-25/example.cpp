#include <bits/stdc++.h>
using namespace std;

void arrangeUp(vector<int>&arr){
  int i = arr.size()-1;
  while(i > 0){
    int p = (i-1)/2; // parent
    if(arr[p] < arr[i]){
      swap(arr[p], arr[i]);
      i = p;
    }else break;
  }
}
void insert(vector<int>&arr, int val){
  arr.push_back(val);
  arrangeUp(arr);
}

void arrangeDown(vector<int>&arr, int i, int n){
  if(i >= n) return ;
  int l = 2*i + 1;
  int r = 2*i + 2;
  int lar = i;
  if(l < n && arr[l] > arr[lar]) lar = l;
  if(r < n && arr[r] > arr[lar]) lar = r;
  
  if(lar != i){
    swap(arr[i], arr[lar]);
    arrangeDown(arr, lar, n);
  }
}

void del(vector<int>&arr){
  int n = arr.size();
  swap(arr[0], arr[n-1]);
  arr.pop_back();
  arrangeDown(arr, 0, n-1);
}

void print(vector<int>&arr){
  for(int e: arr) cout<<e<<" ";
  cout<<endl;
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        arrangeDown(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        arrangeDown(arr, 0, i);
    }
}

int main() 
{
    vector<int> arr;
    insert(arr, 44);
    insert(arr, 33);
    insert(arr, 77);
    insert(arr, 11);
    insert(arr, 55);
    insert(arr, 88);
    insert(arr, 66);
    print(arr);
    del(arr);
    print(arr);
    heapSort(arr);
    print(arr);
}