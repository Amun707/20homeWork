#include <iostream>
#include <ctime>
#include <cstdlib>

//Задача1.Заполнение массива.
template<typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

//Задача2. Вывод массива в консоль.
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}

//Задача3.Возврат индекса первого вхождения в массив.
template<typename T>
int search_index(T arr[], const int length, int value, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

//Задача4. Возврат индекса последнего вхождения элемента в массив.
template<typename T>
int search_last_index(T arr[], const int length, int value) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == value)
			return i;
	return -1;
}
template<typename T>
int search_last_index(T arr[], const int length, int value, int begin) {
	for (int i = begin; i >= 0; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

//Задача5. Возврат значения минимального элемента массива.
int arr_min(int arr1[], const int length) {
	int min = arr1[0];
	for (int i = 1; i < length; i++)
		if (arr1[i] < min)
			min = arr1[i];
	return min;
}

//Задача6. Возвращает значение максимального элемента в массиве.
int arr_max(int arr1[], const int length) {
	int max = arr1[0];
	for (int i = 1; i < length; i++)
		if (arr1[i] > max)
			max = arr1[i];
	return max;
}

//Задача7. Возвращает ср. ариф. всех элементов массива.
double mean_value(int arr1[], const int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr1[i];
	return sum /(double) length;
}

//Задача8. Выводит все элементы массива, которые входят в переданный в функцию диапазон.
template<typename T>
void range(T arr[], const int length, T left, T right) {
	for (int i = 0; i < length; i++)
		if (arr[i] >= left && arr[i] <= right)
			std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

//Задача9. Вхождение переданного эл-та в массив(кол-во).
template<typename T>
int count(T arr[], const int length,T value ) {
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == value)
			counter++;
	return counter;
}

//Задача10. По возрастанию сортировка
template<typename T>
void bubble_sort(T arr[], const int length) {
	for (int i = length - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}



int main() {
	system("chcp 1251>nul");
	int n, m;

	//Задача1.
	const int size = 20;
	int arr[size];

	fill_arr(arr, size, 1, 21);
	std::cout << "Массив:\n";
	print_arr(arr, size);

	std::cout << "Введите число -> ";
	std::cin >> n;

	//Задача3.
	int index = search_index(arr, size, n);
	if (index != -1)
		std::cout << "Позиция числа в массиве ->" << index << std::endl;
	else
		std::cout << "Числа нет в массиве!" << std::endl;

	//Задача4.
	int last_index = search_last_index(arr, size, n);
	if (last_index != -1)
		std::cout << "Позиция последнего числа в массиве -> " << last_index << std::endl;
	else
		std::cout << "Числа нет в массиве!" << std::endl<<std::endl;

	//Задача5, 6, 7.
	const int size1 = 20;
	int arr1[size1];
	fill_arr(arr1, size1, 1, 21);
	print_arr(arr1, size1);
	std::cout << "Минимальное значение в массиве -> "<<arr_min(arr1, size1)<<std::endl;
	std::cout << "Максимальный элемент в массиве ->" << arr_max(arr1, size1) << std::endl;
	std::cout << "Ср. ар. всех элементов ->" << mean_value(arr1, size1) << std::endl;

	//Задача8.
	std::cout << "Введите начало и конец диапазона -> ";
	std::cin >> n >> m;
	std::cout << "Элементы между " << n << " и " << m << "\n";
	range(arr, size, n, m);


	//Задача9.
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << "Кол-во совпадений: " << count(arr, size, n) << "\n\n";

	//Задача10.
	std::cout << "Изначальный массив ->\n";
	print_arr(arr, size);

	bubble_sort(arr, size);
	std::cout << "Отсортированный массив ->\n";
	print_arr(arr, size);

	return 0;
}