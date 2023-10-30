
void dfs(vector<vi> &q, int r, int c){
  int row=q.size();
  int col=q[0].size();

  vi dx={1, -1, 0, 0};
  vi dy={0, 0, -1, 1};

  for(int c=0; c<4; ++c){
    if(-1<r+dy[c] && r+dy[c]<row
    && -1<c+dx[c] && c+dx[c]<col){ //check !visited

      //dfs code
      if(){
        dfs(q, r+dy[c], c+dx[c]);
      }
    }
  }
  return;
}
