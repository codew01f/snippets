
vi scc(grid &edg){ //tarjans' alg
  ll cn = edg.size(), id = 1;

  vi idx(cn, 0), mnv(cn, 0);
  vi vst(cn, 0);
  vi sc(cn, 0);
  stack<ll> stk;
  
  function<void(int)> dfs = [&](int n){
    vst[n]++;
    idx[n]=id; mnv[n]=id;
   
    stk.push(n); id++;
    for(ll to: edg[n]){
      if(!vst[to]){
        dfs(to);
        mnv[n]=min(mnv[n], mnv[to]);
      }else if(vst[to]==1){
        mnv[n]=min(mnv[n], idx[to]);
      }
    }

    if(mnv[n]==idx[n]){
      while(1){
        ll at=stk.top(); stk.pop();
        sc[at]=n; vst[at]=-1;
        if(at==n) break;
      }
    }
  };

  fir(cn){
    if(!vst[i]) dfs(i);
  }
  return sc;
}
