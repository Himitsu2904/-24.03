#include <iostream>
using namespace std;

//5. Функции для работы с динамическим массивом:

//a. функция распределения динамической памяти
void create(int** arr, int size)
{
	*arr = new int[size];
}

//b. функция инициализации динамического массива
void initialize(int** arr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		(*arr)[i] = rand() % 21 - 10;
	}
}

//c. функция печати динамического массива
void print(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << (*arr)[i] << "\t";
	}
	cout << endl;
}

//d. удаления динамического массива
void deleting(int** arr)
{
	delete[](*arr);
}

//e. функция добавления элемента в конец массива
void add(int** arr, int size, int **mass)
{
	*mass = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		(*mass)[i] = (*arr)[i];
	}
	srand(time(0));
	(*mass)[size] = rand() % 11;
}

//f. функция вставки элемента по указанному индексу
void ind_paste(int** arr, int size, int ind, int element, int** mass2)
{
	*mass2 = new int[size + 1];
	int n = 0;
	for (int i = 0; i <= size; i++)
	{
		if (i != ind)
		{
			(*mass2)[i] = (*arr)[n];
			n++;
		}
		else
		{
			(*mass2)[i] = element;
		}
	}
}

//g. функция удаления элемента по указанному индексу
void delete_element(int** ARR, int size, int** mass, int ind)
{
	int n = 0;
	for (int i = 0; i <= size; i++)
	{
		if (i != ind)
		{
			(*ARR)[n] = (*mass)[i];
			n++;
		}
	}
}

/*15. Написать функцию, которая получает указатель на статический массив и его размер. Функция
распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.*/
void  plus_minus_zero(int stat[], int size, int** plus_m, int** minus_m, int** zero_m)
{
	int plus = 0, minus = 0, zero = 0;
	for (int i = 0; i < size; i++)
	{
		if (stat[i] > 0)
		{
			plus++;
		}
		else if (stat[i] < 0)
		{
			minus++;
		}
		else
		{
			zero++;
		}
	}
	*plus_m = new int[plus];
	*minus_m = new int[minus];
	*zero_m = new int[zero];
	int n1 = 0, n2 = 0, n3 = 0;
	for (int i = 0; i < 10; i++)
	{
		if (stat[i] > 0)
		{
			(*plus_m)[n1]=stat[i];
			n1++;
		}
		else if (stat[i] < 0)
		{
			(*minus_m)[n2] = stat[i];
			n2++;
		}
		else
		{
			(*zero_m)[n3] = stat[i];
			n3++;
		}
	}
	cout << "\nМассив положительных елементов:\n";
	print(&(*plus_m), plus);
	cout << "Массив отрицательных елементов:\n";
	print(&(*minus_m), minus);
	cout << "Массив нулевых елементов:\n";
	print(&(*zero_m), zero);
}

//11. Создать функцию, позволяющую добавлять блок элементов в конец массива.
void add_block(int** arr, int size, int** arr_b)
{
	cout << "Введите размер блока: ";
	int size_b;
	cin >> size_b;
	int* block = new int[size_b];
	cout << "Добавляемый блок:\n";
	initialize(&block, size_b);
	print(&block, size_b);
	*arr_b = new int[size + size_b];
	for (int i = 0; i < size; i++)
	{
		(*arr_b)[i] = (*arr)[i];
	}
	for (int i = size, n = 0; n < size_b; i++, n++)
	{
		(*arr_b)[i] = block[n];
	}
	cout << "Массив с добавленным блоком:\n";
	print(&(*arr_b), size + size_b);
	
	deleting(&block);
}

//12. Создать функцию, позволяющую вставлять блок элементов, начиная с произвольного индекса массива.
void add_block_rand(int** arr, int size, int** arr_b)
{
	cout << "Введите размер блока: ";
	int size_b;
	cin >> size_b;
	int* block = new int[size_b];
	cout << "Добавляемый блок:\n";
	initialize(&block, size_b);
	print(&block, size_b);
	*arr_b = new int[size + size_b];
	srand(time(0));
	int index;
	index = rand() % size;
	cout << "Произвольный индекс: " << index << "\n";
	for (int i = 0; i < index; i++)
	{
		(*arr_b)[i] = (*arr)[i];
	}
	for (int i = index, n = 0; n < size_b; i++, n++)
	{
		(*arr_b)[i] = block[n];
	}
	for (int i = index + size_b, ind = index; i < size + size_b; i++, ind++)
	{
		(*arr_b)[i] = (*arr)[ind];
	}
	cout << "Массив с произвольно вставленным блоком:\n";
	print(&(*arr_b), size + size_b);

	deleting(&block);
}
//13. Создать функцию, позволяющую удалять блок элементов, начиная с произвольного индекса массива.
void delete_block_rand(int** arr, int size, int** arr_b)
{
	srand(time(0));
	int size_b;
	size_b = rand() % size;
	cout << "Pазмер блока: " << size_b;
	*arr_b = new int[size - size_b];
	int index;
	index = rand() % (size - size_b);
	cout << "\nПроизвольный индекс: " << index << "\n";
	for (int i = 0; i < index; i++)
	{
		(*arr_b)[i] = (*arr)[i];
	}
	for (int i = index + size_b, n = index; i < size + size_b; i++, n++)
	{
		(*arr_b)[n] = (*arr)[i];
	}
	cout << "Массив с произвольно удалённым блоком:\n";
	print(&(*arr_b), size - size_b);
}

int main()
{
	setlocale(0, "ru");
	int* arr = nullptr;
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	cout << "Массив:\n";
	create(&arr, size);
	initialize(&arr, size);
	print(&arr, size);
	
	int* mass = nullptr;
	add(&arr, size, &mass);
	cout << "Массив с добавленным элементом:\n";
	print(&mass, (size + 1));
	
	int* mass2 = nullptr;
	cout << "Введите индекс: ";
	int ind;
	cin >> ind;
	while (ind<0 || ind>size)
	{
		cout << "Некорректный индекс.";
		cin >> ind;
	}
	cout << "Введите значение элемента: ";
	int element;
	cin >> element;
	cout << "Массив после добавления элемента: ";
	ind_paste(&arr, size, ind, element, &mass2);
	print(&mass2, size + 1);
	
	cout << "Массив после удаления элемента:\n";
	int* ARR = nullptr;
	create(&ARR, size);
	delete_element(&ARR, size, &mass, ind);
	print(&ARR,size);
	
	cout << "\n---------------------------------------------------------\n";
	
	int stat[10] = { 1,-9,0,11,32,-65,23,0,-13,99 };
	cout << "Статический массив:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << stat[i] << "\t";
	}
	int* plus_m = nullptr;
	int* minus_m = nullptr;
	int* zero_m = nullptr;
	plus_minus_zero(&stat[0], 10, &plus_m, &minus_m, &zero_m);

	cout << "----- Вставка блока элементов -----\n";
	int* arr_b = nullptr;
	add_block(&arr, size, &arr_b);
	cout << "----- Вставка блока элементов с произвольного индекса массива -----\n";
	add_block_rand(&arr, size, &arr_b);
	cout << "----- Удаление блока элементов с произвольного индекса массива -----\n";
	delete_block_rand(&arr, size, &arr_b);

	deleting(&arr);
	deleting(&mass);
	deleting(&mass2);
	deleting(&ARR);
	deleting(&plus_m);
	deleting(&minus_m);
	deleting(&zero_m);
	deleting(&arr_b);
}