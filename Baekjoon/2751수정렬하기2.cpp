#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// 중간 지점을 계산한다.
		mid = (left + right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}
int arr[1000000];
int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		scanf("%d", &arr[i]);

	MergeSort(arr, 0, t-1);

	for (int i = 0; i < t; i++)
		printf("%d\n", arr[i]);
	return 0;
}