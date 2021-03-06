struct segtree{
	int size;
	vector<ll> vals;

	void init(int n){
		size=1;
		while(size<n) size*=2;
		vals.assign(2*size, 0LL);
	}

	void build(vector<ll> &a, int x, int lx, int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()) vals[x]=a[lx];
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		vals[x]=min(vals[2*x+1], vals[2*x+2]);
	}

	void build(vector<ll> &a){
		build(a, 0, 0, size);
	}

	void set(int i, ll v, int x, int lx, int rx){
		if(rx-lx==1){
			vals[x]=v; return;
		}
		int m=(lx+rx)/2;
		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}
		else {
			set(i, v, 2*x+2, m, rx);
		}
		vals[x]=min(vals[2*x+1], vals[2*x+2]);
	}

	void set(int i, ll v){
		set(i, v, 0, 0, size);
	}

	ll calc(int l, int r, int x, int lx, int rx){
		if(lx>=l && rx<=r) return vals[x];
		if(lx>=r || rx<=l) return INF;
		int m=(lx+rx)/2;
		ll s1=calc(l, r, 2*x+1, lx, m);
		ll s2=calc(l, r, 2*x+2, m, rx);
		return min(s1, s2);
	}

	ll calc(int l, int r){
		return calc(l, r, 0, 0, size);
	}
};






// EXAMPLE


int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  int n, m, u, v, l, r;
  cin >> n >> m;
  vector<int> a(n);
  segtree st;
  st.init(n);

  rep(i, 0, n-1){
  	cin >> a[i];
  }
  st.build(a);

  rep(i, 1, m){
  	int op;
  	cin >> op;
  	if(op==1){
  		cin >> u >> v;
  		st.set(u, v);
  	}
  	else {
  		cin >> l >> r;
  		cout << st.calc(l, r) << endl;
  	}
  }
}