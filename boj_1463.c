//2020-03-07 BOJ_1463
//DP(Dynamic Programming)
//1로 만들기 
//정수 x에 사용할 수 있는 연산은 
//x가 3으로 나누어 떨어지면 3으로 나눈다, 2로 나누어 떨어지면 2로 나눈다, 1을 뺀다 
//정수 N을 위와 같은 세개의 연산을 적절히 활용하여 1로 만들고자 할 때 연산을 사용하는 횟수의 최솟값? 

//num을 1로 만드는 최소횟수=num(-1 or /3 or /2)을 1로 만드는 최소횟수+1

#include<stdio.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y)) 

//int num[1000000]; => main함수 안에서 10^6이 오버플로우를 발생하는 경우가 있음
int main(){
	//num=입력된 숫자에 해당하는 연산최소횟수를 담는 배열
	int input, i, num[1000000];
	
	scanf("%d", &input);
	
	num[1]=0;
	for(i=2;i<=input;i++){
	//-1을 한것과 나누기연산을 한 것중 더 작은 횟수인것을 선택 
		num[i]=num[i-1]+1;	 
		if(i%3==0)
			num[i]=MIN(num[i], num[i/3]+1);
		if(i%2==0)
			num[i]=MIN(num[i], num[i/2]+1);
	}	
	printf("%d", num[input]); 
} 
