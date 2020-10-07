// Problems related to Unbounded knapsack
#include<bits/stdc++.h>
#define ll long long
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int  unbounded(int wt[],int val[],int sum,int n){
   //1.Build table
	int dp[n+1][sum+1];
	//2.Approach
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0||j==0)dp[i][j]=0;
			else if(wt[i-1]<=j){
				dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	//3.Return
	return dp[n][sum];
}
//Rod cutting
int maxicuts(int len[],int price[],int n){
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)dp[i][j]=0;
            else if(len[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}
int maxicoins(int a[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i][j-a[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int minicoins(int a[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=INT_MAX-1;
            }
            if(j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int j=1;j<sum+1;j++){
            if(j%a[0]==0){
                dp[1][j]=j/a[0];
            }
            else{
                dp[1][j]=INT_MAX-1;
            }
        }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-a[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<sum+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[n][sum];
}
int main(){
    OJ;
    FIO;
    return 0;
}
//inputs for rod cutting
/*
 int l;
    cin>>l;
    int len[l];
    for(int i=0;i<l;i++){
        len[i]=i+1;
    }
    int price[l];
    for(int i=0;i<l;i++){
        cin>>price[i];
    }
   cout<<maxicuts(len,price,l);
   
*/
// inputs for Unbounded
/*
    int n;
    cin>>n;
	int val[n],wt[n];
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	int W;
    cin>>W;
	cout<<unbounded(wt,val,W,n);
    */
   //inputs for mini and maxi coin change
   /*
   int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    cout<<minicoins(a,n,sum);
   */