
vi scc(grid &edg){ //tarjans' alg
  ll cn = edg.size(), id=1;
  vi idx(cn, 0), mnv(cn, 0);
  vi vst(cn, 0), sc(cn, 0);
  stack<ll> stk;
  
  function<void(ll)> dfs=[&](ll n){
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

  fir(cn) if(!vst[i]) dfs(i);
  return sc;
}



vi scc(grid &edg, grid &rev){ //kosaraju alg
  ll cn=edg.size();
  vi vst(cn, 0), sc(cn, 0);
  vi stk;
  
  function<void(ll)> d1=[&](ll at){
    vst[at]++;
    for(ll to: edg[at]) if(!vst[to]) d1(to);
    stk.push_back(at);
  };
  function<void(ll, ll)> d2=[&](ll at, ll sn){
    vst[at]--; sc[at]=sn;
    for(ll to: rev[at]) if(vst[to]) d2(to, sn);
  };

  fir(cn) if(!vst[i]) d1(i);
  reverse(stk.begin(), stk.end());
  for(ll i: stk) if(vst[i]){
    d2(i, i);
  }
  return sc;
}
