#include <iostream>
#include <vector>


using namespace std;

double newPow(double x, long long n){
  if(n == 0){
    return 1;
  }
  if(x == 0){
    return 0;
  }
  if(x == 1){
    return 1;
  }

  if(n>0){
    double half = newPow(x, n/2);
    if(n % 2 == 0){
      return half * half;
    } else {
      return half * half * x;
    }
  }
  
}



double myPow(double x, int n) {
  long long N = n;
  if (N < 0) {
      x = 1 / x;
      N = -N;
  }
  return newPow(x,N);
}



int main(){
  double test = myPow(10,3);

  cout << to_string(test);
}