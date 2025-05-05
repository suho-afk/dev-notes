#include<iostream>

int main()
{
	//C++StyleMemoryAllocation
	int *a = new int;
	*a = 3;
	std::cout << a << std::endl;
	delete a;

	int arr_size;
	std::cin >> arr_size;
	int* arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << arr[i] << std::endl;
	}
	delete[] arr;
	return 0;

}