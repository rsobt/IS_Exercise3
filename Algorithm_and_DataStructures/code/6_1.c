#include<stdio.h>
#include<stdlib.h>

/*配列を出力する関数*/
void printArray(int* array, int size) {
	int i;
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return;
}

/*バブルソートする関数*/
void bubbleSort(int* array, int start, int end) {
	int i = start;
	int flag = 1;
	while (flag == 1) {
		flag = 0;
		for (int j = end; j > i; j--) {
			if (array[j - 1] > array[j]) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				flag = 1;
			}
		}
		i++;
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int i;
	for(i =0; i<n;i++)
		scanf("%d", &array[i]);
	bubbleSort(array, 0, n - 1);
	printArray(array, n);
	return 0;
}