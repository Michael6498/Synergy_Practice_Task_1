#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    double a[100];

    cout << "Введите количество элементов массива (до 100): ";
    cin >> n;
    if (cin.fail() || n <= 0 || n > 100) {
        cout << "Ошибка! Не допустимый размер массива. Программа завершена\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " элемент массива: ";
        cin >> a[i];
        if (cin.fail()) {
            cout << "Ошибка! Нужно было ввести число. Программа завершена\n";
            return 0;
        }
    }

    int min_idx = 0;
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min_idx]) min_idx = i;
        if (a[i] > a[max_idx]) max_idx = i;
    }

    cout << "\n-----------------------------------------\n";
    cout << "Минимальный элемент на позиции: " << min_idx + 1 << " (это число " << a[min_idx] << ")\n";
    cout << "Максимальный элемент на позиции: " << max_idx + 1 << " (это число " << a[max_idx] << ")\n";

    int start, end;
    if (min_idx < max_idx) {
        start = min_idx;
        end = max_idx;
    }
    else {
        start = max_idx;
        end = min_idx;
    }

    double sum = 0;
    bool found = false;
    for (int i = start + 1; i < end; i++) {
        if (a[i] < 0) {
            sum = sum + a[i];
            found = true;
        }
    }

    if (found) {
        cout << "Сумма отрицательных чисел между ними: " << sum << endl;
    }
    else {
        cout << "Между ними нет отрицательных чисел\n";
    }
    return 0;
}
