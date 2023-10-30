
void dfs(vector<vi> &q, int r, int c){
  int row=q.size();
  int col=q[0].size();

  vi dx={1, -1, 0, 0};
  vi dy={0, 0, -1, 1};

  for(int d=0; d<4; ++d){
    if(-1<r+dy[d] && r+dy[d]<row
    && -1<c+dx[d] && c+dx[d]<col){ //check !visited

      //dfs code
      if(){
        dfs(q, r+dy[d], c+dx[d]);
      }
    }
  }
  return;
}
