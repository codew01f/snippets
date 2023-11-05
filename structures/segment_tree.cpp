
vi mkst(vi &v){
  int n = v.size();
  vi res(2*n);

  for(int i=0; i<n; ++i) res[n+i]=v[i];
  for(int i=n-1; i; --i){
    res[i] = res[i<<1]+res[i<<1|1];
  }
  return res;
}

void stud(vi &v, int p, ll val){
  int n = v.size()/2;
  for(v[p+=n]=val; p>1; p>>=1){
    v[p>>1]=v[p]+v[p^1];
  }
}

ll stgs(vi &v, int l, int r){ //0 indexed;
  int n = v.size()/2;
  int res = 0;

  for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
    if(l&1) res+=v[l++];
    if(r&1) res+=v[--r];
  }
  return res;
}

