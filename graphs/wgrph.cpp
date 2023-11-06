
vector<vector<pii>> mkwgph(ll cn, ll ce){
  vector<vector<pii>> edg(cn+1, vector<pii>(0));

  ll fr, to, wt;
  fir(ce){
    cin>>fr>>to>>wt;
    edg[fr].push_back({to, wt});
  }
  return edg; 
}
