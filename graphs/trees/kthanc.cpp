
ll kth(grid &bl, ll n, ll k){
  ll kk=log2(k)+1;
  
  fir(kk){
    if(k&(1<<i)){
      n=bl[i][n];
      if(!n) return -1; 
    }
  }
  return n;
}
