#include <iostream>

using namespace std;

int firstBadVersion(int n) {
  long left = 0;
  long right = n;
  int mid;
  int bad = n;

  while (left <= right){
    mid = (left+right)/2;
    if (isBadVersion(mid)){
      right = mid - 1;
      if (mid<bad){
        bad = mid;
      }
    }
    else{
      left = mid + 1;
    }
  }
  return bad;
}

