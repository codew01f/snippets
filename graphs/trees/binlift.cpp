
grid binlift(grid &edg, vi &par){
  ll cn=edg.size(), kk=log2(cn);
  grid bl(kk+1, vi(cn, 0));

  fir(cn) for(ll to: edg[i]){
    if(par[to]==i) bl[0][to]=i;
    else bl[0][i]=to;
  }
  fir(kk) fjr(cn){
    bl[i+1][j]=bl[i][bl[i][j]];
  }
  return bl;
}
