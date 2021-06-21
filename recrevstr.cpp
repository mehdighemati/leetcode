#include <iostream>
#include <vector>

using namespace std;

void helper(int left, int right, vector<char>& s){
  if(left >= right){
    return;
  }
  
  auto temp = s[left];
  s[left++] = s[right];
  s[right--] = temp;

  helper(left, right, s);
}

void reverseString(vector<char>& s) {
  helper(0, s.size()-1, s);
}