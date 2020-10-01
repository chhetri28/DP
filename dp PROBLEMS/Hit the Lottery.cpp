#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// ll solve(int *a,int n,ll sum){
// 	ll dp[sum+1];
// 	dp[0]=0;
// 	for(ll i=1;i<=sum;i++){
// 		dp[i]=INT_MAX;
// 	}
// 	for(ll i=1;i<=sum;i++){
// 		for(ll j=0;j<n;j++){
// 			if(a[j]<=i){
// 				ll sub_res=dp[i-a[j]];
// 				if(sub_res!=INT_MAX){
// 					dp[i]=min(dp[i],sub_res+1);
// 				}
// 			}
// 		}
// 	}
// 	return dp[sum];
// }
int main(){
	// OJ;
	// FIO;
	ll sum;
	cin>>sum;
	// int a[5]={1,5,10,20,100};
	// cout<<solve(a,5,sum);
	/*
    Greedy Approach
    int m=0;
	if(sum/100){
		m+=(sum/100);
		sum-=(sum/100)*100;
	}
	if(sum/20){
		m+=(sum/20);
		sum-=(sum/20)*20;
	}
	if(sum/10){
		m+=(sum/10);
		sum-=(sum/10)*10;
	}
	if(sum/5){
		m+=(sum/5);
		sum-=(sum/5)*5;
	}
	m+=sum;
	cout<<m;
    */
}