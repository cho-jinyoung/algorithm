// 2020-03-08 BOJ_9095,15988
// DP
// N을 1, 2, 3의 합으로 나타내는 방법의 수  (합을 나타낼 때는 수를 1개 이상 사용)
// 첫번째 입력=테스트 케이스의 개수 T 각 테스트 케이스 n은 양수이며 11보다 작다
// 각 테스트 케이스마다 1, 2, 3의 합으로 나타내는 방법의 수를 출력 

// n=5인 경우 n=4인 경우에+1, n=3인 경우에+2, n=2인 경우에+3인 것과 같으므로 
// (n이 3이상일때) f(n)=f(n-1)+f(n-2)+f(n-3)

#include<stdio.h> 
#define MOD 1000000009

int main(){
	//오버플로우가 발생할 수 있기 때문에 long long형으로 선언  
	long long T, output[1000001], n[1000001], i, j, input;
	n[1]=1;	n[2]=2;	n[3]=4;	

	scanf("%d", &T);
			
	for(i=0;i<T;i++){
		scanf("%d", &input);
		for(j=4;j<=input;j++)
			n[j]=(n[j-1]+n[j-2]+n[j-3])%MOD;
		output[i]=n[input];
	}
	for(i=0;i<T;i++)
		printf("%d\n", output[i]);	
}
