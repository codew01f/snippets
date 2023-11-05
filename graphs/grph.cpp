
ll cn = 200000; //node count;
ll ce = 200000; //edge count;

grid edg1(cn+1, {}); //unweighted;
vector<vector<pi>> wedg(cn+1, {}); //weighted;

void mkgph(grid &edg, ll ce){
  ll fr, to, wt;
  while(ce--){
    cin>>fr>>to;
    cin>>wt; //if weighted;

    //if unweighted;
    edg[fr].push_back(to);
    edg[to].push_back(fr); //if undirected;

    //if weighted;
    edg[fr].push_back({to, wt});
    
  }
  return; 
}
