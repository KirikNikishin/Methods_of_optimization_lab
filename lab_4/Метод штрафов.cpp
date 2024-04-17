// Метод штрафов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

unordered_map<string, double> Koef(double x1, double x2, double koef1_f, double koef2_f, double koef3_f, double rk, double koef1_g, double koef2_g, double koef3_g) {
    unordered_map<string, double> Koef_;

    double koef1 = koef1_f + rk * koef1_g * koef1_g;
    Koef_["koef1"] = koef1;
    //cout << "koef1 = " << koef1 << endl;
    double koef2 = koef2_f + rk * koef2_g * koef2_g;
    Koef_["koef2"] = koef2;
    //cout << "koef2 = " << koef2 << endl;
    double koef3 = koef1_g * koef2_g * 2 * rk;
    Koef_["koef3"] = koef3;
    //cout << "koef3 = " << koef3 << endl;
    double koef4 = koef1_g * koef3_g * 2 * rk;
    Koef_["koef4"] = koef4;
    //cout << "koef4 = " << koef4 << endl;
    double koef5 = koef2_g * koef3_g * 2 * rk;
    Koef_["koef5"] = koef5;
    //cout << "koef5 = " << koef5 << endl;
    double koef6 = koef3_g * koef3_g * rk + koef3_f;
    Koef_["koef6"] = koef6;
    //cout << "koef6 = " << koef6 << endl;
    //double Fx = koef1 * pow(x1, 2) + koef2 * pow(x2, 2) + koef3 * x1 * x2 + koef4 * x1 + koef5 * x2 + koef6;
    //F_x["Fx"] = Fx;

    return Koef_;
}

double z(double x1, double x2, double koef1, double koef2, double koef3, double koef4, double koef5, double koef6) {
    //cout << "z = " << koef1 * pow(x1, 2) + koef2 * pow(x2, 2) + koef3 * x1 * x2 + koef4 * x1 + koef5 * x2 + koef6 << endl;
    return koef1 * pow(x1, 2) + koef2 * pow(x2, 2) + koef3 * x1 * x2 + koef4 * x1 + koef5 * x2 + koef6;
}

double f(double x1, double x2, double koef1, double koef2, double koef3) {
    //cout << "z = " << (koef1_f * pow(x1, 2) + koef2_f * pow(x2, 2) + koef3_f - rk * (1 / (koef1_g * x1 + koef2_g * x2 + koef3_g))) << endl;
    return (koef1 * pow(x1, 2) + koef2 * pow(x2, 2) + koef3);
}

double p(double x1, double x2, double rk, double koef1_g, double koef2_g, double koef3_g) {
    return rk * (pow(koef1_g * x1 + koef2_g * x2 + koef3_g, 2));
}

double determinant(double H[2][2]) {
    return (H[0][0] * H[1][1] - H[1][0] * H[0][1]);
}

double d0(double H[2][2], double grad_z_1, double grad_z_2, bool flag_d) {
    if (flag_d == true) {
        //cout << "********************d0=" << -1 * H[0][0] * grad_z_1 << endl;
        return (-1 * H[0][0] * grad_z_1 + -1 * H[0][1] * grad_z_2);
    }
    if (flag_d == false) {
        return (-1 * H[1][0] * grad_z_1 + -1 * H[1][1] * grad_z_2);
    }
}

//double z(double x1, double x2, double koef1, double koef2, double koef3) {
//    //cout << "z= " << (koef1 * pow(x1, 2) + koef2 * x1 * x2 + koef3 * pow(x2, 2)) << endl;
//    return (koef1 * pow(x1, 2) + koef2 * x1 * x2 + koef3 * pow(x2, 2));
//}

double grad_z1(double x1, double x2, double koef1, double koef3, double koef4) {
    //cout << "grad_z1 =" << (2 * koef1 * x1 + koef3 * x2 + koef4) << endl;
    return (2 * koef1 * x1 + koef3 * x2 + koef4);
}

double grad_z2(double x1, double x2, double koef2, double koef3, double koef5) {
    //cout << 2 * koef2 * x2 << " " << koef3 * x1 << endl;
    //cout << "grad_z2 =" << (2 * koef2 * x2 + koef3 * x1 + koef5) << endl;
    return (2 * koef2 * x2 + koef3 * x1 + koef5);
}

double norma_(double x_1, double x_2) {
    //cout << "norma_ = " << (sqrt(pow(x_1, 2) + pow(x_2, 2))) << endl;
    return (sqrt(pow(x_1, 2) + pow(x_2, 2)));
}

double xk_new_(double x, double grad_z_, double tk) {
    //cout << "xk_new_ = " << (x - tk * grad_z_) << endl;
    return (x - tk * grad_z_);
}

