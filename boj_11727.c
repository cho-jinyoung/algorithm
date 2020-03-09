// 2020-03-08 BOJ_11727
// DP
// 2xN 타일링2  
// 2×n 크기의 직사각형을 2×1, 2x2 타일로 채우는 방법의 수를 10,007로 나눈 나머지 출력 

// f(n)의 값을 구하고자 할 때
// ⅰ)2x2타일 하나로 2x2칸을 채우고 나머지 n-2칸을 채우는 경우 > f(n-2)
// ⅱ)1x2타일 두개로 2x2칸을 채우고 나머지 n-2칸을 채우는 경우 > f(n-2)
// ⅲ)2x1타일 하나로 2x1칸을 채우고 나머지 n-1칸을 채우는 경우 > f(n-1)
// f(n)=f(n-1)+f(n-2)*2

#include<stdio.h>

int main(){
	int input, i, tile[1001];
	
	scanf("%d", &input);
	
	tile[0]=tile[1]=1;
	
	for(i=2;i<=input;i++)
		tile[i]=(tile[i-1]+tile[i-2]*2)%10007;
	printf("%d", tile[input]);
}
