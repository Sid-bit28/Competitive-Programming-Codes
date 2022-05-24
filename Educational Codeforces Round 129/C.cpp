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
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void pre(){

}
void solve(){
	lli n;
	cin>>n;
	vi arr(n),brr(n);
	fr(i,n)cin>>arr[i];
	fr(i,n)cin>>brr[i];
	multiset<pii> m1,m2,mm;
	fr(i,n){
		m1.insert({arr[i],brr[i]});
	}
	mm=m1;
	auto a=arr;
	auto b=brr;
	sort(all(a));
	sort(all(b));
	fr(i,n){
		m2.insert({a[i],b[i]});
	}
	if(m1!=m2){
		cout<<"-1"<<endl;
		return;
	}
	vii v1,v2;
	fr(i,n){
		v1.push_back({arr[i],brr[i]});
	}
	fr(i,n){
		v2.push_back({a[i],b[i]});
	}
	map<pii,set<int>> mp;
	map<lli,pii> mp1,mp2;
	fr(i,n){
		mp1[i]={arr[i],brr[i]};
	}
	fr(i,n){
		mp2[i]={a[i],b[i]};
	}
	fr(i,n){
		mp[{arr[i],brr[i]}].insert(i);
	}
	vii ans;
	for(int i=0;i<n;i++){
		auto chahiye=mp2[i];
		auto hai=mp1[i];
		if(chahiye==hai){
			mp[chahiye].erase(i);
			mp[hai].erase(i);
			continue;
		}
		int pos=*mp[chahiye].rbegin();
		ans.push_back({i,pos});
		mp[hai].erase(i);
		mp[chahiye].erase(pos);
		mp[hai].insert(pos);
		mp[chahiye].insert(i);
		mp1[i]=chahiye;
		mp1[pos]=hai;
	}
	cout<<sz(ans)<<endl;
	for(auto x:ans){
		cout<<x.F+1<<" "<<x.S+1<<endl;
	}
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