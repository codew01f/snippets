
void bfs(grid &edg, ll sn){
  ll cn=edg.size(), lv=-1, cl=0, nl=1;
  vi vst(cn+1, 0), prt(cn+1, -1);
  queue<ll> call;
  call.push(sn);
  while(!call.empty()){
    vst[sn]++;
    if(!cl){
      lv++; cl=nl; nl=0;
    }

    int at=call.front();
    call.pop(); cl--;
    for(ll to:edg[at]){
      if(!vst[to]){

        prt[to]=at;
        call.push(to);
        vst[to]++;
        nl++;
      }
    }
  }
  return;
}
