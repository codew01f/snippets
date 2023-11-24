
void ftud(grid &ft, ll i, ll jj, ll val){
  ll r=ft.size();
  ll c=ft[0].size();
  
  ll j;
  for(; i<r; i += -i&i){
    for(j=jj; j<c; j += -j&j){
      ft[i][j]+=val;
    }
  }
  return;
}

grid mkft(grid &g){
  ll r=g.size();
  ll c=g[0].size();
  grid res(r+1, vi(c+1, 0));

  fir(r){
    fjr(c){
      ftud(res, i+1, j+1, g[j][i]);
    }
  }
  return res;
}

ll gt(grid &ft, ll x, ll yy){
  ll res=0, y;
  for(; x; x -= x&-x){
    for(y=yy; y; y -= y&-y){
      res+=ft[x][y];
    }
  }
  return res;
}

ll ftgs(grid &ft, ll x1, ll y1, ll x2, ll y2){
   x1++; y1++; x2++; y2++;
   return gt(ft, x2, y2)-gt(ft, x1-1, y2)-gt(ft, x2, y1-1)+gt(ft, x1-1, y1-1);
}
