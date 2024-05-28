#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct array{
	int arr;
	int size;
	
}st_ar;

void *sort_array(void *param){
	st_ar *ptr=(st_ar *)param;
	int i,j;
	for(i=0;i<(ptr->size-1);i++){
		for(j =0;j<((ptr->size)-i-1);j++){
			if((ptr->arr[i])>(ptr->arr[i+1])){
				int temp =ptr->arr[i];
				ptr->arr[i]=ptr->arr[i+1];
				ptr->arr[i+1] = temp;
			}
		}
	}
	
	return (void *)arr;
}

int main(){
	pthread_t t;
	int *sort;
	st_ar ar ={(11,22,9,2,1,3,4,5),8};
	pthread_create(&t,NULL,sort_array,&ar);
	pthread_join(t,(void **)&sort);

	printf("sort result: \n");
	for(int i=0;i<10;i++){
		printf("%d ",sort[i]);

	}
	free(sort);
	return 0;
}
