#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void fill_arr(T arr[], int length,int begin, int end) {
	srand(time(0));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (end + 1 - begin) + begin;
	}
}
template <typename T>
void show_arr(T arr[], int length) {
	cout << "[";
		for (int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n\n";
}
template <typename T>
void resize_arr(T *&arr, int length1, int length2) {
	if(length1==length2)
		return;
	if (length2 == 0) {
		delete[]arr;
		arr = new T[0];
		return;
	}
	T* tmp = new T[length2]{};
	if(length1<length2)
		for (int i = 0; i < length1; i++)
			tmp[i] = arr[i];
	else 
		for (int i = 0; i < length2; i++)
			tmp[i] = arr[i];
	delete[]arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	cout << "Домашнее задание №24.\n\nЗадача №1.\nВведите длину первого массива: ";
	cin >> n;
	int *A = new int[n];
	fill_arr(A, n, 13, 78);
	cout << "Массив A:\n";
	show_arr(A, n);		
	cout << "Введите длину второго массива: ";
	cin >> m;
	int *B = new int[m];
	fill_arr(B, m, 45, 99);
	cout << "Массив B:\n";
	show_arr(B, m);
	int* C = new int[n+m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i-n];
	cout << "Массив C:\n";
	show_arr(C, n+m);

	delete[]A;
	delete[]B;

	cout << "Задача №2.\nВведите длину массива: ";
	cin >> n;
	int* arr = new int[n];
	fill_arr(arr, n, 1, 10);
	cout << "Массив:\n";
	show_arr(arr, n);
	cout << "Введите новую длину массива: ";
	cin >> m;
	resize_arr(arr, n, m);
	cout << "Массив:\n";
	show_arr(arr, m);

	return 0;
}