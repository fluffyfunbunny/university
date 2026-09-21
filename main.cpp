#include <iostream>
#include <cmath>
#include <iomanip>
#include <locale.h>

using namespace std;
double x = 0;

static double calculateF(double x) {
    if (x < 2.0) {
        return x;
    } else if (x <= 3.0) {
        return 2.0;
    }  else {
        return -x + 5.0;
    }
}

void runTask1_Part2() {
    cout << "\nЗадание 1. Часть 2. Разветвляющийся процесс" << endl;
    double x;
    scanf("%lf", &x);
    cout << calculateF(x) << endl;
    cout << endl;
}

// --- Часть 3. Циклический процесс ---
void runTask1_Part3() {
    cout << "\nЗадание 1. Часть 3. Циклический процесс" << endl;
    
    double xi;
    cout << "Введите точность xi (например, 0.0001): ";
    if (!(cin >> xi) || xi <= 0) {
        cerr << "Некорректная точность!" << endl;
        return;
    }

    double sum = 0.0;
    double term = 0.0;
    int k = 1;
    int iterations = 0;

    do {
        term = 1.0 / (pow(k, 2) * pow(k + 1, 2));
        sum += term;
        iterations++;
        k++;
    } while (term >= xi);

    const double PI = acos(-1.0);
    double exact_value = (PI * PI) / 3.0 - 3.0;

    cout << fixed << setprecision(8);
    cout << "\nРезультаты:" << endl;
    cout << "Точность xi:             " << xi << endl;
    cout << "Вычисленная сумма:       " << sum << endl;
    cout << "Точное значение:        " << exact_value << endl;
    cout << "Абсолютная погрешность: " << fabs(sum - exact_value) << endl;
    cout << "Количество итераций:    " << iterations << endl << endl;
}

// --- Главная функция с выбором ---
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int choice;
    cout << "Какая часть задачи? (2 или 3): ";
    if (!(cin >> choice)) {
        cout << "Ошибка ввода!" << endl;
        return 1;
    }

    switch (choice) {
        case 2:
            runTask1_Part2();
            break;
        case 3:
            runTask1_Part3();
            break;
        default:
            cout << "Некорректный выбор! Допустимы варианты 2 или 3." << endl;
            break;
    }

    return 0;
}