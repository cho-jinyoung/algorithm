//2020-03-06 BOJ_1065
//한수 (1000보다 작거나 같은 자연수 N) 

#include<stdio.h>

int main(){
	int input, i, num[4], n=0, count=0, k;
	
	scanf("%d", &input);
	
	for(i=1;i<=input;i++){
		if(i<100)	count++;			
		else if(i==1000)	break; 
		else{
			n=0;
			k=i;
			while(k>0){
				num[n]=k%10;
				k=k/10;
				n++;
			}
			if((num[1]-num[0])==(num[2]-num[1]))
				count++;
		}
	}
	printf("%d", count);	
} 
