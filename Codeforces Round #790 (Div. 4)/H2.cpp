#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> oset;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    oset s;
	unordered_map<long long,long long> mp;
	s.insert(arr[n-1]);
	mp[arr[n-1]]++;
	long long ans=0;
    for(int i=n-2;i>=0;i--){
    	ans+=s.order_of_key(arr[i]);
    	ans+=mp[arr[i]];
    	s.insert(arr[i]);
    	mp[arr[i]]++;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}