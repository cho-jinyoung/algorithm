// 2020-03-08 BOJ_11726
// DP
// 2xN타일링
// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 10,007로 나눈 나머지 출력  

#include <stdio.h>
// 1,2,3,5,8,..>피보나치 수열과 같은 방식  
int main(){
	int i, j, input, tile[1001];
	
	scanf("%d", &input);
	tile[0]=tile[1]=1;
	
	for(i=1;i<=input;i++)
	//나중에 출력에서 %10007을 하면 for문 안에서 overflow가 발생할 수 있기 때문에 계산할 때마다 %10007을 해줌   
		tile[i+1]=(tile[i-1]+tile[i])%10007;		
	printf("%d", tile[input]); 
}
