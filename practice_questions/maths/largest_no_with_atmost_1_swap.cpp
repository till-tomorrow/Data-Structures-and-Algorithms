// Program to input a number (number of digits <= 10^6), Find out largest number possible by making atmost 1 swap operation

#include <bits/stdc++.h>
using namespace std;

int main(){
	char num[1000005];
	int i,j,k,l,n,m;
	scanf("%s",num);
	l = strlen(num);

	int dp[l+2];
	for(i=0;i<=l;i++){
		dp[i] = -1;
	}

	int last_index[10];
	for(i=0;i<10;i++) 	last_index[i] = -1;

	last_index[num[l-1]-'0'] = l-1;

	for(i=l-2;i>=0;i--){
		int ans = -1;

		if(last_index[num[i]-'0'] == -1){
			last_index[num[i]-'0'] = i;
		}

		for(k=9; k > num[i]-'0'; k--){
			if(last_index[k] == -1)
				continue;
			ans = last_index[k];
			break;
		}

		dp[i] = ans;
	}

	for(i=0;i<l;i++){
		if(dp[i] != -1){
			char tmp = num[i];
			num[i] = num[dp[i]];
			num[dp[i]] = tmp;
			break;
		}
	}

	printf("%s\n",num);
}