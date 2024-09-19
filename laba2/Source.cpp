#include <iostream>
#include <ctime>

using namespace std;

const int size_m = 4000;
int a[size_m][size_m], b[size_m][size_m], c[size_m][size_m], elem_c;

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "RUS");
	int i = 0, j = 0, r;
	
	cout << "Размер массива " << size_m << endl;
	
	clock_t start, end;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size_m)
	{
		while (j < size_m)
		{
			a[i][j] = rand() % size_m + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < size_m)
	{
		while (j < size_m)
		{
			b[i][j] = rand() % size_m + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	start = clock();
	for (i = 0; i < size_m; i++)
	{
		for (j = 0; j < size_m; j++)
		{
			elem_c = 0;
			for (r = 0; r < size_m; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	double time = 0.0;
	end = clock();
	time += (double)(end - start) / CLOCKS_PER_SEC;
	cout << time;
	return(0);
}
