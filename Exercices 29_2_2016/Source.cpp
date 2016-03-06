#include <iostream>

using namespace std;

class Point{
public:
	float x;
	float y;
	bool IsZero();
	Point SetZero();
	Point Negate(Point& a);
	Point operator+(const Point&);
	Point operator-(const Point& a);
	Point operator-=(const Point& a);
	Point operator+=(const Point& a);
	bool operator==(const Point& a);
	bool operator!=(const Point& a);
};

bool Point::IsZero(){
	return (Point::x == 0 && Point::y == 0);
};
Point Point::SetZero(){
	Point tmp;
	tmp.x = 0;
	tmp.y = 0;
	return tmp;
}
Point Point::Negate(Point&){
	Point tmp;
	tmp.x = 0 - x;
	tmp.y = 0 - y;
	return tmp;
}
Point Point::operator+(const Point& other_point){
	Point tmp;
	tmp.x = x + other_point.x;
	tmp.y = y + other_point.y;
	return tmp;
}
Point Point::operator-(const Point& other_point){
	Point tmp;
	tmp.x = x - other_point.x;
	tmp.y = y - other_point.y;
	return tmp;
}
Point Point::operator-=(const Point& other_point){
	Point tmp;
	tmp.x = x - other_point.x;
	tmp.y = y - other_point.y;
	return tmp;
}
Point Point::operator+=(const Point& other_point){
	Point tmp;
	tmp.x = x + other_point.x;
	tmp.y = y + other_point.y;
	return tmp;
}
bool Point::operator==(const Point& other_point){
	if (x == other_point.x && y == other_point.y)
		return true;
	else
		return false;
}
bool Point::operator!=(const Point& other_point){
	if (x == other_point.x && y == other_point.y)
		return false;
	else
		return true;
}



int main(){
	Point p;
	Point o_p;
	int operation;
	float res;

	cout << "Give me an x and a y: " << std::endl;
	std::cin >> p.x;
	std::cin >> p.y;
	std::cout << "What operation do you want to do?\n1.\tIs Zero\n2.\tSet Zero\n3.\tNegate\n4.\t+\n5.\t-\n6.\t-=\n7.\t+=\n8.\t==\n9.\t!=" << std::endl;
	std::cin >> operation;
	
	switch (operation)
	{
	case 1:
		if (p.IsZero()) std::cout << "true" << endl;
		else std::cout << "false" << endl;
		break;
	case 2:
		p = p.SetZero();
		break;
	case 3:
		p = p.Negate(p);
		break;
	case 4:
		cin >> o_p.x;
		cin >> o_p.y;
		p = p.operator+(o_p);
		break;
	case 5:
		cin >> o_p.x;
		cin >> o_p.y;
		p = p.operator-(o_p);
		break;
	case 6:
		cin >> o_p.x;
		cin >> o_p.y;
		p = p.operator-=(o_p);
		break;
	case 7:
		cin >> o_p.x;
		cin >> o_p.y;
		p = p.operator+=(o_p);
		break;
	case 8:
		cin >> o_p.x;
		cin >> o_p.y;
		if (p.operator==(o_p)) std::cout << "true" << endl;
		else std::cout << "false" << endl;
		break;
	case 9:
		cin >> o_p.x;
		cin >> o_p.y;
		if (p.operator!=(o_p)) std::cout << "true" < endl;
		else std::cout << "false" << endl;
		break;
	default:
		break;
	}
	
	std::cout << p.x << " " << p.y << endl;

	system("pause");
	return 0;
}