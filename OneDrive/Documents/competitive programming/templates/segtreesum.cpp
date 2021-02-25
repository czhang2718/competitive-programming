#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct segtree{
	int size;
	vector<ll> sums;

	void init(int n){
		size=1;
		while(size<n) size*=2;
		sums.assign(2*size, 0LL);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		// cout << "build"<<endl;
		if(rx-lx==1){
			if(lx<(int)a.size()) sums[x]=a[lx];
			return;
		}
		int m=(lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		sums[x]=sums[2*x+1]+sums[2*x+2];
	}

	void build(vector<int> &a){
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx-lx==1){
			sums[x]=v; return;
		}
		int m=(lx+rx)/2;
		if(i<m){
			set(i, v, 2*x+1, lx, m);
		}
		else {
			set(i, v, 2*x+2, m, rx);
		}
		sums[x]=sums[2*x+1]+sums[2*x+2];
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
	}

	ll sum(int l, int r, int x, int lx, int rx){
		if(lx>=l && rx<=r) return sums[x];
		if(lx>=r || rx<=l) return 0;
		int m=(lx+rx)/2;
		ll s1=sum(l, r, 2*x+1, lx, m);
		ll s2=sum(l, r, 2*x+2, m, rx);
		return s1+s2;
	}

	ll sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
};

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
  // cout << "here"<<endl;

  rep(i, 1, m){
  	int op;
  	cin >> op;
  	if(op==1){
  		cin >> u >> v;
  		st.set(u, v);
  	}
  	else {
  		cin >> l >> r;
  		cout << st.sum(l, r) << endl;
  	}
  }
}