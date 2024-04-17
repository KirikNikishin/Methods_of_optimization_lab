// Метод барьерных функций.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

double z(double x1, double x2, double koef1_f, double koef2_f, double koef3_f, double rk, double koef1_g, double koef2_g, double koef3_g) {
    //cout << "z = " << (koef1_f * pow(x1, 2) + koef2_f * pow(x2, 2) + koef3_f - rk * (1 / (koef1_g * x1 + koef2_g * x2 + koef3_g))) << endl;
    return (koef1_f * pow(x1, 2) + koef2_f * pow(x2, 2) + koef3_f - rk * (1/(koef1_g * x1 + koef2_g * x2 + koef3_g)));
}

double f(double x1, double x2, double koef1_f, double koef2_f, double koef3_f) {
    //cout << "z = " << (koef1_f * pow(x1, 2) + koef2_f * pow(x2, 2) + koef3_f - rk * (1 / (koef1_g * x1 + koef2_g * x2 + koef3_g))) << endl;
    return (koef1_f * pow(x1, 2) + koef2_f * pow(x2, 2) + koef3_f);
}

double g(double x1, double x2, double koef1_g, double koef2_g, double koef3_g) {
    return (koef1_g * x1 + koef2_g * x2 + koef3_g);
}

double grad_z1(double x1, double x2, double koef1_f, double koef2_f, double koef3_f, double koef1_g, double koef2_g, double koef3_g) {
    //cout << "grad_z1 =" << (2 * koef1_f * x1 + ((2 * koef1_g)/(pow(2 * koef1_g * x1 + 2 * koef2_g * x2 + 2 * koef3_g, 2)))) << endl;
    return (2 * koef1_f * x1 + ((2 * koef1_g) / (pow(2 * koef1_g * x1 + 2 * koef2_g * x2 + 2 * koef3_g, 2))));
}

double grad_z2(double x1, double x2, double koef1_f, double koef2_f, double koef3_f, double koef1_g, double koef2_g, double koef3_g) {
    //cout << "grad_z2 =" << (2 * koef2_f * x2 + ((2 * koef2_g) / (pow(2 * koef1_g * x1 + 2 * koef2_g * x2 + 2 * koef3_g, 2)))) << endl;
    return (2 * koef2_f * x2 + ((2 * koef2_g) / (pow(2 * koef1_g * x1 + 2 * koef2_g * x2 + 2 * koef3_g, 2))));
}

double norma_(double x_1, double x_2) {
    //cout << "norma_ = " << (sqrt(pow(x_1, 2) + pow(x_2, 2))) << endl;
    return (sqrt(pow(x_1, 2) + pow(x_2, 2)));
}

double xk_new_(double x, double grad_z_, double tk) {
    //cout << "xk_new_1 = " << (x1 - tk * grad_z_1) << endl;
    return (x - tk * grad_z_);
}

double p(double x1, double x2, double rk, double koef1_g, double koef2_g, double koef3_g) {
    //cout << rk / 2 << endl;
    return (-1 * rk * (1/(koef1_g * x1 + koef2_g * x2 + koef3_g)));
}

bool proverka(double g) {
    if (g >= 0) {
        return false;
    }
    else {
        return true;
    }
};

