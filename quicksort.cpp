#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>* arr, int i, int j){
  int temp = arr->at(i);
  arr->at(i) = arr->at(j);
  arr->at(j) = temp;
  //arr[i] = arr[j];
  //arr[j] = temp;
}

int partition(vector<int> &arr, int start, int end){
  
  int pivot = arr[start];
  int swapIdx = start;

  for(int i = start + 1; i < arr.size(); i++){
    if(pivot > arr[i]){
      swapIdx++;
      swap(&arr, swapIdx, i); 
    }
  }

  swap(&arr, start, swapIdx);
  return swapIdx;
}

vector<int> quickSort(vector<int> &arr, int left, int right){
  if(left < right){
    int pivotIndex = partition(arr, left, right);
    //Stuck here
    cout << pivotIndex << ", " << left  << ", " << right ;
    cout << endl;
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
  }
  return arr;
}
