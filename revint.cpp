class Solution {
public:
    int reverse(int x) {

  if (x == 0){
    return 0;
  }
        
  int ans = 0;
  int factor = 10;

  while (x != 0){
    int digit = x % 10;
    x = x - digit;
    x = x / 10;
    if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
    if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && digit < -8)) return 0;
    
    ans = ans*factor + digit;
    
  }

    return ans;

    };
};