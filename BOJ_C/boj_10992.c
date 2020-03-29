// 2020-03-07 BOJ_10992 
// 가운데가 빈 트리모양 별 찍기 

#include<stdio.h>

int main(){
    int n, i, j, k, in=1;
    scanf("%d", &n);
    for (i=1;i<=n;i++){
    	//마지막 줄
    	if (i==n)
    		for(j=0;j<n*2-1;j++)
    			printf("*");
		else{
			for(j=0;j<n-i;j++)
				printf(" ");
			printf("*");
			//첫번째 줄 외
			if(i!=1){
				for(k=0;k<in;k++)
					printf(" ");
				printf("*");
				in=in+2;
			}
    		printf("\n");			
		}
	}
}
