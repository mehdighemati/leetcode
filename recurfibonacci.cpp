#include <iostream>
#include <unordered_map>
#include <vector>

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

using namespace std;


unordered_map<int,int> hm = {};

int fib(int n){
  
  //check if n<2 return n 
  if(n<2){
    return n;
  }
  
  if(hm.find(n) != hm.end()){
    return hm[n];
  }else{

    int previous = fib(n-1);
    int previousx2 = fib(n-2);
    hm[n] = previous+ previousx2;
    
    return hm[n];     
  }
  //if n in hashmap, return hashmap value, 
  
  //else call fib and store in hashmap?

  //if n not in hashmap, store the calculated 

    
}
