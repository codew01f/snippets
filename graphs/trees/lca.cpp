
ll lca(grid &bl, ll a, ll b, vi &dep){
  if(dep[a]<dep[b]) swap(a, b);
  ll k=dep[a]-dep[b], kk=bl.size()-1;

  a=kth(bl, a, k);
  if(a==b) return a;
  for(ll i=kk; i+1; i--){
    if(bl[i][a]!=bl[i][b]){
      a=bl[i][a];
      b=bl[i][b];
    }
  }
  return bl[0][a];
}
