#include<bits/stdc++.h>
using namespace std;

const int mxN=2e7+10;
vector<int> p(mxN,1);
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p[0]=p[1]=0;
    for(int i=2;i<=mxN;i++){
    	if(p[i]){
    		for(int j=2*i;j<=mxN;j+=i){
    			p[j]=0;
    		}
    	}
    }
    map<long long,pair<long long,long long>> mp;
    long long cnt=1;
    for(int i=1;i<mxN-1;i++){
    	if(p[i]&&p[i+2]){
    		mp[cnt]={i,i+2};
    		cnt++;
    	}
    }
    int in;
    while(cin>>in){
    	cout<<"("<<mp[in].first<<", "<<mp[in].second<<")"<<endl;
    }
}