
vi sssd(ll cn, ll ce, ll s, vector<vector<pii>> &edg){
  vi dis(cn+1, INT_MAX);
  dis[s]=0;
  vi vst(cn+1, 0);
  priority_queue<pii, vector<pii>, greater<pii>> call;

  call.push({0, s});
  while(!call.empty()){
    auto [wt0, at]=call.top();
    call.pop();
    vst[at]++;
    for(auto [to, wt]:edg[at]){
      if(vst[to]) continue;
      ll d=dis[at]+wt;
      if(d<dis[to]){
        dis[to]=d;
        call.push({d, to});
      }
    }
  }
  return dis;
}
