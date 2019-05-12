//#define num 3
//#define mun 3 
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <malloc.h>
//
//typedef enum Mode { First, Second, Third }mode;
//
//void keyboard(int **arr, int N, int M)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			printf_s("Введие %d элемент %d стоки:", j + 1, i + 1);
//			scanf_s("%d", &arr[i][j]);
//		}
//	}
//}
//
//void key2(int *a, int n, int m)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf_s("a[%d][%d] = ", i + 1, j + 1);
//			scanf_s("%d", (a + i * m + j));
//		}
//	}
//}
//
//void output(int **arr, int N, int M)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//			printf_s("%5d ", arr[i][j]);
//		printf_s("\n");
//	}
//}
//
//void out2(int *a, int n, int m)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			printf("%5d ", *(a + i * m + j));
//		printf("\n");
//	}
//}
//
//void calc2(int *a, int n, int m)
//{
//	int A, B,number;
//
//	printf("Введите диапозон от A до B:");
//	scanf_s("%d%d", &A, &B);
//	int *sum = (int*)calloc(m, sizeof(int)), max;
//	for (int j = 0; j < m; j++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (*(a + i * m + j) < A || *(a + i * m + j) > B)
//			{
//				sum[j] += *(a + i * m + j);
//				printf("%d\n", *(a + i * m + j));
//			}
//			
//		}
//	}
//	max = sum[0];
//	for (int i = 1; i < m; i++)
//	{
//			max += sum[i];
//	}
//	free(sum);
//	printf_s(" сумма не входящая в область :%d\n", max);
//}
//
//void calc(int **arr, int N, int M)
//{
//	int A, B;
//	printf("Введите диапозон от A до B:");
//	scanf_s("%d%d",&A,&B);
//	int *sum = (int*)calloc(M, sizeof(int)), m;
//	for (int j = 0; j < M; j++)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (arr[j][i] < A || arr[j][i] > B)
//			{
//				sum[j] += arr[j][i];
//				printf("%d\n", arr[j][i]);
//			}
//				
//		}
//	}
//	m = sum[0];
//	for (int i = 1; i < M; i++)
//	{
//			m+= sum[i];
//	}
//
//	free(sum);
//	printf_s(" сумма не входящая в область :%d\n", m);
//}
//void calc3(int **arr, int N, int M)
//{
//	int A, B;
//	printf("Введите диапозон от A до B:");
//	scanf_s("%d%d", &A, &B);
//	int*sum = (int*)calloc(M, sizeof(int)), m;
//	for (int j = 0; j < M; j++)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (arr[j][i] < A || arr[j][i] > B)
//			{
//				sum[j] += arr[j][i];
//				printf("%d\n", arr[j][i]);
//			}
//
//		}
//	}
//	m = sum[0];
//	for (int i = 1; i < M; i++)
//	{
//		m += sum[i];
//	}
//
//	free(sum);
//	printf_s(" сумма не входящая в область :%d\n", m);
//}
//
//
//int main(void)
//{
//	int	sw, **ARR = NULL, N, M, *a = NULL;
//	
//	mode	m;
//	setlocale(LC_ALL, "Rus");
//	printf_s("Выберите метод инициализации (1 или 2 или 3):");
//	scanf_s("%d", &sw);
//	if ( sw == 3)
//	{
//		printf_s("Введите кол-во строк:");
//		scanf_s("%d", &N);
//		
//	}
//	int *p[mun];
//		if (sw == 1)
//		{
//			m = First;
//			ARR = (int**)malloc(num * sizeof(int*));
//			for (int i = 0; i < num; i++)
//				ARR[i] = (int*)malloc(mun * sizeof(int));
//		}
//		else if (sw == 2)
//		{
//			m = Second;
//			ARR = (int**)malloc(num * sizeof(int*) + num * mun * sizeof(int));
//			int *start = (int*)((char*)ARR + num * sizeof(int*));
//			for (int i = 0; i < num; i++)
//				ARR[i] = start + i * mun;
//		}
//		else
//		{
//			m = Third;
//			a = (int*)malloc(N*M * sizeof(int));
//		}
//
//		if (m != Third)
//		{
//			keyboard(ARR, num, mun);
//			printf_s("\n");
//			output(ARR, num, mun);
//
//			calc(ARR, num, mun);
//		}
//		else
//		{
//			key2(a, N, M);
//			printf_s("\n");
//			out2(a, N, M);
//			calc2(a, N, M);
//		}
//
//		if (m == First)
//		{
//			for (int i = 0; i < num; i++)
//				free(ARR[i]);
//			free(ARR);
//		}
//		else if (m == Second)
//			free(ARR);
//		else
//			free(a);
//	system("pause");
//	return 0;
//}