double xk_new_Newton (double x, double d0, double tk) {
    //cout << "x = " << x << endl;
    //cout << "d0 = " << d0 << endl;
    //cout << "tk = " << tk << endl;
    return (d0 * tk + x );
}

unordered_map<string, double> Newton(double x1, double x2, double koef1, double koef2, double koef3, double koef4, double koef5, double koef6){

    unordered_map<string, double> newton_;

    //double x1 = 0;
    //double x2 = 0.5;
    double eps1 = 0.15;
    double eps2 = 0.2;
    double M = 10;
    int k_N = 0;
    int flag = 0;
    double z1 = z(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);
    double z2 = 99999;
    double tk = 0.5;
    double x11;
    double x22;

    //   double grad_z_1 = grad_z1(x1, x2, koef1, koef2);
    //   double grad_z_2 = grad_z2(x1, x2, koef2, koef3);

    //   double norma_gradz = norma_(grad_z_1, grad_z_2);

    while (true) {
        //cout << "===========================================" << endl;
        double grad_z_1 = grad_z1(x1, x2, koef1, koef3, koef4);
        double grad_z_2 = grad_z2(x1, x2, koef2, koef3, koef5);

        double norma_gradz = norma_(grad_z_1, grad_z_2);

        if (norma_gradz < eps1) {
            double xx1 = x1;
            double xx2 = x2;
            double zxx = z2;
            //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
            //cout << zxx;
            newton_["xx1"] = xx1;
            newton_["xx2"] = xx2;
            return newton_;
            break;
        }
        else {
            if (k_N >= M) {
                double xx1 = x1;
                double xx2 = x2;
                double zxx = z2;
                newton_["xx1"] = xx1;
                newton_["xx2"] = xx2;
                return newton_;
                //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                //cout << zxx;
                break;
            }
            else {
                double H[2][2] = { {2 * koef1, koef3}, {koef3, 2 * koef2} };
                double H_n[2][2] = { {H[1][1], -1 * H[0][1]}, {-1 * H[1][0], H[0][0]} };
                double detH = determinant(H);
                double H_1[2][2] = { {1 / detH * H_n[0][0], 1 / detH * H_n[0][1]} , {1 / detH * H_n[1][0], 1 / detH * H_n[1][1]} };
                double detH_1 = determinant(H_1);
                if (H_1[0][0] > 0 and detH_1 > 0) {
                    bool flag_d = true;
                    double d0_1 = d0(H_1, grad_z_1, grad_z_2, flag_d);
                    flag_d = false;
                    double d0_2 = d0(H_1, grad_z_1, grad_z_2, flag_d);
                    flag_d = true;
                    //cout << d0_1 << " " << d0_2 << endl;
                    //cout << x1 << " " << x2 << endl;
                    double tk = 1;
                    x11 = xk_new_Newton(x1, d0_1, tk);
                    x22 = xk_new_Newton(x2, d0_2, tk);
                    z2 = z(x11, x22, koef1, koef2, koef3, koef4, koef5, koef6);
                    //cout << x11 << " " << x22 << endl;
                    //break;
                }
                else { //?
                    //double koef_gold_1 = koef1 * grad_z_1 * grad_z_1 + koef2 * grad_z_1 * grad_z_2 + koef3 * grad_z_2 * grad_z_2;
                    //double koef_gold_2 = koef1 * 2 * x1 * -1 * grad_z_1 + koef2 * x1 * -1 * grad_z_2 + koef2 * x2 * -1 * grad_z_1 + koef3 * 2 * x2 * -1 * grad_z_2;
                    //double koef_gold_3 = koef1 * x1 * x1 + koef2 * x1 * x2 + koef3 * x2 * x2;
                    //double tk = gold(koef_gold_1, koef_gold_2, koef_gold_3, eps2);
                    ////cout << tk << endl;
                    //x11 = xk_new_(x1, grad_z_1, tk);
                    //x22 = xk_new_(x2, grad_z_2, tk);
                    //z2 = z(x11, x22, koef1, koef2, koef3, koef4, koef5, koef6); //?
                    while (true) {
                        x11 = xk_new_(x1, grad_z_1, tk);
                        x22 = xk_new_(x2, grad_z_2, tk);
                        z2 = z(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);
                        if (z2 - z1 >= 0) {
                            //cout << "********************tk = " << tk << endl;
                            tk = tk / 2;
                        }
                        else {
                            //cout << "********************tk = " << tk << endl;
                            break;
                        }
                    }
                }
                //cout << koef_gold_2 << endl;
                //cout << koef_gold_3 << endl;
                double razn_1 = x11 - x1;
                double razn_2 = x22 - x2;
                double norma_razn = norma_(razn_1, razn_2);

                //cout << "*********************z1 = " << z1 << endl;
                //cout << "*********************z2 =" << z2 << endl;
                //cout << "*********************fabs(z2 - z1) =" << fabs(z2 - z1) << endl;
                //cout << "*********************eps2 =" << eps2 << endl;

                if ((norma_razn >= eps2) or (fabs(z2 - z1) >= eps2)) {
                    flag = 0;
                    k_N += 1;
                    x1 = x11;
                    x2 = x22;
                    //cout << "(" << x1 << "; " << x2 << ")" << endl;
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
                        newton_["xx1"] = xx1;
                        newton_["xx2"] = xx2;
                        //cout << "(" << xx1 << "; " << xx2 << ")" << endl;
                        return newton_;
                        break;
                    }
                    else {
                        k_N += 1;
                        x1 = x11;
                        x2 = x22;
                        z1 = z2;
                    }

                }
            }

        }
    }
}

