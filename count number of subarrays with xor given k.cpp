int Solution::solve(vector<int> &A, int B) {
  unordered_map<int,int>mp;
  int count=0;
  mp[0]=1;
  int x=0;
  for(auto &i:A)
  {
      x^=i;
      if(mp.count(x^B))
      {
          count+=mp[x^B];
      }
      mp[x]++;
  }
  return count;
}
