#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
  stack<char> stack;
  unordered_map<char,char> hm_open = {
    {'(', ')'}, 
    {'[', ']'}, 
    {'{', '}'}
  }; 
  unordered_map<char, char> hm_close = {
    {')', '('},
    {']', '['},
    {'}', '{'}
  };
  char letter;
  char popped;
  
  for(int i = 0; i < s.length(); i++ ){
    letter = s[i];
    if (hm_open.count(letter) > 0){
      stack.push(letter);

    }
    else {

      if (!stack.empty()){
        
        popped = stack.top();
        if (hm_close[letter] == popped){
          stack.pop();
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }  
    }
  }
  if (stack.empty()){
    return true;
  }
  return false;
}