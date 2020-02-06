﻿// Тайм-менеджмент. У Васи есть список из n дел, в котором для каждого дела j указаны время t[j]​, 
// которое требуется Васе, чтобы сделать это дело, и момент времени d[j], 
// не позже которого нужно начать делать это дело. Вася начинает работать в момент времени 0. 
// Он будет делать дела строго в том порядке, в котором они записаны в его списке, 
// возможно, пропуская некоторые из них. Он хочет максимизировать количество дел, которые ему удастся сделать.
//
// Входные данные
// В первой строке содержится целое число n - количество дел в списке.
// В каждой из следующих n строк содержится по два целых числа t[j] и d[j]​ - время, 
// необходимое, чтобы сделать дело с номером j, и момент времени, не позже которого это дело необходимо начать делать.
//
// Выходные данные
// Выведите одно целое число - максимальное количество дел, которое можно успеть сделать.
//
// Решение динамическим программированием

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int n;
    string fn;
    ifstream cinf;

    cout << "Введите имя файла" << endl;
    cin >> fn;
    cinf.open(fn);
    cinf >> n;

    long long sum(0);
    vector<int> t(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cinf >> t[i] >> d[i];
        sum += t[i];
    }

    int cmax(0);
    vector<vector<int>> c(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)         // динамика - расчет всех возможных количеств дел
    {
        for (int j = 0; j < sum; j++)
        {
            c[i + 1][j] = max(c[i + 1][j], c[i][j]);
            if (j > d[i]) continue;
            c[i + 1][j + t[i]] = max(c[i + 1][j + t[i]], c[i][j] + 1);
        }
    }
    
    int ans(0);
    for (int cur = 0; cur < sum; cur++)     // вывод максимального количества дел
        ans = max(ans, c[n][cur]);
    cout << ans << endl;

    system("pause");
    return 0;
}
