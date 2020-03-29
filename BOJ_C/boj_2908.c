//2020-03-06 BOJ_2908
//숫자를 거꾸로 읽었을 때 더 큰수를 출력
//Ex)734, 893 => 437과 398로 읽어, 437출력  


#include <stdio.h>

int main(){
	int input_1, input_2, one, two, i, max, output[3];
	
	scanf("%d %d", &input_1, &input_2);
	
	one=input_1;
	two=input_2;
	
	while(1){
		if(one%10>two%10){
			max=input_1;
			break;
		}
		else if(one%10<two%10){
			max=input_2;
			break;
		}
		else{
			one=one/10;
			two=two/10;
		}
	}
//숫자를 거꾸로 출력하기 위해
	for(i=0;i<3;i++){
		output[i]=max%10;
		max=max/10;
		printf("%d", output[i]);	
	}
}