unordered_map<string, double> Gradient(double x1, double x2, double koef1, double koef2, double koef3, double koef4, double koef5, double koef6) {

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
    double z1 = z(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);
    double z2 = 99999;
    double tk = 0.5;
    double x11;
    double x22;

    //   double grad_z_1 = grad_z1(x1, x2, koef1, koef2);
    //   double grad_z_2 = grad_z2(x1, x2, koef2, koef3);

    //   double norma_gradz = norma_(grad_z_1, grad_z_2);

    while (true) {
        //cout << "===========================================" << endl;
        double grad_z_1 = grad_z1(x1, x2, koef1, koef3, koef4);
        double grad_z_2 = grad_z2(x1, x2, koef2, koef3, koef5);
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
                    z2 = z(x11, x22, koef1, koef2, koef3, koef4, koef5, koef6);
                    //cout << "*********************z1 = " << z1 << endl;
                    //cout << "*********************z2 =" << z2 << endl;
                    if (z2 - z1 >= 0) {
                        //cout << "********************tk = " << tk << endl;
                        //cout << "z1 = " << z1 << endl;
                        //cout << "z2 = " << z2 << endl;
                        tk = tk / 2;
                    }
                    else {
                        //cout << "********************tk = " << tk << endl;
                        break;
                    }
                }
                double razn_1 = x11 - x1;
                double razn_2 = x22 - x2;
                double norma_razn = norma_(razn_1, razn_2);

                
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

int main() {
    double x1 = 0;
    double x2 = 0.5;
    double koef1_f = 6;
    double koef2_f = 2;
    double koef3_f = 0;
    double koef1_g = 8;
    double koef2_g = 1;
    double koef3_g = -7;
    double rk = 0.25;
    double C = 10;
    double eps = 0.05;
    int k = 0;
    
    while (true){
        unordered_map<string, double> Koef_ = Koef(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);
        double koef1 = Koef_["koef1"];
        double koef2 = Koef_["koef2"];
        double koef3 = Koef_["koef3"];
        double koef4 = Koef_["koef4"];
        double koef5 = Koef_["koef5"];
        double koef6 = Koef_["koef6"];
        //cout << koef1 << endl;
        //cout << koef2 << endl;
        //cout << koef3 << endl;
        //cout << koef4 << endl;
        //cout << koef5 << endl;
        //cout << koef6 << endl;
        if (koef1 <= 250) {
            unordered_map<string, double> newton_ = Newton(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);

            x1 = newton_["xx1"];
            x2 = newton_["xx2"];
            //cout << "x1 = " << x1 << ", x2 = " << x2 << endl; 
            double p_1 = p(x1, x2, rk, koef1_g, koef2_g, koef3_g);
            //cout << p_1 << endl;
            if (p_1 > eps) {
                rk *= C;
                k += 1;
            }
            else {
                cout << "(" << x1 << "; " << x2 << ")" << endl;
                cout << f(x1, x2, koef1_f, koef2_f, koef3_f) << endl;
                break;
            }
        }
        else {
            unordered_map<string, double> gradient_ = Gradient(x1, x2, koef1, koef2, koef3, koef4, koef5, koef6);

            double x1 = gradient_["xx1"];
            double x2 = gradient_["xx2"];
            //cout << "x1 = " << x1 << ", x2 = " << x2 << endl; 
            double p_1 = p(x1, x2, rk, koef1_g, koef2_g, koef3_g);
            //cout << p_1 << endl;
            if (p_1 > eps) {
                rk *= C;
                k += 1;
            }
            else {
                cout << "(" << x1 << "; " << x2 << ")" << endl;
                cout << f(x1, x2, koef1_f, koef2_f, koef3_f) << endl;
                break;
            }
        }
    }
    
    //double func = z(x1, x2, koef1_f, koef2_f, koef3_f, rk, koef1_g, koef2_g, koef3_g);
    
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
