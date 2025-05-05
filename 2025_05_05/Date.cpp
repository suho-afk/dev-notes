#include <iostream>

//����� C++ p73 ����

class Date {
	int year_;
	int month_; // 1 ���� 12 ����.
	int day_; // 1 ���� 31 ����.
public:
	Date(int year, int month, int date);
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	int GetCurrentMonthTotalDays(int year, int month);
	void AddMonth(int inc);
	void AddYear(int inc);
	void ShowDate();
};

//������
Date::Date(int year, int month, int date)
{
	year_ = year;
	month_ = month;
	day_ = date;
}

void Date::SetDate(int year, int month, int date)
{
	year_ = year;
	month_ = month;
	day_ = date;
}

void Date::AddDay(int inc)
{
	while (true)
	{
		int result_day = day_+inc;

		// ���� ���� �� �� ��
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		if (result_day <= current_month_total_days)
		{
			day_ = result_day;
			return;
		}
		else
		{
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

//������ ������ �� �޿� �����Ҽ� �ִ� ���� ���� �����ϴ� �Լ�
int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; // ����
	}
	else {
		return 28;
	}
}

void Date::AddMonth(int inc)
{
	//���� ��
	int result_month = month_ + inc;

	if (result_month > 12)
	{
		result_month = result_month - 12;
		month_ = result_month;
		AddYear(1);
	}
	else
	{
		month_ = result_month;
	}
}

void Date::AddYear(int inc)
{
	year_ = year_ + inc;
}

void Date::ShowDate()
{
	std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
		<< " �� �Դϴ� " << std::endl;
}

int main()
{
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();
	day.AddDay(30);
	day.ShowDate();
	day.AddDay(2000);
	day.ShowDate();
	day.SetDate(2012, 1, 31); // ����
	day.AddDay(29);
	day.ShowDate();
	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;
}