unordered_map<string, double> Gradient(double x1, double x2, double koef1_f, double koef2_f, double koef3_f, double rk, double koef1_g, double koef2_g, double koef3_g, double koef1_g_new, double koef2_g_new, double koef3_g_new) {

    //cout << "**************************************************************************" << endl;
    //cout << x1 << endl;

    unordered_map<string, double> gradient_;

    //double x1 = 0;
    //double x2 = 0.5;
    double eps1 = 0.15;
    double eps2 = 0.2;
    double M = 10;
    int k = 0;
    int flag = 0;
    //double koef1 = 1;
    //double koef2 = 0.6;
    //double koef3 = 6;
    double z1 = z(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);
    double z2 = 99999;
    double tk = 0.5;
    double x11;
    double x22;

    //   double grad_z_1 = grad_z1(x1, x2, koef1, koef2);
    //   double grad_z_2 = grad_z2(x1, x2, koef2, koef3);

    //   double norma_gradz = norma_(grad_z_1, grad_z_2);

    while (true) {
        //cout << "===========================================" << endl;
        double grad_z_1 = grad_z1(x1, x2, koef1_f, koef2_f, koef3_f, koef1_g_new, koef2_g_new, koef3_g_new);
        double grad_z_2 = grad_z2(x1, x2, koef1_f, koef2_f, koef3_f, koef1_g_new, koef2_g_new, koef3_g_new);
        //cout << x1 << endl;

        double norma_gradz = norma_(grad_z_1, grad_z_2);

        if (norma_gradz < eps1) {
            double xx1 = x1;
            double xx2 = x2;
            double zxx = z2;
            gradient_["xx1"] = xx1;
            gradient_["xx2"] = xx2;
            //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
            return gradient_;
            break;
        }
        else {
            if (k >= M) {
                double xx1 = x1;
                double xx2 = x2;
                double zxx = z2;
                gradient_["xx1"] = xx1;
                gradient_["xx2"] = xx2;
                //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                return gradient_;
                break;
            }
            else {
                while (true) {
                    x11 = xk_new_(x1, grad_z_1, tk);
                    x22 = xk_new_(x2, grad_z_2, tk);
                    z2 = z(x11, x22, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);
                    if (z2 - z1 >= 0) {
                        //cout << "********************tk = " << tk << endl;
                        //cout << "z1 = " << z1 << endl;
                        //cout << "z2 = " << z2 << endl;
                        tk = tk / 2;
                        //cout << "(" << x11 << "; " << x22 << ")" << endl;
                    }
                    else {
                        //cout << "********************tk = " << tk << endl;
                        break;
                    }
                }
                double razn_1 = x11 - x1;
                double razn_2 = x22 - x2;
                double norma_razn = norma_(razn_1, razn_2);

                //cout << "*********************z1 = " << z1 << endl;
                //cout << "*********************z2 =" << z2 << endl;
                //cout << "*********************fabs(z2 - z1) =" << fabs(z2 - z1) << endl;
                //cout << "*********************eps2 =" << eps2 << endl;

                if ((norma_razn >= eps2) or (fabs(z2 - z1) >= eps2)) {
                    flag = 0;
                    k += 1;
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
                        gradient_["xx1"] = xx1;
                        gradient_["xx2"] = xx2;
                        //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                        return gradient_;
                        break;
                    }
                    else {
                        k += 1;
                        x1 = x11;
                        x2 = x22;
                        z1 = z2;
                    }

                }

            }
        }
    }
}

int main()
{
    double x1 = 0;
    double x2 = 0.5;
    double koef1_f = 6;
    double koef2_f = 2;
    double koef3_f = -17;
    double koef1_g = 8;
    double koef2_g = 1;
    double koef3_g = -7;
    double rk = 0.5;
    double C = 10;
    double eps = 0.05;
    int k = 0;
    double g_ = g(x1, x2, koef1_g, koef2_g, koef3_g);

    double koef1_g_new = koef1_g;
    double koef2_g_new = koef2_g;
    double koef3_g_new = koef3_g;

    //double z_F = z(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);

    while (true) {
        unordered_map<string, double> gradient_ = Gradient(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g, koef1_g_new, koef2_g_new, koef3_g_new);

        double xxx1 = gradient_["xx1"];
        double xxx2 = gradient_["xx2"];
        //cout << "x1 = " << xxx1 << ", x2 = " << xxx2 << endl;
        double p_1 = fabs(p(xxx1, xxx2, rk, koef1_g, koef2_g, koef3_g));
        //cout << "p_1 = " << p_1 << endl;
        if (p_1 > eps) {
            rk /= C;
            k += 1;
            koef1_g_new *= 10;
            koef2_g_new *= 10;
            koef3_g_new *= 10;
            x1 = xxx1;
            x2 = xxx2;
        }
        else {
            if (proverka(g_) == true) {
                cout << "(" << xxx1 << "; " << xxx2 << ")" << endl;
                //cout << koef2_g << endl;
                cout << "f(x) = " << f(x1, x2, koef1_f, koef2_f, koef3_f) << endl;
                break;
            }
            else {
                rk /= C;
                koef1_g_new *= 10;
                koef2_g_new *= 10;
                koef3_g_new *= 10;
            }
        }
        //cout << "(" << x1 << "; " << x2 << ")" << endl;
        //cout << z(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g) << endl;
    }
    
    //cout << p_1 << endl;
    //if (p_1 > eps) {
    //    rk *= C;
    //    k += 1;
    //}
    //else {
    //    cout << "(" << x1 << "; " << x2 << ")" << endl;
    //    cout << z(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g) << endl;
    //    //break;
    //}
    /*unordered_map<string, double> Koef_ = Koef(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);
    double koef1 = Koef_["koef1"];
    double koef2 = Koef_["koef2"];
    double koef3 = Koef_["koef3"];
    double koef4 = Koef_["koef4"];
    double koef5 = Koef_["koef5"];
    double koef6 = Koef_["koef6"];*/

    //unordered_map<string, double> gradient_ = Gradient(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);

    //double a = gradient_["xx1"];
    //double b = gradient_["xx2"];
    //cout << "a = " << a << ", b = " << b << endl;
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
