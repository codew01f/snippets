
vi tsort(ll cn, ll ce, grid &edg){
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
