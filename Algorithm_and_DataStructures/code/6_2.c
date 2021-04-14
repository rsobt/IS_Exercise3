#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

void swap(int i, int j, int* A) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	return;
}

/*グループ分割する関数*/
int separateGroup(int* array, int i, int j, int a) {
	int l = i, r = j;
	while (array[l] < a)
		l++;
	while (array[r] >= a)
		r--;
	while (l <= r) {
		swap(l, r, array);
		l++;
		r--;
		while (array[l] < a)
			l++;
		while (array[r] >= a)
			r--;
	}
	return(l);
}

/*クイックソートする関数*/
void quickSort(int* array, int start, int end) {
	int i = start, j = end;
	if (i >= j)
		return;
	int a;
	if (array[i] > array[i + 1]) {
		a = array[i];
	}
	else {
		a = array[i + 1];
	}
	int k = separateGroup(array, i, j, a);
	quickSort(array, i, k - 1);
	quickSort(array, k, j);
	return;
}





/*ヒープソートする関数*/
void heapSort(int* array, int start, int end) {

}

int main() {
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int i;
	for(i =0; i<n;i++)
		scanf("%d", &array[i]);
	quickSort(array, 0, n - 1);
	printArray(array, n);
	return 0;
}