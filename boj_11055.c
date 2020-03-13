// 2020-03-13 BOJ_11055
// DP
// 가장 큰 증가 부분 수열(LIS)
// 수열 A의 증가 부분 수열 중에서 합이 가장 큰 것
// Ex) 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우
// 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8}, 합은 113 > 합 출력  
// 첫째줄에 A의 크기 N (1 ≤ N ≤ 1,000), 둘째 줄에 수열 A를 이루고 있는 Ai (1 ≤ Ai ≤ 1,000)입력

#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	// dp=증가 부분 수열의 합 중 가장 큰 값   
	int input, a[1000], i, j, dp[1000]={}, big_max=0;
	
	scanf("%d", &input);
	
	for(i=0;i<input;i++)
		scanf("%d", &a[i]);
	
	dp[0]=a[0];

	for(i=1;i<input;i++){
		big_max=0;
		for(j=0;j<i;j++){
			if(a[i]>a[j])
				big_max=MAX(dp[j]+a[i], big_max);
			else	// 만약 현재 위치 앞의 배열에 현재의 값보다 작은게 현재 값 혼자 가장 큰 부분수열이 되거나 앞의 최대값이 유지됨  
				big_max=MAX(a[i], big_max);
		}
		dp[i]=big_max;		
	} 
	for(i=0;i<input;i++)
		big_max=MAX(big_max, dp[i]);		
	printf("%d", big_max);
}  
