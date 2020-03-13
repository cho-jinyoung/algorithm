// 2020-03-13 BOJ_1912
// DP
// 연속합 
// n개의 정수로 이루어진 임의의 수열에서 연속된 몇 개의 수를 선택해 구할 수 있는 합 중 가장 큰 합
// ex) {10, -4, 3, 1, 5, 6, -35, 12, 21, -1} 정답은 12+21인 33
// 첫째줄에 정수 N (1 ≤N ≤100,000), 둘째 줄에 n개의 정수로 이루어진 수열 (-1,000 ≤a ≤1,000)입력

// dp[i]=dp[i-1]+a[i]이 현재 값 보다 작으면 현재값부터 다시 연속값을 진행하는 방식
#include<stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	int input, a[100000], i, j, dp[100000]={}, big=0;
	
	scanf("%d", &input);
	
	for(i=0;i<input;i++)
		scanf("%d", &a[i]);
		
	big=dp[0]=a[0];
	
	for(i=0;i<input;i++)
		dp[i]=MAX(dp[i-1]+a[i], a[i]); 
	
	for(i=0;i<input;i++)
		big=MAX(big, dp[i]);
	printf("%d", big);
}

// 시간초과 코드  > dp를 사용하지 않음  

/*#include<stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

int main(){
	int input, a[100000], i, j, dp[100000]={},sum=0, big=0;
	
	scanf("%d", &input);
	
	for(i=0;i<input;i++)
		scanf("%d", &a[i]);
	big=a[0];		
	for(i=0;i<input;i++){
		sum=a[i];
		for(j=i+1;j<input;j++){
			sum=sum+a[j];
			big=MAX(big, sum);		
		}
		dp[i]=big;
	}
	for(i=0;i<input;i++)
		big=MAX(big, dp[i]);
	printf("%d", big);
} */
