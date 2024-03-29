const int MAXN=100000;
int tin[MAXN+1];
int t=0;
int et[2*MAXN];
int st[2*MAXN+1][20];
int lg[2*MAXN+1];
int par[MAXN+1];
int height[MAXN+1];

void dfs(int x){
  t++;
  tin[x]=t;
  et[t]=x;
  trav(k, adj[x]){
    if(k!=par[x]){
      par[k]=x;
      // sum[k]=sum[x]+k.s;
      height[k]=height[x]+1;
      dfs(k);
      t++;
      et[t]=x;
    }
  } 
}

int lca(int a, int b){
  if(tin[b]<tin[a]) swap(a, b);
  int l=lg[tin[b]-tin[a]+1];
  return (height[st[tin[a]][l]]<height[st[tin[b]-(1<<l)+1][l]]? st[tin[a]][l]:st[tin[b]-(1<<l)+1][l]);
}

void init(){
  int N=2*n-2;
  rep(i, 1, N){
    st[i][0]=et[i];
  }
  for(int j=1; j<20; j++){
    for(int i=1; i+(1<<j)<=N; i++){
      st[i][j]=st[i][j-1];
      if(height[st[i+(1<<(j-1))][j-1]]<height[st[i][j]]) st[i][j]=st[i+(1<<(j-1))][j-1];
    }
  }
}


rep(i, 2, 200000) lg[i]=lg[i/2]+1;