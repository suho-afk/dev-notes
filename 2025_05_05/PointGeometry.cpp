#include<iostream>

class Point {
	
public:
	int x, y;
	Point(int pos_x, int pos_y);
	int EvalLine(int a, int b, int c) const;
};

Point::Point(int pos_x, int pos_y)
{
	x = pos_x;
	y = pos_y;
}

int Point::EvalLine(int a, int b, int c) const
{
	return a * x + b * y + c;
}

class Geometry {
	// 점 100 개를 보관하는 배열.
	Point* point_array[100];
public:
	Geometry(Point** point_list);
	Geometry();
	void AddPoint(const Point& point);

	int max_idx;
	// 모든 점들 간의 거리를 출력하는 함수 입니다.
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
	// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
	// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
	// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
	void PrintNumMeets();

	float CaluculateDistance(Point* p1, Point* p2);
};

Geometry::Geometry(Point** point_list)
{
	max_idx = 0;
	for (int i = 0; i < 100; i++)
	{
		if (point_list[i] == 0) break;
		point_array[i] = point_list[i];
		max_idx++;
	}
}

Geometry::Geometry()
{
	max_idx = 0;
	for (int i = 0; i < 100; i++) point_array[i] = 0;
}

void Geometry::AddPoint(const Point& point)
{
	point_array[max_idx] = new Point(point);
	max_idx++;
}

void Geometry::PrintDistance()
{
	for (int i = 0; i < max_idx; i++)
	{
		for (int j = i+1; j < max_idx; j++)
		{
			std::cout << CaluculateDistance(point_array[i], point_array[j]) << std::endl;
		}
	}
}

void Geometry::PrintNumMeets()
{
	int count = 0;

	for (int i = 0; i < max_idx; i++) {
		for (int j = i + 1; j < max_idx; j++) {
			// 직선 (i, j)를 기준으로 잡고
			int a = point_array[i]->x - point_array[j]->y;
			int b = point_array[j]->x - point_array[i]->y;
			int c = -(a * point_array[i]->x + b * point_array[i]->y);

			for (int k = 0; k < max_idx; k++) {
				for (int l = k + 1; l < max_idx; l++) {
					if (k == i || k == j || l == i || l == j) continue;

					int v1 = point_array[k]->EvalLine(a, b, c);
					int v2 = point_array[l]->EvalLine(a, b, c);

					if (v1 * v2 <= 0) {
						count++;
					}
				}
			}
		}
	}
	std::cout << "직선들 간의 교점 수: " << count / 2 << "\n"; // 중복 계산 제거
}

float Geometry::CaluculateDistance(Point* p1, Point* p2)
{
	float distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
	return distance;
}

int main()
{
	Geometry geo;
	geo.AddPoint(Point(0, 0));
	geo.AddPoint(Point(2, 2));
	geo.AddPoint(Point(2, 0));
	geo.AddPoint(Point(0, 2));

	geo.PrintDistance();
	geo.PrintNumMeets();
}