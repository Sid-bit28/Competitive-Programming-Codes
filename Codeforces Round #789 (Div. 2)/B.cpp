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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<int,char>> v;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            v.push_back({cnt,s[i-1]});
            cnt=1;
        }else cnt++;
    }
    v.push_back({cnt,s[n-1]});
    for(int i=0;i<sz(v)-1;i++){
        if(v[i].F%2){
            v[i].F++;
            v[i+1].F--;
        }
    }
    string temp="";
    fr(i,sz(v)){
        fr(j,v[i].F){
            temp+=v[i].S;
        }
    }
    lli ans=0;
    fr(i,n){
        if(s[i]!=temp[i])ans++;
    }
    cout<<ans<<endl;
    vi arr;
    cnt=1;
    for(int i=1;i<sz(s);i++){
        if(s[i]==s[i-1])cnt++;
        else {
            arr.push_back(cnt);
            cnt=1;
        }
    }
    arr.push_back(cnt);
    pr(arr);
    int k=ans;
    vii a,b;
    for(int i=0;i<sz(arr);i+=2){
        a.push_back({arr[i],i});
    }
    for(int i=1;i<sz(arr);i+=2){
        b.push_back({arr[i],i});
    }
    sort(all(a));
    sort(all(b));
    map<lli,bool> mp;
    for(auto x:a){
        if(x.F>k)break;
        k-=x.F;
        mp[x.S]=true;
    }
    int cnt1=0;
    int sub=0;
    for(int i=0;i<sz(arr);i+=2){
        if(mp[i])cnt1++;
        else {
            sub+=(2*cnt1+1);
            cnt1=0;
        }
    }
    if(sub==0)sub+=(2*cnt1+1);
    pr(mp);
    pr(sub);
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