#include <iostream>
#include <vector>

using namespace std;

int helper(long left, long right){
  long mid = (left + right)/2;

  if (guess(mid) == 0){
    return mid;  
  }

  if (guess(mid) == -1){
    return helper(left ,mid-1);
  }
  else{
    return helper(mid + 1, right);
  }
  
}

int guessNumber(int n) {
   return helper(1, n);
}

// int guess(int proposed, int target){

//   if(target < proposed){
//     return -1;
//   }

//   else if(target > proposed){
//     return 1;
//   }

//   else(target == proposed){
//     return 0;
//   }
// }

int main(){
  return 0;
}