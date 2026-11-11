// 10.1.2. Два стека в одном массиве.
// Левый стек растёт от начала массива, правый — от конца.
// Индексы вершин пустых стеков равны -1 и n. Места больше нет,
// когда вершины соседствуют. Все четыре операции работают за O(1).
#include <iostream>

using namespace std;

bool push_left(int data[], int& left_top, int right_top, int value) {
    if (left_top + 1 == right_top) {
        return false;
    }
    ++left_top;
    data[left_top] = value;
    return true;
}

bool push_right(int data[], int left_top, int& right_top, int value) {
    if (left_top + 1 == right_top) {
        return false;
    }
    --right_top;
    data[right_top] = value;
    return true;
}

bool pop_left(const int data[], int& left_top, int& value) {
    if (left_top == -1) {
        return false;
    }
    value = data[left_top];
    --left_top;
    return true;
}

bool pop_right(const int data[], int n, int& right_top, int& value) {
    if (right_top == n) {
        return false;
    }
    value = data[right_top];
    ++right_top;
    return true;
}

int main() {
    const int n = 4;
    int data[n] = {};
    int left_top = -1;
    int right_top = n;

    push_left(data, left_top, right_top, 4);
    push_right(data, left_top, right_top, 8);
    push_left(data, left_top, right_top, 1);
    push_left(data, left_top, right_top, 3);

    if (!push_right(data, left_top, right_top, 9)) {
        cout << "Общий массив переполнен\n";
    }

    int value;
    cout << "Левый стек:";
    while (pop_left(data, left_top, value)) {
        cout << ' ' << value;
    }
    cout << "\nПравый стек:";
    while (pop_right(data, n, right_top, value)) {
        cout << ' ' << value;
    }
    cout << '\n';
}
