
set<pii> mst(ll cn, ll ce, vector<vector<pii>> &edg){ //prims' alg
  set<pii> mst;
  vi vst(cn+1, 0);
  priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> call;
  
  for(auto [to, wt]:edg[1]){
    call.push({wt, {1, to}});
  }
  vst[1]++;
  while(!call.empty()){
    auto [wt0, nd]=call.top();
    auto [at0, to0]=nd;
    call.pop();

    if(vst[to0]) continue;
    mst.insert({at0, to0});
    vst[to0]++;
    for(auto [to, wt]:edg[to0]){
      if(!vst[to]) call.push({wt, {to0, to}});
    }
  }
  return mst;
}
