
grid apsp(vector<vector<pii>> &edg){ //floyd-warshall alg
  ll cn=edg.size();
  grid dis(cn, vi(cn, INT_MAX));

  fir(cn) for(auto [to, wt]: edg[i]){
    dis[i][to]=wt;
  }
  for(int k=0; k<cn; ++k){
    fjr(cn) fir(cn){
      if(dis[j][k]+dis[k][i]<dis[j][i]){
        dis[j][i]=dis[j][k]+dis[k][i];
      }    
    }
  }
  return dis;
}
