// Метод половинного деления.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double y(double x) {
    return (pow(x, 3)) + 3 * (pow(x, 2)) - 3;
}
int main()
{
    //double x = 0;
    //double y = (pow(x, 3)) + 3 * (pow(x, 2)) - 3;
    int k = 0;
    double start = -1;
    double stop = 1;
    double eps = 0.2;
    double xck = (start + stop) / 2;
    double fxck = y(xck);
    double L2k = stop - start;
    while (L2k > eps) {
        double yk = start + (L2k / 4);
        double zk = stop - (L2k / 4);
        double fyk = y(yk);
        double fzk = y(zk);
        if (fyk < fxck) {
            stop = xck;
            //start += 0;
            xck = yk;
        }
        else {
            if (fzk < fxck) {
                start = xck;
                //stop += 0;
                xck = zk;
            }
            else {
                start = yk;
                stop = zk;
                //xck += 0;
            }
        }
        L2k = stop - start;
        if (L2k < 0) {
            L2k *= -1;
        }
        k += 1;
    }
    double xx = xck;

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
