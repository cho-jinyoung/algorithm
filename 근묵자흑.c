// 2020-03-11 소마 테스트문제
// 단순구현
// 근묵자흑
// 길이 N의 수열에서 연속된 K개의 정수를 이 정수들 중 가장 작은 수로 만들고자 할 때 최소 몇번 골라야 하는지
// 2<=N<=100000, 2<=K<=N
// 첫번째 줄에는 N,K값을 두번째 줄 에는 공백으로 구분된 N개의 정수를 입력받음
// 출력으로는 모두 같은 수를 만들고자 할 때 골라야 하는 최소 횟수

// N과 K값에만 집중하여 총 N개를 바꾸고자 할 때 몇번을 움직여야 하는지 생각(두번째 줄의 입력은 의미가 없다고 생각)
// 첫번째는 N개중 K개를 바꿀 수 있고 그 이후부터는 K-1개를 바꿀 수 있음 
#include <stdio.h>

int main(){
	int n, k, arr, i, count=0;
	
	scanf("%d %d",&n, &k);
	
	for(i=0;i<n;i++)
		scanf("%d", &arr);		
	
	n=n-k;
	while(n>0){
		n=n-(k-1);
		count++;
	}
	printf("%d", count+1);
	
	return 0;
}
