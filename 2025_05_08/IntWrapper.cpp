#include <iostream>
class Int {
	int data;
	// some other data
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	operator int() { return data; }
};
int main() {
	Int x = 3;
	int a = x + 4;
	x = a * 2 + x + 4;
	std::cout << x << std::endl;
}