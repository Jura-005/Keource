//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <locale.h>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int *a; // ��������� �� ������
//	int i, j, n, m;
//	printf("������� ���������� �����: ");
//	scanf_s("%d", &n);
//	printf("������� ���������� ��������: ");
//	scanf_s("%d", &m);
//	// ��������� ������
//	a = (int*)malloc(n*m * sizeof(int));
//	// ���� ��������� �������
//	for (i = 0; i < n; i++) // ���� �� �������
//	{
//		for (j = 0; j < m; j++) // ���� �� ��������
//		{
//			printf("a[%d][%d] = ", i, j);
//			scanf_s("%d", (a + i * m + j));
//		}
//	}
//	// ����� ��������� �������
//	for (i = 0; i < n; i++) // ���� �� �������
//	{
//		for (j = 0; j < m; j++) // ���� �� ��������
//		{
//			printf("%5d ", *(a + i * m + j)); // 5 ��������� ��� ������� �������
//		}
//		printf("\n");
//	}
//	free(a);
//	getchar();
//	return 0;
//}