#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
void *sort_array(void *param){
	int *arr=(int *)param;
	int i,j;
	int *sorted_arr =(int *)malloc(40);
	int min=arr[0];

	for (int i = 0; i < 10; i++) {
		sorted_arr[i] = arr[i];
	}

	for (int i = 0; i < 9; i++) {
		int min_index = i;
		for (int j = i + 1; j < 10; j++) {
			if (sorted_arr[j] < sorted_arr[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			int temp = sorted_arr[i];
			sorted_arr[i] = sorted_arr[min_index];
			sorted_arr[min_index] = temp;
		}

	}
	
	return (void *)sorted_arr;
}

int main(){
	pthread_t t;
	int *sort;
	int arr[10] ={5,6,7,8,9,10,1,2,3,4};
	pthread_create(&t,NULL,sort_array,arr);
	pthread_join(t,(void **)&sort);

	printf("sort result: \n");
	for(int i=0;i<10;i++){
		printf("%d ",sort[i]);

	}
	free(sort);
	return 0;
}
