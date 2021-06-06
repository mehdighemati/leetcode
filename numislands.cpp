class Solution {
public:
    
    void helper(int i, int j, vector<vector<char>>& grid){
  int rowSize = grid.size();
  int colSize = grid[0].size();
  //cout << i << " " << j << grid[i][j] << "\n";

  if(grid[i][j] == '1'){
    grid[i][j] = '0';
  }
  if(i!=0){
    if(grid[i-1][j]=='1'){
      helper(i-1,j, grid);
    }
  }
  if(j!=(colSize-1)){
    if(grid[i][j+1]=='1'){
      helper(i,j+1,grid);
    }
  }
  if(i!=(rowSize-1)){
    if(grid[i+1][j]=='1'){
      helper(i+1,j,grid);
    }
  }
  if(j!=0){
    if(grid[i][j-1]=='1'){
      helper(i,j-1,grid);
    }
  }
}
    int numIslands(vector<vector<char>>& grid) {
  int rowSize = grid.size();
  int colSize = grid[0].size();
  //std::cout<< "size of grid: " << i << ", " << j << "\n";
  int ans = 0;

  

  for (int i = 0; i < rowSize; i++){
    for (int j = 0; j< colSize; j++){
      if(grid[i][j] == '1'){
        //Send to recursive function
        helper(i,j, grid);
        ans++;
        cout << ans;
      }
    }
  }
  return ans;
}
};