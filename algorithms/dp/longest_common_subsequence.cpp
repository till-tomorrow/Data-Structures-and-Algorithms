#include <bits/stdc++.h>
using namespace std;

int main(){
	char s1[1005], s2[1005];
	int i,j,k,l,n,m,t;

	scanf("%s",s1);
	scanf("%s",s2);

	int l1 = strlen(s1);
	int l2 = strlen(s2);

	int dp[l1+1][l2+1];
	for(i=0;i<=l1;i++){
		for(j=0;j<=l2;j++){
			dp[i][j] = 0;
		}
	}

	for(i=0;i<=l1;i++){
		for(j=0;j<=l2;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout<<dp[l1][l2]<<endl;
}
