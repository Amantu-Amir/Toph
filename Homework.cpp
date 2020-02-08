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
void solve(string str, int n, int index, string curr){ 
	if (index == n) 
		return; 
	v.push_back(curr); //cout<<curr<<"\n";
	for (int i=index+1; i<n; i++) { 
		curr += str[i]; 
		solve(str, n, i, curr); 
		curr = curr.erase(curr.size()-1); 
	} 
	return; 
} 

bool isPerfect(int n){
	int a = sqrt(n);
	if((a*a)==n) return true;
	else return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int tc; cin>>tc;
	for(int T=1; T<=tc; T++){
		v.clear();
		string s, s2 = ""; cin>>s;
		int len = s.length();
		
		solve(s, s.size(), -1, s2);
		
		int vl = v.size(), res = -1, ok = 0;
		for(int i=0; i<vl; i++){
			int aa = toInt(v[i]);
			if(isPerfect(aa) and aa != 0){
				string s = v[i];
				int idx = 0;
				while(s[idx]=='0') idx++;
				ok = 1; int aa = s.length()-idx;
				res = max(res,aa);
			}
		}
		if(!ok) cout<<"-1\n";
		else cout<<len-res<<"\n";
	}
	return 0;
}
