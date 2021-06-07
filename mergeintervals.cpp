class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

  vector<int> track = intervals[0];
  if(intervals.size() == 1){
    return intervals;
  }
  vector<vector<int>> ans;
  
  for(int i = 1; i < intervals.size(); i++){
    vector<int> compare= intervals[i];

    if (track[1] >= compare[0]){
      track = {track[0], max(compare[1], track[1])};
      if(i == intervals.size()-1){
        ans.push_back(track);
      }
      //
    }else {
      ans.push_back(track);
      track = intervals[i];
      if(i == intervals.size()-1){
        ans.push_back(compare);
      }
    }
  }
  return ans;
}
};