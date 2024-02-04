
grid apsd(vector<vector<pii>> &edg){ //floyd-warshall alg
  ll cn=edg.size(); ll INF = 0x3f3f3f3f3f3f3f3f;
  grid asd(cn, vi(cn, INF));
  
  fir(cn) for(auto [to, wt]: edg[i]){
    asd[i][to]=min(asd[i][to], wt);
  }
  fir(cn) asd[i][i]=0;
  for(int k=0; k<cn; ++k){
    fjr(cn) fir(cn) asd[j][i]=min(asd[j][i], asd[j][k]+asd[k][i]);
  }
  return asd;
}
