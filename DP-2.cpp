#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//1.Recursive
int lcs(string s1,string s2,int n,int m){
	if(n==0||m==0)return 0;
	if(s1[n-1]==s2[m-1])return 1+lcs(s1,s2,n-1,m-1);
	else 
		return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));

}
//2.Top-down
int lcsdp[1001][1001];
int lcs2(string s1,string s2,int n,int m){
	lcsdp[n+1][m+1];
	memset(lcsdp,-1,sizeof(lcsdp));
	if(n==0||m==0)lcsdp[n][m]=0;
	if(lcsdp[n][m]!=-1){
		return lcsdp[n][m];
	}else{
		if(s1[n-1]==s2[m-1])lcsdp[n][m]=1+lcs2(s1,s2,n-1,m-1);
		else
			lcsdp[n][m]=max(lcs2(s1,s2,n-1,m),lcs2(s1,s2,n,m-1));
	}

	return lcsdp[n][m];	
}
//4.Bottom-up approach
int lcs3(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	return lcsdp[n][m];
}
//5.Print LCS
string lcsprint(string s1,string s2,int n,int m){

	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	string res="";
	int i=n,j=m;
	while(i>0 and j>0){
		if(s1[i-1]==s2[j-1]){
			res.push_back(s1[i-1]);
			i--,j--;
		}
		else{
			if(lcsdp[i][j-1]>lcsdp[i-1][j])j--;
			else i--;
		}
	}
	return res;
}
//Longest Common substring 
//1.Recursive
int longestcommonsubstring(string s1,string s2,int n,int m,int c){
	if(n==0||m==0)return c;
	if(s1[n-1]==s2[m-1])
	c=longestcommonsubstring(s1,s2,n-1,m-1,c+1);
	else
		c=max(c,max(longestcommonsubstring(s1,s2,n-1,m,0),longestcommonsubstring(s1,s2,n,m-1,0)));
	return c;	
}
//2.TopDown
int t[1001][1001];
int longestcommonsubstringdp(string s1,string s2,int n,int m,int c){
	t[n+1][m+1];
	if(n==0||m==0)t[n][m]=0;
	else if(s1[n-1]==s2[m-1]){
		t[n][m]=longestcommonsubstringdp(s1,s2,n-1,m-1,c+1);
	}
	else{
		t[n][m]=max(c,max(longestcommonsubstringdp(s1,s2,n-1,m,0),longestcommonsubstring(s1,s2,n,m-1,0)));
	}
	return t[n][m];

}
//3.Bottom-up
int lcommonsubstringdp2(string s1,string s2,int n,int m){
	int t[n+1][m+1];
	int res=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)t[i][j]=0;
			else if(s1[i-1]==s2[j-1]){
				t[i][j]=1+t[i-1][j-1];
				res=max(res,t[i][j]);
			}
			else{
				t[i][j]=0;
			}
		}
	}
	return res;
}
//Shortest Common SuperSequence
int scsdp(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	return n+m-lcsdp[n][m];
}
void printscs(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	string res="";
	int i=n,j=m;
	while(i>0 || j>0){
		if(s1[i-1]==s2[j-1]){
			res.push_back(s1[i-1]);
			i--,j--;
		}
		else{
			if(lcsdp[i][j-1]>lcsdp[i-1][j]){
				res.push_back(s2[j-1]);
				j--;
			}
			else{
				res.push_back(s1[i-1]);
				i--;
			}
		}
	}
	while(i--){
		res.push_back(s1[i-1]);
		i--;
	}
	while(j--){
		res.push_back(s2[j-1]);
		j--; 
	}
	cout<<res;
}

// Minimum Number of Insertion and Deletion to convert String a to String b
void minindel(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	int del=n-lcsdp[n][m];
	int in=m-lcsdp[n][m];
	cout<<"Deletion: "<<del<<" Interstion: "<<in;
}
//  Longest Palindromic Subsequence
int lps(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	return lcsdp[n][m];
}
// Minimum number of deletion in a string to make it a palindrome
int mindelinlps(string s1,string s2,int n,int m){
	int res=0;
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
			lcsdp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}
			else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	res=n-lcsdp[n][m];
	return res;
}
//  Longest repeating subsequence
int lrs(string s,int n){
	int lrsdp[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			lrsdp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==s[j-1] and i!=j){
				lrsdp[i][j]=1+lrsdp[i-1][j-1];
			}else{
				lrsdp[i][j]=max(lrsdp[i-1][j],lrsdp[i][j-1]);
			}
		}
	}
	return lrsdp[n][n];
}
//  Sequence Pattern Matching
bool spm(string s1,string s2,int n,int m){
	int lcsdp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0){
				lcsdp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				lcsdp[i][j]=1+lcsdp[i-1][j-1];
			}else{
				lcsdp[i][j]=max(lcsdp[i-1][j],lcsdp[i][j-1]);
			}
		}
	}
	return lcsdp[n][m];
	if(lcsdp[n][m]==n){
		return true;
	}
	else
	    return false;
}
int main(){
	OJ;
	FIO;
	string s1,s2;
	cin>>s1>>s2;
	// int j=0;
	// for(int i=s1.size()-1;i>=0;i--){
	// 	s2.push_back(s1[i]);
	// }
	int n=s1.size();
	// cout<<lrs(s1,n);
	int m=s2.size();
	cout<<spm(s1,s2,n,m);
	// printscs(s1,s2,n,m);
	// cout<<mindelinlps(s1,s2,n,m);
	//cout<<lps(s1,s2,n,m);
	// minindel(s1,s2,n,m);
	// cout<<scsdp(s1,s2,n,m);
	// string res=lcsprint(s1,s2,n,m);
	// reverse(res.begin(),res.end());
	// cout<<res;
	//cout<<lcs3(s1,s2,n,m);
	//cout<<lcommonsubstringdp2(s1,s2,n,m);
}