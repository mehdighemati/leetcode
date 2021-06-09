#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

vector<pair<vector<int>, double>> merge(vector<pair<vector<int>, double>> arr1, vector<pair<vector<int>, double>> arr2){
  int i = 0;
  int j = 0;

  vector<pair<vector<int>, double>> ans;

  while(i < arr1.size() && j < arr2.size()){
    if(arr1[i].second < arr2[j].second){
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

vector<pair<vector<int>, double>> mergeSort(vector<pair<vector<int>, double>> arr){
  if(arr.size() <= 1 ){
    return arr;
  }
  int mid = arr.size()/2;

  vector<pair<vector<int>, double>> left;
  vector<pair<vector<int>, double>> right;

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




vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    double distance;
    //unordered_map<pair<int,int>, float> hm = {};
    vector<pair<vector<int>, double>> ans;
    //vector<pair<double,vector<int>>> distances;
    for(int i=0; i< points.size(); i++){
      //calculating distance of each point 
      distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
      ans.push_back({points[i],distance});
    }

    vector<pair<vector<int>, double>> sorted = mergeSort(ans);

    vector<vector<int>> newAns;

    for(int i=0; i< k; i++){
      newAns.push_back(sorted[i].first);
    }
    return newAns;
}

int main(){
  vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
  vector<vector<int>> ans = kClosest(points, 2);
  
  for(int i=0; i < ans.size(); i++){
    cout<< ans[i][0] << ", " << ans[i][1] <<"\n";
  }
  
  
  return 0;
}