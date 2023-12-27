
void bfs(vector<vi> &q, int r, int c){
  ll row=q.size();
  ll col=q[0].size();
  ll lv=-1, cl=0, nl=1;
  vi dx={1, -1, 0, 0};
  vi dy={0, 0, -1, 1};

  queue<pii> call;
  call.push({r, c});
  while(!call.empty()){
    if(!cl){
      lv++; cl=nl; nl=0;
    }
    auto [y, x]=call.front();
    call.pop(); cl--;
    for(int d=0; d<4; ++d){
      if(-1<y+dy[d] && y+dy[d]<row
      && -1<x+dx[d] && x+dx[d]<col){ //check !visited
        
        if(){
          call.push({y+dy[d], x+dx[d]});
          nl++;
        }
      }
    }
  }
  return;
}

