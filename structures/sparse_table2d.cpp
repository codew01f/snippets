
vector<grid> mkst(grid g){
  int r=g.size();
  int c=g[0].size();
  int k=log2(min(r, c)-1);

  vector<grid> res(k+1, grid(r, vi(c, 0)));
  fir(r){
    fjr(c){
      res[0][i][j]=g[i][j];
    }
  }
  for(int p=0; p<k; ++p){
    fir(r-(2<<p)+1){
      fjr(c-(2<<p)+1){
        ll m1=min(res[p][i][j], res[p][i][j+(1<<p)]);
        ll m2=min(res[p][i+(1<<p)][j], res[p][i+(1<<p)][j+(1<<p)]);

        res[p+1][i][j]=min(m1, m2);
      }
    }
  }
  return res;
}

ll stgm(vector<grid> st, int r, int c, int k){ //0 indexed;
  if(k==1) return st[0][r][c]; 
  int p = log2(k-1);
  int rr = r+k-1;
  int cc = c+k-1;
  ll mi1=min(st[p][r][c], st[p][rr-(1<<p)+1][c]);
  ll mi2=min(st[p][r][cc-(1<<p)+1], st[p][rr-(1<<p)+1][cc-(1<<p)+1]);
  return min(mi1, mi2);
}
