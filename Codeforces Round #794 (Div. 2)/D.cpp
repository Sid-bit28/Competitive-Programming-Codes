#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
typedef long long lli;         typedef long double ld;
typedef pair<lli,lli> pii;     typedef vector<lli> vi;
typedef vector<pii> vii;       typedef vector<vi> graph;
const long long MOD=1000000007;const long long INF=1e18;
#ifndef SIDDARTH
#define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
#else
#define pr(...) {}
#define debarr(a,n) {}
#define debmat(mat,row,col) {}
#endif
lli binpow(lli b,lli p,lli mod=MOD){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void pre(){

}
void solve(){
	vi a(4);
	fr(i,4)cin>>a[i];
	string s;
	cin>>s;
	int n=sz(s);
	vi marked(n,0);
	fr(i,n){
		if(i+1<n&&s[i]=='A'&&s[i+1]=='A'&&a[0]){
			marked[i]=1;
			a[0]--;
		}else if(i+1<n&&s[i]=='B'&&s[i+1]=='B'&&a[1]){
			marked[i]=1;
			a[1]--;
		}
	}
	string naya;
	fr(i,n){
		if(!marked[i])naya.push_back(s[i]);
	}
	pr(naya);
	auto b=a;
	n=sz(naya);
	marked.assign(n,0);
	vi marked1(n,0);
	fr(i,n){
		if(i+1<n&&naya[i]=='A'&&naya[i+1]=='B'&&a[3]){
			marked[i]=1;
			marked[i+1]=1;
			a[3]--;
			i++;
		}else if(i+1<n&&naya[i]=='B'&&naya[i+1]=='A'&&a[4]){
			marked[i]=1;
			marked[i+1]=1;
			a[4]--;
			i++;
		}
	}
	fr(i,n){
		if(!marked[i]&&naya[i]=='B'){
			a[1]--;
		}else if(!marked[i]&&naya[i]=='A'){
			a[0]--;
		}
	}
	int cnt=0;
	fr(i,sz(a)){
		if(a[i]==0)cnt++;
	}
	bool ok=false;
	if(cnt==sz(a)){
		ok=true;
	}
	fr(i,n){
		if(i+1<n&&naya[i]=='B'&&naya[i+1]=='A'&&b[4]){
			marked1[i]=1;
			marked1[i+1]=1;
			b[4]--;
			i++;
		}else if(i+1<n&&naya[i]=='A'&&naya[i+1]=='B'&&b[3]){
			marked1[i]=1;
			marked1[i+1]=1;
			b[3]--;
			i++;
		}
	}
	fr(i,n){
		if(!marked1[i]&&naya[i]=='B'){
			b[1]--;
		}else if(!marked1[i]&&naya[i]=='A'){
			b[0]--;
		}
	}
	cnt=0;
	fr(i,sz(b)){
		if(b[i]==0)cnt++;
	}
	if(cnt==sz(b)){
		ok=true;
	}
	if(ok){
		cout<<"YES"<<endl;
	}else cout<<"NO";
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	pre();lli _t=1;cin>>_t;
	for(lli i=1;i<=_t;i++){
        //cout<<"Case #"<<i<<": ";
		solve();
	}
}