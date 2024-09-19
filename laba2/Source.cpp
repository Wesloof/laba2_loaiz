#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int size_m = 100000;
int a[size_m];

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "RUS");
	int i = 0, j = 0, r;
	
	cout << "–азмер массива " << size_m << endl;
	
	clock_t start, end;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size_m / 2)
	{
		a[i] = rand() % size_m + 1; // заполн€ем массив случайными числами
		i++;
	}
	//while (i < size_m / 2)
	//{
	//	a[i] = i; // заполн€ем массив случайными числами
	//	i++;
	//}

	//while (i < size_m)
	//{
	//	a[i] = size_m - i; // заполн€ем массив случайными числами
	//	i++;
	//}

	start = clock();
	int n = sizeof(a) / sizeof(a[0]);

	qsort(a, n, sizeof(int), compare);
	double time = 0.0;
	end = clock();
	time += (double)(end - start) / CLOCKS_PER_SEC;
	cout << time;
	return(0);
}
