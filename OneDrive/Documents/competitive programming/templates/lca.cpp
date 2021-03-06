const int MAXN=200001;
const int K=20;
int par[MAXN][K+1];
int tin[MAXN];
int tout[MAXN];
int t=0;

void dfs(int x){
  t++;
  tin[x]=t;
  rep(i, 1, K){
    par[x][i]=par[par[x][i-1]][i-1];
  }
  trav(k, adj[x]){
    if(k!=par[x][0]){
      par[k][0]=x;
      dfs(k);
    }
  } 
  t++;
  tout[x]=t;
}

bool anc(int a, int b){
  return tin[a]<=tin[b] && tout[a]>=tout[b];
}

int lca(int u, int v){
  if(anc(u, v)) return u;
  for(int i=K; i>=0; i--){
    if(par[u][i]!=0 && !anc(par[u][i], v)) u=par[u][i];
  }
  return par[u][0];
}
