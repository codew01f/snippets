
vi mkps(vi &v){
  int n = v.size();
  vi res(n+1);
  
  res[0] = 0;
  for(int i=1; i<n+1; ++i){
    res[i] = res[i-1] + v[i-1];
  }
  return res;
}

ll psgs(vi &ps, int l, int r){ //0 indexed;
  return ps[r+1]-ps[l];
}
