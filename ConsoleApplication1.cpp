﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Vector; // Не полное обьявление класса

class Array
{
private:
	int** matrix;
	int rows;
	int cols;

public:
	Array() : rows(0), cols(0), matrix(new int* [0]) // Конструкт по умолчанию
	{

	}

	Array(int rowC, int colC, int** matr) : rows(rowC), cols(colC), matrix(matr) // Конструкт с параметрами
	{

	}

	Array(const Array& obj) : rows(obj.rows), cols(obj.cols), matrix(obj.matrix) // Конструкт копирование
	{

	}

	~Array()
	{
		delete[] matrix;
	}

	void Print()
	{
		cout << endl << "Массив:" << endl;
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				auto temp = matrix[r][c];
				cout << temp << " ";
			}
			cout << endl;
		}
	}

	Array Multiplication(Vector& vect);
};

class Vector
{
	friend Array Array::Multiplication(Vector& vect);
private:
	int* arr;
	int length;

public:
	Vector() : length(0), arr(new int[0])
	{

	}

	Vector(int l, int* a) : length(l), arr(a)
	{

	}

	Vector(const Vector& obj) : length(obj.length), arr(obj.arr)
	{

	}

	~Vector()
	{
		delete[] arr;
	}

};

Array Array::Multiplication(Vector& vector)
{
	int** result = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[1];
	}

	for (int i = 0; i < rows; i++)
	{
		result[i][0] = 0;
		for (int k = 0; k < vector.length; k++)
		{
			result[i][0] += matrix[i][k] * vector.arr[k];
		}
	}

	return Array(rows, 1, result);
}

int main()
{
	//Установить русскую кодировку консоли
	setlocale(LC_ALL, "Russian");

	//Выделение памяти под указатели
	int colCount = 0;
	int rowCount = 0;

	//Ввод размеров массива
	cout << "Введите кол-во строк массива:" << endl;
	cin >> rowCount;
	cout << "Введите кол-во столбцов массива:" << endl;
	cin >> colCount;

	//Выделение памяти на указатель на массив указателей
	int** arr = new int* [rowCount];
	//Выделение памяти под каждый указатель на массив в массиве указателей
	for (int i = 0; i < rowCount; i++)
	{
		arr[i] = new int[colCount];
	}

	//Цикл ввода массива через консоль
	for (int r = 0; r < rowCount; r++)
	{
		cout << "Строка " << r + 1 << ":" << endl;
		for (int c = 0; c < colCount; c++)
		{
			cin >> arr[r][c];
		}
	}

	Array m = Array(rowCount, colCount, arr);

	//Вывод исходного массива
	m.Print();

	//Ввод размеров массива
	cout << "Введите количество строк вектора:" << endl;
	cin >> rowCount;

	cout << "Введите вектор" << endl;
	int* arr2 = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		cin >> arr2[i];
	}

	Vector v = Vector(rowCount, arr2);

	Array res = m.Multiplication(v);
	res.Print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
