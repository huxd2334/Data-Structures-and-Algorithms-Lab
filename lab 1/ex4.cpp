#include <bits/stdc++.h>
using namespace std;

void input(int* &arr, int size);
void display(int* arr, int size);

int main() {
    int size;
    int* arr;

    cout << "Enter array size: ";
    cin >> size;
    input(arr, size);
    
    cout << "The array is: ";
    display(arr, size);

    delete[] arr;

    return 0;
}

void input(int* &arr, int size) {
    arr = new int[size];

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
