#include <iostream>
#include <vector>

using namespace std;

//Helper function that takes in two sorted arrays and merges them

vector<int> merge(vector<int> arr1, vector<int> arr2){
  int i = 0;
  int j = 0;

  vector<int> ans;

  while(i < arr1.size() && j < arr2.size()){
    if(arr1[i] < arr2[j]){
      ans.push_back(arr1[i]);
      i++;
    }else{
      ans.push_back(arr2[j]);
      j++;
    }
  }

  while(i < arr1.size()){
    ans.push_back(arr1[i]);
    i++;
  }

  while(j < arr2.size()){
    ans.push_back(arr2[j]);
    j++;
  }

  return ans;
}


//The main Splitter/Recursive function

vector<int> mergeSort(vector<int> arr){
  if(arr.size() <= 1 ){
    return arr;
  }
  int mid = arr.size()/2;

  vector<int> left;
  vector<int> right;

  for(int i = 0; i< mid; i++){
    left.push_back(arr[i]);
  }

  left = mergeSort(left);

  for(int i = mid; i< arr.size(); i++){
    right.push_back(arr[i]);
  }
  
  right = mergeSort(right);

  return merge(left,right);

}

int main(){
  vector<int> arr1 = {10,8,12,15,25,20,100,2,3,5,15}; 
  vector<int> ans = mergeSort(arr1);

  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << "\n";
  }
  return 0;
}
