#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
T* allocate(int size)
{
	return new T[size];
}

template <typename T>
T* init_arr(int size) {
	T* arr = allocate<T>(size);
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	return arr;
}

template <typename T>
void fill_arr(T*& arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

template <typename T>
void print_arr(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void delete_arr(T* arr) {
	delete[] arr;
}

template <typename T>
void push_back(T*& arr, int& size, T value) {
	T* new_arr = init_arr<T>(size + 1);
	for (size_t i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = value;
	delete_arr(arr);
	arr = new_arr;
	size++;
}

template <typename T>
void insert(T*& arr, int& size, int index, T value) {
	T* new_arr = init_arr<T>(size + 1);
	for (size_t i = 0; i < index; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[index] = value;
	for (size_t i = index; i < size; i++)
	{
		new_arr[i + 1] = arr[i];
	}
	delete_arr(arr);
	arr = new_arr;
	size++;
}

template <typename T>
void remove(T*& arr, int& size, int index) {
	T* new_arr = init_arr<T>(size - 1);
	for (size_t i = 0; i < index; i++)
	{
		new_arr[i] = arr[i];
	}
	for (size_t i = index; i < size - 1; i++)
	{
		new_arr[i] = arr[i + 1];
	}
	delete_arr(arr);
	arr = new_arr;
	size--;
}

int main()
{
	srand(time(0));

	int size, push_back_value, insert_value, insert_index, delete_index;
	cout << "Enter size of array: ";
	cin >> size;

	int* arr = init_arr<int>(5);
	fill_arr(arr, size);
	print_arr(arr, size);

	cout << "Enter value to push back: ";
	cin >> push_back_value;
	push_back(arr, size, push_back_value);
	print_arr(arr, size);

	cout << "Enter value to insert: ";
	cin >> insert_value;
	cout << "Enter index to insert: ";
	cin >> insert_index;
	insert(arr, size, insert_index, insert_value);
	print_arr(arr, size);

	cout << "Enter index to delete: ";
	cin >> delete_index;
	remove(arr, size, delete_index);
	print_arr(arr, size);

	delete_arr(arr);
	return 0;
}