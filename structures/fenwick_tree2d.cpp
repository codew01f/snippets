
void ftud(grid &ft, ll rr, ll cc, ll del){
  rr++; cc++; 
  ll row=ft.size();
  ll col=ft[0].size(), c;
  
  for(; rr<row; rr+= -rr&rr){
    for(c=cc; c<col; c+= -c&c){
      ft[rr][c]+=del;
    }
  }
  return;
}

grid mkft(grid &g){
  ll row=g.size();
  ll col=g[0].size();
  grid gd(row+1, vi(col+1, 0));

  fir(row){
    fjr(col){
      ftud(gd, i, j, g[i][j]);
    }
  }
  return gd;
}

ll gt(grid &ft, ll rr, ll cc){
  rr++; cc++;
  ll res=0, c;
  
  for(; rr; rr -= rr&-rr){
    for(c=cc; c; c -= c&-c){
      res+=ft[rr][c];
    }
  }
  return res;
}

ll ftgs(grid &ft, ll r1, ll c1, ll r2, ll c2){
  return gt(ft, r2, c2)-gt(ft, r1-1, c2)
        -gt(ft, r2, c1-1)+gt(ft, r1-1, c1-1);
}
