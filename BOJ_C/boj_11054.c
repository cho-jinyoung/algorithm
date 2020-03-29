// 2020-03-17 BOJ_11054
// DP
// 가장 긴 바이토닉 부분 수열
// 바이토닉 수열 = 수열 S가 어떤 수 Sk 기준 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족
// 첫째 줄에 수열 A의 크기 N, 둘째 줄엔 A를 이루고 있는 Ai가 주어짐(1 ≤N ≤1,000, 1 ≤Ai ≤1,000)
// 수열 A의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이 > 출력  

// i를 기준으로 0번째 배열에서 증가하는 수열 + 맨 마지막번째에서 왼쪽으로 증가하는 수열 

#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	int input, i, j, big=0, a[1000], up[1000]={}, down[1000]={}, dp[1000]={};
	
	scanf("%d", &input);
	
	for(i=0;i<input;i++)
		scanf("%d", &a[i]);
		
	up[0]=1;	down[input]=1;	
		
	for(i=1;i<input;i++){
		big=0;	
		for(j=0;j<i;j++){
			if(a[i]>a[j])
				big=MAX(up[j], big);
		}
		up[i]=big+1;
	}
	for(i=input-1;i>=0;i--){
		big=0;
		for(j=input-1;j>i;j--){
			if(a[i]>a[j])
				big=MAX(down[j], big);
		}		
		down[i]=big+1;					
	}
	for(i=0;i<input;i++){
		dp[i]=up[i]+down[i]-1;	
		big=MAX(big, dp[i]);			
	}
	printf("%d", big);
} 
