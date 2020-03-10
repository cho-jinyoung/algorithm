// 2020-03-10 BOJ_11057
// DP
// 오르막수=자리가 오름차순을 이루는 수, 인접한 수가 같아도 오름차순으로 침 
// ex) 2234,36778(o) 2232,3676,911(x)
// 수의 길이 N이 주어졌을 때 오르막 수의 개수를 10,007로 나눈 나머지? (수는 0으로 시작할 수 있음) 

#include <stdio.h>
#define MOD 10007

int main(){
	// 배열 초기화! > n[k][i]가 첫번째로 더해질 때 쓰레기값이 들어있음  
	int input, i, j, k, n[1001][10]={}, sum=0;
	
	scanf("%d", &input);
	
	for(i=0;i<10;i++)
		n[1][i]=1;	
	for(k=2;k<=input;k++)
		for(i=0;i<10;i++)
			for(j=i;j<10;j++)
				n[k][i]=(n[k][i]+n[k-1][j])%MOD;						
	for(k=0;k<10;k++)
		sum=(sum+n[input][k])%MOD;	
	
	printf("%d", sum);
} 
