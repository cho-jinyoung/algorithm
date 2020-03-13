// 2020-03-12 BOJ_11053
// DP
// 가장 긴 증가하는 부분 수열(LIS)
// ex) 수열 A = {10, 20, 10, 30, 20, 60} 경우 
// 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 60} 이고, 길이는 4 => 4출력  
// 첫째줄에 A의 크기 N (1 ≤ N ≤ 1,000), 둘째 줄에 수열 A를 이루고 있는 Ai (1 ≤ Ai ≤ 1,000)입력  

// dp=현재 인덱스보다 작은 인덱스 중 가장 큰 dp값+1
// 가장 마지막 배열값의 dp수를 구하고 전체 dp값을 비교하여 가장 큰 값 찾기   
#include<stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	int input, a[1000], i, j, dp[1000]={}, big_max=0;
	
	scanf("%d", &input);
	
	for(i=0;i<input;i++)
		scanf("%d", &a[i]);

	dp[0]=1;
	
	for(i=0;i<input;i++){
		big_max=0;			// 가장 큰 dp값 저장  
		for(j=0;j<i;j++) 	// 현재 배열값(i)의 dp를 구하기 위해
			if(a[i]>a[j])	// 현재(가장 마지막)배열의 값과 앞의 배열값 비교    
				big_max=MAX(dp[j], big_max);									
		dp[i]=big_max+1;	// 현재값 포함  
	}		
	for(i=0;i<input;i++)
		big_max=MAX(dp[i], big_max);	// 각 자리 수열의 dp값 중 가장 큰 수 찾기  
	
	printf("%d", big_max);	
} 

// cf) 다른 풀이 방법: O(N log N) 알고리즘
