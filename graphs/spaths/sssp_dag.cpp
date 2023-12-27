
vi sssd(vector<vector<pii>> &edg, vi &ts, ll s){
  ll cn=edg.size();
  vi dis(cn, INT_MAX);
  dis[s]=0;

  ll idx=0;
  while(ts[idx]!=s) idx++;
  while(idx<cn-1){
    ll at=ts[idx];
    for(auto [to, wt]:edg[at]){
      dis[to]=min(dis[to], dis[at]+wt);
    }
    idx++;
  }
  return dis;
}
