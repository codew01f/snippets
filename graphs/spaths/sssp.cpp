
vi sssd(vector<vector<pii>> &edg, ll sn){ //dijkstras' alg
  vi ssd(edg.size(), LLONG_MAX), vis(edg.size(), 0);
  priority_queue<pii> cll;
  ssd[sn]=0; cll.push({0, sn});

  while(!cll.empty()){
    auto [wt0, at]=cll.top(); cll.pop(); vis[at]=1;
    if(-wt0>ssd[at]) continue;
    for(auto [to, wt]: edg[at]){
      ll d=wt+ssd[at];
      if(d<ssd[to]){
        ssd[to]=d;
        cll.push({-d, to});
      }
    }
  }
  return ssd;
}

