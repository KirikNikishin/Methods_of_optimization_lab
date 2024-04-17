// Метод золотого сечения.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double y(double x) {
    return (pow(x, 3)) + 3 * (pow(x, 2)) - 3;
}
double f_delta(double a, double b) {
    if (b > a) {
        return b - a;
    }
    else {
        return a - b;
    }
}
int main()
{
    //double x = 0;
    //double y = (pow(x, 3)) + 3 * (pow(x, 2)) - 3;
    int k = 0;
    double start = -1;
    double stop = 1;
    double eps = 0.2;
    double yk = start + (((3 - sqrt(5)) / 2) * (stop - start));
    double zk = start + stop - yk;
    double delta = f_delta(start, stop);
    while (delta > eps) {
        double fyk = y(yk);
        double fzk = y(zk);
        if (fyk > fzk) {
            start = yk;
            //stop += 0;
            yk = zk;
            zk = start + stop - zk;
        }
        else {
            //start += 0;
            stop = zk;
            zk = yk;
            yk = start + stop - yk;
        }
        delta = f_delta(start, stop);
        k += 1;
    }
    double xx = (start + stop) / 2;

    cout << xx << endl;
    cout << y(xx) << endl;
    cout << k << endl;
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
