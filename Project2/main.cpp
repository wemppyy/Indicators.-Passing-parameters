#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void print_array(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T* init_arr(int size) {
    if (size == 0) {
        return nullptr;
    }
    T* arr = new T[size];
    return arr;
}

template <typename T>
void push_back(T*& arr, int& size, T value) {
    T* new_arr = new T[size + 1];
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[size] = value;
    size++;
    delete[] arr;
    arr = new_arr;
}

template <typename T>
void distribute_array(T arr[], int size, T*& positive, int& positive_size, T*& negative, int& negative_size, T*& zero, int& zero_size) {
    positive_size = 0;
    negative_size = 0;
    zero_size = 0;
    positive = init_arr<T>(positive_size);
    negative = init_arr<T>(negative_size);
    zero = init_arr<T>(zero_size);

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            push_back(positive, positive_size, arr[i]);
        }
        else if (arr[i] < 0) {
            push_back(negative, negative_size, arr[i]);
        }
        else {
            push_back(zero, zero_size, arr[i]);
        }
    }
}

int main()
{
    srand(time(0));

    const int size = 20;

    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20 - 10;
    }

    print_array(arr, size);

    int positive_size, negative_size, zero_size;
    int* positive;
    int* negative;
    int* zero;

	system("pause");

    distribute_array(arr, size, positive, positive_size, negative, negative_size, zero, zero_size);

    cout << "Positive: ";
    print_array(positive, positive_size);
    cout << "Negative: ";
    print_array(negative, negative_size);
    cout << "Zero: ";
    print_array(zero, zero_size);

    delete[] positive;
    delete[] negative;
    delete[] zero;

    return 0;
}
