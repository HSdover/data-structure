#include <stdio.h>

// ���� Ž�� �˰��� ����� �Լ�
// �� ������ �� �Ʒ����� ����
int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;	// ã�� ����� �ε��� �� ��ȯ
	}

	return -1;	// ã�� �������� �ǹ��ϴ� �� ��ȯ
}

// ���� Ž��
// �迭�� ����� �����ʹ� ���ĵ��־���Ѵ�.
int BSearch(int ar[], int len, int target)
{
	int first = 0;			// Ž�� ����� ���� �ε��� ��
	int last = len - 1;		// Ž�� ����� ������ �ε��� ��
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;	// Ž�� ����� �߾��� ã�´�.

		if (target == ar[mid])	// �߾ӿ� ����� ���� Ÿ���̶��
		{
			return mid;			// Ž�� �Ϸ�!
		}
		else                    // Ÿ���� �ƴ϶�� Ž�� ����� ������ ���δ�.
		{
			if (target < ar[mid])
				last = mid - 1;		// �� -1�� �Ͽ�����? mid�� ���� �̹� Ȯ�� �Ϸ�
			else
				first = mid + 1;	// �� +1�� �Ͽ�����? mid�� ���� �̹� Ȯ�� �Ϸ�
		}
		printf(" first = %d \n", first);
		printf(" last = %d \n", last);
	}
	return -1;		// ã�� ������ �� ��ȯ�Ǵ� �� -1
}

int main(void)
{
	int searchCase = 1;
	int idx;

	if (searchCase == 0) {
		// ���� Ž��
		int arr[] = { 3, 5, 2, 4, 9 };

		idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
		if (idx == -1)
			printf("Ž�� ���� \n");
		else
			printf("Ÿ�� ���� �ε���: %d \n", idx);

		idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
		if (idx == -1)
			printf("Ž�� ���� \n");
		else
			printf("Ÿ�� ���� �ε���: %d \n", idx);
	}
	else if (searchCase == 1) {
		// ���� Ž��
		int arr[] = { 1, 3, 5, 7, 9 };

		idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
		if (idx == -1)
			printf("Ž�� ���� \n");
		else
			printf("Ÿ�� ���� �ε���: %d  \n", idx);

		idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
		if (idx == -1)
			printf("Ž�� ���� \n");
		else
			printf("Ÿ�� ���� �ε���: %d  \n", idx);
	}
	return 0;
}