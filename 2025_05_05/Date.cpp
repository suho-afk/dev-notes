#include <iostream>

//모두의 C++ p73 문제

class Date {
	int year_;
	int month_; // 1 부터 12 까지.
	int day_; // 1 부터 31 까지.
public:
	Date(int year, int month, int date);
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	int GetCurrentMonthTotalDays(int year, int month);
	void AddMonth(int inc);
	void AddYear(int inc);
	void ShowDate();
};

//생성자
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

		// 현재 달의 총 일 수
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

//윤년을 포함한 그 달에 도달할수 있는 날의 값을 리턴하는 함수
int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; // 윤년
	}
	else {
		return 28;
	}
}

void Date::AddMonth(int inc)
{
	//최종 월
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
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
		<< " 일 입니다 " << std::endl;
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
	day.SetDate(2012, 1, 31); // 윤년
	day.AddDay(29);
	day.ShowDate();
	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();
	return 0;
}