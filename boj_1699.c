// 2020-03-22 BOJ_1699
// DP
// 제곱수의 합 = 어떤 자연수 N을 그보다 작거나 같은 제곱수의 합으로 나타낼 수 있는 수의 개수  
// Ex) 11=32+12+12(3개항), =22+22+12+12+12(5개항) > 출력 3 
// 자연수 N (1 ≤N ≤100,000)입력, 제곱수 항의 최소 개수 출력
 
// dp[n]=n보다 작거나 같은 제곱수의 합으로 나타낼 수 있는 수의 최소값 
// 현재 dp[n]값보다 dp[n-(n보다 작은 제곱수)]+1의 값이 더 작으면 dp[i]값 바꿈 

#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
 
int main(){
	int input, dp[100001]={};
	long j, i;
	
	scanf("%d", &input);
	
	dp[1]=1;
	
	for(i=2;i<=input;i++){
		dp[i]=i;
		for(j=1;j<i;j++)
			if(j*j<=i)
				dp[i]=min(dp[i], dp[i-j*j]+1);					
	}
	printf("%d", dp[input]);
}
