#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main(){
    int n,x,y;
    cin>>n; int ver=0,hor=0;
    set<double>st;
    for(int i=1; i<=n; i++){
        cin>>x>>y;
        if(x==0) ver++;
        if(y==0) hor++;
        double slope = (float)y/x;
        st.insert(slope);
    }
    int siz = st.size();
    int ans = max(siz,max(ver,hor));
    cout<<ans<<"\n";
    return 0;
}
