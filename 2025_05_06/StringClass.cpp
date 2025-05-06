#include<iostream>
#include<string.h>

//아래와 같은 문자열 클래스를 완성해보세요
class MyString{
	
public:
	char* str;
	int len;
	MyString(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
	MyString(const char* s);
	MyString(const MyString& s);
	~MyString();
	void add_string(const MyString& s); // str 뒤에 s 를 붙인다.
	void copy_string(const MyString& s); // str 에 s 를 복사한다.
	int get_len(); // 문자열 길이 리턴
};

MyString::MyString(char c, int n)
{
	//char의 배열이기 때문에 마지막은 \n로 비워둬야함.
	str = new char[n+1];

	for (int i = 0; i < n; i++)
	{
		str[i] = c;
		len++;
	}
	str[len] = '\0';
}

MyString::MyString(const char* s)
{
	len = strlen(s);
	str = new char[len+1];
	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}
	str[len] = '\0';
}

//복사생성자
MyString::MyString(const MyString& s)
{
	len = s.len;
	str = new char[len+1];
	for (int i = 0; i < len; i++)
		str[i] = s.str[i];
	str[len] = '\0';
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::add_string(const MyString& s)
{
	int new_len = len + s.len;
	char* new_str = new char[new_len + 1];

	for (int i = 0; i < len; ++i) {
		new_str[i] = str[i];
	}
	for (int i = 0; i < s.len; ++i) {
		new_str[len + i] = s.str[i];
	}
	new_str[new_len] = '\0';

	delete[] str;
	str = new_str;
	len = new_len;
}

void MyString::copy_string(const MyString& s)
{
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		str[i] = s.str[i];
	}
	str[len] = '\0';
}

int MyString::get_len()
{
	return len;
}

int main()
{
	MyString a('s', 3);
	MyString b(a);
	std::cout << b.str;
}