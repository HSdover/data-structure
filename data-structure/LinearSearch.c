#include <stdio.h>

// 순차 탐색 알고리즘 적용된 함수
// 맨 위에서 맨 아래까지 순차
int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;	// 찾은 대상의 인덱스 값 반환
	}

	return -1;	// 찾기 못했음을 의미하는 값 반환
}

// 이진 탐색
// 배열에 저장된 데이터는 정렬돼있어야한다.
int BSearch(int ar[], int len, int target)
{
	int first = 0;			// 탐색 대상의 시작 인덱스 값
	int last = len - 1;		// 탐색 대상의 마지막 인덱스 값
	int mid;
	int opCount = 0;	// 비교연산의 횟수를 기록

	while (first <= last)
	{
		mid = (first + last) / 2;	// 탐색 대상의 중앙을 찾는다.

		if (target == ar[mid])	// 중앙에 저장된 것이 타겟이라면
		{
			return mid;			// 탐색 완료!
		}
		else                    // 타겟이 아니라면 탐색 대상을 반으로 줄인다.
		{
			if (target < ar[mid])
				last = mid - 1;		// 왜 -1을 하였을까? mid의 값은 이미 확인 완료
			else
				first = mid + 1;	// 왜 +1을 하였을까? mid의 값은 이미 확인 완료
		}
		opCount += 1;	// 비교연산의 횟수 1 증가
	}
	printf("(BSWorstOpCount)비교연산횟수: %d \n", opCount);
	return -1;		// 찾지 못했을 때 반환되는 값 -1
}

int searchCase = 3;
int main(void)
{
	int idx;

	if (searchCase == 0) {
		// 순차 탐색
		int arr[] = { 3, 5, 2, 4, 9 };

		idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);

		idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);
	}
	else if (searchCase == 1) {
		// 이진 탐색
		int arr[] = { 1, 3, 5, 7, 9 };

		idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d  \n", idx);

		idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
		if (idx == -1)
			printf("탐색 실패 \n");
		else
			printf("타겟 저장 인덱스: %d  \n", idx);
	}
	else if (searchCase == 3) {
		// BSWorstOpCOunt
		int arr1[500] = { 0, };		// 모든 요소 0으로 초기화
		int arr2[5000] = { 0, };	// 모든 요소 0으로 초기화
		int arr3[50000] = { 0, };	// 모든 요소 0으로 초기화
		
		// 배열 arr1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
		idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
		if (idx == -1)
			printf("탐색실패 \n\n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);

		// 배열 arr2을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
		idx = BSearch(arr1, sizeof(arr2) / sizeof(int), 1);
		if (idx == -1)
			printf("탐색실패 \n\n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);

		// 배열 arr3을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
		idx = BSearch(arr1, sizeof(arr3) / sizeof(int), 1);
		if (idx == -1)
			printf("탐색실패 \n\n");
		else
			printf("타겟 저장 인덱스: %d \n", idx);

	}
	return 0;
}