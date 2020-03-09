// 2020-03-10 BOJ_10844
// DP
// 계단 수=인접한 모든 자리수의 차이가 1
// N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지(1<=N<=100, 0으로 시작하는 수는 없다)
// 정답을 1,000,000,000으로 나눈 나머지 출력

// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
// 길이 , 마지막 숫자가 j일 경우  

#include<stdio.h>
#define MOD 1000000000
 
int main(){
	int input, i, j;
	long long num[101][10], count=0;
	
	scanf("%d", &input);	// input=계단수의 길이 	

	num[1][0]=0;			// 1의자리수이고 0으로 끝나는 수의 개수  
	for(i=1;i<10;i++)
		num[1][i]=1;
		
	if(input!=1){	
		count=0;	
		for(i=2;i<=input;i++){
			num[i][0]=num[i-1][1];
			num[i][9]=num[i-1][8];
			for(j=1;j<9;j++)
				num[i][j]=(num[i-1][j-1])%MOD+(num[i-1][j+1])%MOD;
		}		
	}
	// count=count+num[input][j]%MOD 라고 하면 틀린 이유
	// +보다%연산이 우선시되므로 num[input][j]%MOD이후에 count에 값이 더해지게 된다	
	// 그러면 count값이 계속 증가해 long long범위를 벗어나 오버플로우가 발생 함  
	for(j=0;j<10;j++)
		count=(count+num[input][j])%MOD;
	printf("%d", count);
} 
