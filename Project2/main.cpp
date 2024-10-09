#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
bool is_prime(T num)
{

	for (size_t i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	
	return true;
}

template <typename T>
void fill_arr(T* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

template <typename T>
void print_arr(T* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void push_back(T*& arr, int& size, T value) {
	T* new_arr = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[size] = value;
	delete[] arr;
	arr = new_arr;
	size++;
}

template <typename T>
T* get_primes(T* arr, int size, int& new_size) {
	new_size = 0;
	T* new_arr = new T[new_size];

	for (size_t i = 0; i < size; i++)
	{
		if (is_prime(arr[i])) push_back(new_arr, new_size, arr[i]);
	}
	return new_arr;
}


int main()
{
	srand(time(0));

	int size;
	cout << "Enter the size of the array: ";
	cin >> size;

	int* arr = new int[size];
	fill_arr(arr, size);
	print_arr(arr, size);

	system("pause");

	int new_size;
	int* primes = get_primes(arr, size, new_size);
	print_arr(primes, new_size);

	delete[] arr;
	delete[] primes;
	return 0;
}