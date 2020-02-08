#include<bits/stdc++.h>
#define int long long int
using namespace std;

int toInt(string s){
	stringstream ss;
	ss<<s;
	int n; ss>>n;
	return n;
}

vector<string>v;
void solve(string str, int n){
	v.clear();
	for(int i=0; i<(1<<n); i++){
		string s;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				s+=str[j];
			}
		}
		v.push_back(s);
	}
	/*int l = v.size();
	cout<<l<<"\n";
	for(int i=1; i<l; i++){
        cout<<v[i]<<"\n";
	}*/
}

bool isPerfect(int n){
	int a = sqrt(n);
	if((a*a)==n) return true;
	else return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	int tc; cin>>tc;
	for(int T=1; T<=tc; T++){
		string s; cin>>s;
		int len = s.length();
		solve(s, len);
        int vl = v.size(), ok = 0, res = -1;
        for(int i=1; i<vl; i++){
            int val = toInt(v[i]);
            if(isPerfect(val)){
                string s = v[i];
                int aa = s.length();
                int idx = 0; ok = 1;
                while(s[idx]=='0') idx++;
                res = max(res, aa-idx);
            }
        }
        if(!ok) cout<<"-1\n";
        else cout<<len-res<<"\n";
	}
	return 0;
}
