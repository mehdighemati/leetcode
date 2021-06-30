#include <iostream>
#include <vector>

using namespace std;


int mySqrt(int x) {

  int L = 0;
  int R = x;
  int mid;

  // 15
  // 0 -- 7 --- 15
  // 0 - 3 - 6
  // 4 - 5 - 6
  // 4----4 - 4 
  // 0 --- 15

  

  while(L <= R){
    mid = (L + R)/2;

    cout << L << ", " << mid << ", " << R;
    cout << endl;

    if(x == mid*mid){
      return mid;
    }

    if (x < mid*mid){
      R = mid - 1;
    }

    else if( x > mid*mid){
      L = mid + 1;
    }
    
  }

   return R; 
}

int main(){
  int test = mySqrt(15);

  cout << to_string(test);
  cout << endl;
}