﻿// Наибольшая общая подпоследовательность. Даны две последовательности чисел. 
// Нужно найти их наибольшую общую подпоследовательность.
//
// Входные данные
// Первые две строки содержат описание первой последовательности.
// В первой строке дано количество элементов последовательности, 
// во второй строке через пробел заданы ее элементы.
// В следующих двух строках аналогично задана вторая последовательность.
//
// Выходные данные
// Выведите одно целое число - длину наибольшей общей подпоследовательности.
//
// Решение динамическим программированием

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n, m;
	string fn;
	ifstream cinf;

	cout << "Введите имя файла" << endl;
	cin >> fn;
	cinf.open(fn);

	cinf >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cinf >> a[i];

	cinf >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cinf >> b[i];

	cinf.close();

	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));  // динамическое определение подпоследовательностей для каждого числа 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			if (a[i - 1] == b[j - 1])
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
		}

    cout << d[n][m] << endl;

	system("pause");
	return 0;
}
