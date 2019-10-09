#include <iostream>
#include <stdio.h>
#include <assert.h>

int posMinArr(int* arr, int L, int& min, int step);
void scanfArr(int* arr, int n);
void printStr(int* arr, int n);
void printMatrix(int* arr, int n, int m);
void minStr(int* arr, int n, int L, int* minArr, int step);
//void minMatrixStr(int* arr, int n, int L, int* minArr, int* minMatrix);

int main()
{
	int n = 0;
	int L = 0;
	scanf("%d%d", &n, &L);

	int* arr = new int[n * n];
	scanfArr(arr, n * n);

	int szm = n - L + 1;
	int* min_str = new int[szm * n];
	for (int i = 0; i < n; ++i)
		minStr(arr + i * n, n, L, min_str + i * szm, 1);

	int* min_matrix = new int[szm * szm];

	for (int i = 0; i < szm; ++i) {
		minStr(min_str + i, n, L, min_matrix + i, szm);
	}

	//printMatrix(min_str, szm, n);
	//printf("\n\n");
	printMatrix(min_matrix, szm, szm);
	//printMatrix(min, n - L, n - L);

    return 0;
}

/*void minMatrixStr(int n, int L, int* minArr, int* minMatrix) {
	for (int i = 0; i < n - L + 1; ++i) {
		minMatrix[i] = posMinArr(minArr, L, min)
	}
}*/

void minStr(int* arr, int n, int L, int* minArr, int step) {
	/*for (int i = 0; i < n; ++i)
		printf("%d ", arr[i * step]);
	printf("\n");*/
	int min = 0;
	int pos = posMinArr(arr, L, min, step);
	minArr[0] = min;

	for (int i = 1; i < n - L + 1; ++i) {
		if (pos >= i) {
			if (min < arr[(i + L - 1) * step]) {
				minArr[i * step] = min;
				//printf("1| %d, %d, %d\n", min, i, pos);
			}
			else {
				pos = i + L - 1;
				min = arr[(i + L - 1) * step];
				minArr[i * step] = min;
				//printf("2| %d, %d, %d\n", min, i, pos);
			}
		}
		else {
			pos = i + posMinArr(arr + i * step, L, min, step);
			minArr[i * step] = min;
			//printf("3| %d, %d, %d\n", min, i, pos);
		}
	}
}

/*void minStr(int* arr, int n, int L, int* minArr) {
	int pos = 0;
	int     min = 0;
	int num_min = 0;
	
	for (int i = 0; i < n - L + 1; ++i) {
		if (pos > i) minArr[i] = min;
		else {
			pos = pos + posMinArr(arr + pos, L, min);
			minArr[i] = min;
		}
	}
}*/

int posMinArr(int* arr, int L, int& min, int step) {
	min = arr[0];
	int pos = 0;
	for (int i = 1; i < L; i++) {
		if (arr[i * step] < min) {
			min = arr[i * step];
			pos = i;
		}
	}
	//printf("%d: %d\n", pos, min);
	return pos;
}

void scanfArr(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}

void printStr(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}

void printMatrix(int* arr, int n, int m) {
	for (int i = 0; i < m; ++i) {
		printStr(arr + i * n, n);
		printf("\n");
	}
}