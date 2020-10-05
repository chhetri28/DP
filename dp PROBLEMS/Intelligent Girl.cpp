// Intelligent Girl 
#include<bits/stdc++.h>
#define ll long long
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<int>solve(vector<int>a){
    int n=a.size()-1;
    vector<int>dp(n+1,0);
    if(!(a[n]&1))dp[n]=1;
    for(int i=n-1;i>=0;i--){
        if(a[i]&1)dp[i]=dp[i+1];
        else dp[i]=1+dp[i+1];
    }
    return dp;
}
int main(){
   // OJ;
    FIO;
	string s;
	cin>>s;
	vector<int>a;
	for(int i=0;s[i];i++){
		int k=s[i]-'0';
        a.push_back(k);
	}
	vector<int>res=solve(a);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}