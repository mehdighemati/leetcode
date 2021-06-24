#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
  if(rowIndex == 0) {
    return {1};
  }
  if(rowIndex == 1) {
    return {1,1};
  }
  vector<int> prevRow = getRow(rowIndex - 1);


  vector<int> row = {};

  row.push_back(1);

  for(int i = 1; i <= prevRow.size()-1; i++){
    row.push_back(prevRow[i] + prevRow[i-1]);
  }

  row.push_back(1);

  return row;

}