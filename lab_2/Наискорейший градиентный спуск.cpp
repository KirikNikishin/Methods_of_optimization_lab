// Наискорейший градиентный спуск.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double fi(double tk, double koef_gold_1, double koef_gold_2, double koef_gold_3) {
    return (koef_gold_1 * pow(tk, 2)) + koef_gold_2 * tk - koef_gold_3;
}
double f_delta(double a, double b) {
    if (b > a) {
        return b - a;
    }
    else {
        return a - b;
    }
}
double gold(double koef_gold_1, double koef_gold_2, double koef_gold_3, double eps)
{
    int k = 0;
    double start = 0;
    double stop = 1;
    //double eps = 0.2;
    double yk = start + (((3 - sqrt(5)) / 2) * (stop - start));
    double zk = start + stop - yk;
    double delta = f_delta(start, stop);
    while (delta > eps) {
        double fyk = fi(yk, koef_gold_1, koef_gold_2, koef_gold_3);
        double fzk = fi(zk, koef_gold_1, koef_gold_2, koef_gold_3);
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

    return xx;
}




double z(double x1, double x2, double koef1, double koef2, double koef3) {
    //cout << "z= " << (koef1 * pow(x1, 2) + koef2 * x1 * x2 + koef3 * pow(x2, 2)) << endl;
    return (koef1 * pow(x1, 2) + koef2 * x1 * x2 + koef3 * pow(x2, 2));
}

double grad_z1(double x1, double x2, double koef1, double koef2) {
    //cout << "grad_z1 =" << (2 * koef1 * x1 + koef2 * x2) << endl;
    return (2 * koef1 * x1 + koef2 * x2);
}

double grad_z2(double x1, double x2, double koef2, double koef3) {
    //cout << "grad_z2 =" << (koef2 * x1 + 2 * koef3 * x2) << endl;
    return (koef2 * x1 + 2 * koef3 * x2);
}

double norma_(double x_1, double x_2) {
    //cout << "norma_ = " << (sqrt(pow(x_1, 2) + pow(x_2, 2))) << endl;
    return (sqrt(pow(x_1, 2) + pow(x_2, 2)));
}

double xk_new_1(double x1, double grad_z_1, double tk) {
    //cout << "xk_new_1 = " << (x1 - tk * grad_z_1) << endl;
    return (x1 - tk * grad_z_1);
}

double xk_new_2(double x2, double grad_z_2, double tk) {
    //cout << "xk_new_2 = " << (x2 - tk * grad_z_2) << endl;
    return (x2 - tk * grad_z_2);
}

int main()
{
    double x1 = 0;
    double x2 = 0.5;
    double eps1 = 0.15;
    double eps2 = 0.2;
    double M = 10;
    int k1 = 0;
    int flag = 0;
    double koef1 = 242;
    double koef2 = 1232;
    double koef3 = 1935;
    double z1 = z(x1, x2, koef1, koef2, koef3);
    double z2 = 99999;
    //double tk = 0.5;
    double x11;
    double x22;

    //   double grad_z_1 = grad_z1(x1, x2, koef1, koef2);
    //   double grad_z_2 = grad_z2(x1, x2, koef2, koef3);

    //   double norma_gradz = norma_(grad_z_1, grad_z_2);

    while (true) {
        //cout << "===========================================" << endl;
        double grad_z_1 = grad_z1(x1, x2, koef1, koef2);
        double grad_z_2 = grad_z2(x1, x2, koef2, koef3);

        double norma_gradz = norma_(grad_z_1, grad_z_2);

        if (norma_gradz < eps1) {
            double xx1 = x1;
            double xx2 = x2;
            double zxx = z2;
            cout << "(" << xx1 << "; " << xx2 << ")" << endl;
            cout << zxx;
            break;
        }
        else {
            if (k1 >= M) {
                double xx1 = x1;
                double xx2 = x2;
                double zxx = z2;
                cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                cout << zxx;
                break;
            }
            else {
                double koef_gold_1 = koef1 * grad_z_1 * grad_z_1 + koef2 * grad_z_1 * grad_z_2 + koef3 * grad_z_2 * grad_z_2;
                double koef_gold_2 = koef1 * 2 * x1 * -1 * grad_z_1 + koef2 * x1 * -1 * grad_z_2 + koef2 * x2 * -1 * grad_z_1 + koef3 * 2 * x2 * -1 * grad_z_2;
                double koef_gold_3 = koef1 * x1 * x1 + koef2 * x1 * x2 + koef3 * x2 * x2;
                double tk = gold(koef_gold_1, koef_gold_2, koef_gold_3, eps2);
                //cout << tk << endl;
                x11 = xk_new_1(x1, grad_z_1, tk);
                x22 = xk_new_2(x2, grad_z_2, tk);
                z2 = z(x11, x22, koef1, koef2, koef3);
                //cout << koef_gold_2 << endl;
                //cout << koef_gold_3 << endl;
                double razn_1 = x11 - x1;
                double razn_2 = x22 - x2;
                double norma_razn = norma_(razn_1, razn_2);

                ////cout << "*********************z1 = " << z1 << endl;
                /////cout << "*********************z2 =" << z2 << endl;
                ////cout << "*********************fabs(z2 - z1) =" << fabs(z2 - z1) << endl;
                ////cout << "*********************eps2 =" << eps2 << endl;

                if ((norma_razn >= eps2) or (fabs(z2 - z1) >= eps2)) {
                    flag = 0;
                    k1 += 1;
                    x1 = x11;
                    x2 = x22;
                    z1 = z2;
                }
                else {
                    //if (fabs(z2 - z1) >= eps2) {
                    //    flag = 0;
                    //    k += 1;
                    //    x1 = x11;
                    //    x2 = x22;
                    //}
                    //else {
                    flag += 1;
                    //cout << "flag = " << flag << endl;
                    if (flag == 2) {
                        double xx1 = x11;
                        double xx2 = x22;
                        double zxx = z2;
                        cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                        cout << zxx;
                        break;
                    }
                    else {
                        k1 += 1;
                        x1 = x11;
                        x2 = x22;
                        z1 = z2;
                    }

                }

            }
        }
    }

    //cout << grad_z_1 << endl;
    //cout << norma_grad_z(grad_z_1, grad_z_2);
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
