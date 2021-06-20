#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums) {
  int length = 0;
  int evens = 0;

  for(int i = 0; i< nums.size(); i++){
    int element = nums[i];
    while (element >= 10){
      
      cout<< element << "\n";
      element = element / 10;
      length++;
    }
    
    if (length % 2 != 0){
      evens++;
    }

    length =0;
  }
  
  return evens;
}



int main(){
  vector<int> arr = {100000};
  cout << to_string(findNumbers(arr));
  return 0;
}