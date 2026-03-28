#include <stdio.h>

int main()
{
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
		if(i%2==0){
			if(j%2==0){
				printf("#");
			}else{
				printf(" ");
			}
		}else{
			if(j%2==0){
				printf(" ");
			}else{
				printf("#");
			}
		}
		}
		printf("\n");
	}
	return 0;
}
