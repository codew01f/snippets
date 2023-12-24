
void bfs(grid &edg, ll sn){
  ll cn=edg.size(), lv=-1, cl=0, nl=1, at;
  vi vst(cn+1, 0), prt(cn+1, -1);
  queue<ll> call;
  call.push(sn);
  while(!call.empty()){
    vst[sn]++;
    if(!cl){
      lv++; cl=nl; nl=0;
    }

    at=call.front();
    //if(at==en) return lv;
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
  //return at; //for deepest.
}
