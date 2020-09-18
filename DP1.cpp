#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//Memoizatation
int memo[100000];
int fib(int n){
	int res;
	if(memo[n]==-1){
		if(n==0|| n==1)return n;
		else return res=fib(n-1)+fib(n-2);
		memo[n]=res;
	}
	return memo[n];
}
//Tabulation
int fib2(int n){
	int dp[n+1];
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

// 0/1 knapsack problem
int knapsack(int wt[],int val[],int sum,int n){
	if(n==0|| sum==0)return 0;
	if(wt[n-1]>sum){
		return knapsack(wt,val,sum,n-1);
	}
	else
	    return max(val[n-1]+knapsack(wt,val,sum-wt[n-1],n-1),knapsack(wt,val,sum,n-1));
}
// memo
int dp[10001][10001];
int knapsackdp1(int wt[],int val[],int sum,int n){
	dp[n+1][sum+1];
	memset(dp,-1,sizeof(dp));
	if(n==0|| sum==0){
		dp[n][sum]=0;
	}
	if(dp[n][sum]!=-1) return dp[n][sum];
	else{
		if(wt[n-1]>sum){
			dp[n][sum]=knapsackdp1(wt,val,sum,n-1);
			return dp[n][sum];
		}
		else
			dp[n][sum]=max(val[n-1]+knapsackdp1(wt,val,sum-val[n-1],n-1),knapsackdp1(wt,val,sum,n-1));

	}

	return dp[n][sum];		
}
// Bottom up
int knapsackdp2(int wt[],int val[],int sum,int n){
	//1.Build table
	int dp[n+1][sum+1];
	//2.Approach
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0||j==0)dp[i][j]=0;
			else if(wt[i-1]<=j){
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	//3.Return
	return dp[n][sum];
}
//Subset sum problem
 //1.Recursive
int subsetsum(int a[],int n,int sum){
	if(n==0)return 0;
	if(sum==0)return 1;
	if(a[0]==sum)return 1;
	if(a[n-1]>sum){
		return subsetsum(a,n-1,sum);
	}
	else
		return subsetsum(a,n-1,sum-a[n-1]) or subsetsum(a,n-1,sum);
}
 //2.Memoizatation
int dpsum[10001][10001];
int subsetdp1(int a[],int n,int sum){
	dpsum[n+1][sum+1];
	if(n==0)return 0;
	if(sum==0)return 1;
	if(a[0]==sum) return 1;
	if(a[n-1]>sum){
		dpsum[n][sum]=subsetdp1(a,n-1,sum);
	}else{
		dpsum[n][sum]=subsetdp1(a,n-1,sum-a[n-1]);
	}
	return dpsum[n][sum];
}
//3.Bottom up
int subsetdp2(int a[],int n,int sum){
	int dpsum1[n+1][sum+1];
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=0;i<=sum;i++)dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]>j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
			}
		}
	}
	return dp[n][sum];
}
//Equal sum partition
int equalsum(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++)sum+=a[i];
	if(sum%2)return 0;
	else 
		return subsetdp2(a,n,sum/2);
}
int main(){
	OJ;
	FIO;
	/*
	memset(memo, -1, sizeof(memo));
	ll sum;
	cin>>sum;
	cout<<fib2(n);
	*/

	/*
	int n;cin>>n;
	int val[n],wt[n];
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	int W;cin>>W;
	cout<<knapsackdp2(wt,val,W,n);
	*/
	/*
	int n;cin>>n;
	int sum;cin>>sum;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<subsetsum(a,n,sum);
	cout<<subsetdp1(a,n,sum);
	cout<<subsetdp2(a,n,sum);
	*/
	/*
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	cout<<equalsum(a,n);
	*/
}