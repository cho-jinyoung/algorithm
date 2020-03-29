// 2020-03-12 BOJ_2156
// DP
// 포도주 시식 
// n개의 포도주 잔에는 각 다른 양의 포도주가 들어있고 이 중 하나를 선택하면 모두 마시고 원래 위치에 둠  
// 연속으로 놓여있는 3잔을 모두 마실 순 없음, 최대로 마실 수 있는 포도주의 양은? 
// 첫째줄에 포도주 잔의 개수 1≤n≤10,000 / 둘째줄부터 각 잔의 포도주 양(1,000 이하의 음이 아닌 정수) 입력 

// 맨 뒤의 잔(n)을 기준으로 3가지 경우 중 가장 큰 수를 찾으면 됨 
// ⅰ) n잔(맨뒤), n-1잔, n-3번째의 잔을 포함한 이후의 경우(dp[n-3])
// ⅱ) n잔, n-2잔이후의 경우(dp[n-2])
// ⅲ) n-1잔이후의 경우 
#include<stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	//wine, dp배열은 1부터 입력함  
	int input, wine[10000], dp[10000]={}, i;
	
	scanf("%d", &input);
	
	for(i=1;i<=input;i++)
		scanf("%d", &wine[i]);

	dp[0]=0;	
	dp[1]=wine[1];
	dp[2]=wine[1]+wine[2];

	for(i=3;i<=input;i++)
		dp[i]=MAX(wine[i]+wine[i-1]+dp[i-3], MAX(wine[i]+dp[i-2],dp[i-1]));
	
	printf("%d", dp[input]);
} 
