
vi tsort(ll cn, ll ce, grid &edg){ //kahns' alg;
  vi ts(cn, 0);
  vi indg(cn+1, 0);
  queue<ll> call;

  for(vi v:edg){
    for(ll to:v) indg[to]++;
  }
  fir(cn){
    if(!indg[i+1]) call.push(i+1);
  }

  ll id=0;
  while(!call.empty()){
    ll at=call.front();
    call.pop();
    ts[id++]=at;
    
    for(ll to:edg[at]){
      indg[to]--;
      if(!indg[to]) call.push(to);
    }
  }
  return ts;
}


vi tsort(ll cn, ll ce, grid &edg){ //dfs;
  vi ts(cn, 0);
  vi vst(cn+1, 0);
  stack<int> call;

  ll cnt=cn;
  fir(cn){
    if(vst[i+1]) continue;
    call.push(i+1);
    vst[i+1]++;

    while(!call.empty()){
      ll at=call.top();
      ll lf=1;
      for(ll to:edg[at]){
        if(vst[to]) continue;
        call.push(to);
        vst[to]++;
        lf=0;
      }
      if(lf){
        ts[--cnt]=at;
        call.pop();
      }
    }  
  }
  return ts;
}
