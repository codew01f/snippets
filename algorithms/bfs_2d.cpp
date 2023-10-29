
void bfs(vector<vi> &q, int r, int c){
  int row=q.size();
  int col=q[0].size();
  queue<pii> call;

  vi dx={1, -1, 0, 0};
  vi dy={0, 0, -1, 1};

  call.push({r, c});
  while(!call.empty()){
    auto [x, y]=call.front();
    call.pop();

    for(int c=0; c<4; c++){
      if(-1<r+dy[c] && r+dy[c]<row
      && -1<c+dx[c] && c+dx[c]<col){ //check !visited
        
        if(){
          call.push({y+dy[c], x+dx[c]});
        }
      }
    }
  }
}
