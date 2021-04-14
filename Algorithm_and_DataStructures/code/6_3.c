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

/*グループ分割する関数*/
int separateGroup(int* array, int i, int j, int a) {
	int l = i, r = j;
	while (array[l] < a)
		l++;
	while (array[r] >= a)
		r--;
	while (l <= r) {
		int temp;
		temp = array[l];
		array[l] = array[r];
		array[r] = temp;
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
	int a = array[i];
	int k = separateGroup(array, i, j, a);
	quickSort(array, i, k - 1);
	quickSort(array, k, j);
	return;
}



void swap(int i, int j, int *A) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	return;
}

void downmax(int i, int* array, int n) {
	int j;
	j = 2 * i + 1;
	if (j >= n) return;
	if (j + 1 < n && array[j] < array[j + 1])j++;
	if (array[j] > array[i]) {
		swap(i, j, array);
		downmax(j, array, n);
	}
	return;
}

void heapify(int* array, int n) {
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		downmax(i, array, n);
}

int deletemax(int* array, int n) {
	int max = array[0];
	array[0] = array[n - 1];
	downmax(0, array, n - 1);
	return(max);
}

/*ヒープソートする関数*/
void heapSort(int* array, int n) {
	int i;
	heapify(array, n);
	for (i = n - 1; i > 0; i--)
		array[i] = deletemax(array, i + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	int i;
	for(i =0; i<n;i++)
		scanf("%d", &array[i]);
	heapSort(array, n);
	printArray(array, n);
	return 0;
}