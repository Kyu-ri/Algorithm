#include<stdio.h>

/*선택정렬
void SelectionSort(int arr[], int n) {
	int min, temp;
	for (int i = 0; i<n - 1; i++) {
		min = i;
		for (int j = i + 1; j<n; j++) {
			if (arr[j] < arr[min]) min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
*/

/*버블정렬
void BubbleSort(int arr[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
}
*/

//삽입정렬
void InsertSort(int arr[], int n) {
	int i, j, key;
	for (i = 0; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}


}

void main() {

	int arr[5] = { 34, 10, 24, 7, 26 };
	int n = 5;
	//SelectionSort(arr, n);
	//BubbleSort(arr, n);
	InsertSort(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d\t", arr[i]);

	return 0;
}


/*****MergeSort﻿*****/

#include<stdio.h>

void merge(int A[], int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	int tmp[8];
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) tmp[k++] = A[i++];
		else tmp[k++] = A[j++];
	}
	while (i <= q) tmp[k++] = A[i++];
	while (j <= r) tmp[k++] = A[j++];
	for (int a = p; a <= r; a++) A[a] = tmp[a];
}

void mergeSort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int A[8] = { 8,27,36,5,16,92,3,9 }, i;
	printf("정렬 전\n");
	for (i = 0; i < 8; i++) {
		printf("%d \t", A[i]);
	}
	mergeSort(A, 0, 7);
	printf("\n정렬 후\n");
	for (i = 0; i < 8; i++) {
		printf("%d \t", A[i]);
	}
	return 0;
}

﻿/******Quick Sort******/

#include <stdio.h>
#include <stdlib.h>

int compare(void* first, void* second) {
	if (*(int*)first > * (int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
}

int main() {
	int A[] = { 8,27,36,5,16,92,3,9 };
	int size = sizeof(A) / sizeof(int);
	int i;

	qsort(A, size, sizeof(int), compare);

	printf("정렬 후 값 : \n");
	for (i = 0; i < size; i++) printf("%d\t ", A[i]);
	return 0;
}

﻿

/*******Heap Sort********/

#include <stdio.h>

#define parent(x) (x-1)/2

void buildheap(int* A, int num) {
	for (int i = 1; i < num; i++) {
		int child = i;
		while (child > 0) {
			int root = parent(child);
			if (A[root] < A[child]) {
				int temp = A[root];
				A[root] = A[child];
				A[child] = temp;
			}
			child = root;
		}
	}
}


int main(void) {

	int num = 9;
	int A[] = { 8,27,36,5,16,92,3,9,10 }, i;
	printf("정렬 전\n");
	for (int i = 0; i < 8; i++) {
		printf("%d \t", A[i]);
	}
	buildheap(A, num);
	for (int i = num - 1; i >= 0; i--) { // heapSort 부분
		int temp = A[i];
		A[i] = A[0];
		A[0] = temp;

		buildheap(A, i);
	}
	printf("\n정렬 후\n");
	for (int i = 0; i < 8; i++) {
		printf("%d \t", A[i]);
	}
	return 0;
}