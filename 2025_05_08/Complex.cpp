#include <cstring>
#include <iostream>
class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	Complex& operator=(const Complex& c);
	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};
Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a);
	return temp.operator+(b);
}
Complex::Complex(const char* str) {
		// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
		// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
		// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)
		int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;
	// ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	// ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}
	// ���� 'i' �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;
	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;
	double num = 0.0;
	double decimal = 1.0;
	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // �� �̿��� �̻��� ���ڵ��� �� ���
	}
	if (minus) num *= -1.0;
	return num;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}
int main() {
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	a.println();
}