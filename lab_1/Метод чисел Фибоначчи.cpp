// Метод чисел Фибоначчи.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <vector>
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
    double l = 0.2;
    int N;
    vector <double> Fibonachi;
    double yk;
    cout << "Enter N" << endl;
    cin >> N;
    for (int i = 0; i < 2; i++) {
        Fibonachi.push_back(1);
    }
    for (int i = 2; i < N+2; i++) {
        Fibonachi.push_back(Fibonachi[i - 2] + Fibonachi[i - 1]);
    }
    
    double F = Fibonachi[Fibonachi.size() - 1];
    while (F+1 < ((stop - start) / l)) {
        Fibonachi.clear();
        cin.clear();
        cin.ignore(1000);
        cout << "Enter N" << endl;
        cin >> N;
        for (int i = 0; i < 2; i++) {
            Fibonachi.push_back(1);
        }
        for (int i = 2; i < N + 2; i++) {
            Fibonachi.push_back(Fibonachi[i - 2] + Fibonachi[i - 1]);
        }

        int F = Fibonachi[-1];
    }
    while (k != N - 2) {
        yk = start + ((Fibonachi[Fibonachi.size() - 3] / Fibonachi[Fibonachi.size() - 1]) * (stop - start));
        cout << "yk = " << yk << endl;
        double zk = start + ((Fibonachi[Fibonachi.size() - 2] / Fibonachi[Fibonachi.size() - 1]) * (stop - start));
        cout << "zk = " << zk << endl;
        double fyk = y(yk);
        cout << "fyk = " << fyk << endl;
        double fzk = y(zk);
        cout << "fzk = " << fzk << endl;
        if (fyk > fzk) {
            start = yk;
            cout << "start = " << start << endl;
            //stop += 0;
            yk = zk;
            cout << "yk = " << yk << endl;
            zk = start + ((Fibonachi[Fibonachi.size() - 3 - k]) / (Fibonachi[Fibonachi.size() - 2 - k]) * (stop - start));
            cout << "zk = " << zk << endl;
            cout << endl;
        }
        else {
            //start += 0;
            stop = zk;
            cout << "stop = " << stop << endl;
            //yk += 0;
            cout << "yk = " << yk << endl;
            zk = start + ((Fibonachi[Fibonachi.size() - 4 - k]) / (Fibonachi[Fibonachi.size() - 2 - k]) * (stop - start));
            cout << "zk = " << zk << endl;
            cout << endl;
        }
        k += 1;
    }

    double yN_1 = yk;
    double zN_1 = yN_1 + eps;

    if (y(yN_1) > y(zN_1)) {
        double aN_1 = yN_1;
        double bN_1 = stop;
        double xx = (aN_1 - bN_1) / 2;

        cout << xx << endl;
        cout << y(xx) << endl;
        cout << k << endl;
    }
    else {
        double aN_1 = start;
        double bN_1 = zN_1;
        double xx = (aN_1 - bN_1) / 2;

        cout << endl;
        cout << endl;
        cout << xx << endl;
        cout << y(xx) << endl;
        cout << k << endl;
    }

    
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
