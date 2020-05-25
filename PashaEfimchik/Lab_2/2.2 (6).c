//IDE: VisualStudio
//Task 2.2(6)
/*
Численно убедиться в справедливости равенства, для чего для заданного значения х вычислить его левую часть и разложение, 
стоящее в правой части. При каком n исследуемое выражение отличается от sin x менее, чем на заданную погрешность E? 
Испытать разложение на сходимость при разных значениях х.
*/
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <time.h>


double fact(double x)
{
	if (x <= 0)
	{
		return 1;
	}
	return x * fact(x - 1);
}

int recursion(double x, double E, int n, double right)
{
	double D = 2 * n - 1;
	right += (pow(-1, (n - 1)) * pow(x, 2 * n - 1)) / fact(D);
	if (fabs(sin(x) - right) < E)
	{
		return n;
	}
	return recursion(x, E, n += 1, right);
}

int iterative(double x, double e)
{
	int n = 1;
	double result = 0;
	double D;
	do
	{
		D = 2 * n - 1;
		result += (pow(-1, n - 1) * pow(x, 2 * n - 1)) / fact(D);
		n++;
	} while (fabs(sin(x) - result) >= e);
	return n;
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	double x, E, result = 0;
	clock_t startTime, endTime;
	printf("Введите x: ");
	scanf_s("%lf", &x);
	printf("Введите погрешность: ");
	scanf_s("%lf", &E);
	int n = 1;

	startTime = clock();
	int RecursCount = recursion(x, E, n, result);
	endTime = clock();
	printf("\n1. Способ.\nРекурсивно:\n");
	printf("Количество членов N = %d\n", RecursCount);
	printf("Время работы: %lf секунд\n", (double)(endTime - startTime) / clock());

	startTime = clock();
	int IterCount = iterative(x, E);
	endTime = clock();
	double time = (double)(endTime - startTime) / clock();
	printf("\n2. Способ\nИтеративно:\n");
	printf("Количество членов N = %d\n", IterCount);
	printf("Время работы: %lf секунд\n", (double)(endTime - startTime) / clock());
}
