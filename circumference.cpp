#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int main()
{
	random_device rd;
	mt19937 gen(rd());

	int num_divisions = -1;
	cout << "Enter number of divisions of the circle: ";
	cin >> num_divisions;
	
	double alpha = PI / num_divisions;
	int num_points = 10000000;
	int num_points_trapezoid = 0;

	
	uniform_real_distribution<> dist_x(0, tan(alpha));
	uniform_real_distribution<> dist_y(0, 1.0);


	for (int i = 0; i < num_points; ++i)
	{
		double x = dist_x(gen);
		double y = dist_y(gen);

		double theta = atan(y / x);

		if (PI / 2 - theta > alpha)
			continue;

		if (y > cos(alpha))
			num_points_trapezoid++;
	}
	cout << num_points_trapezoid << '\n';
	
	double area = tan(alpha) * (double(num_points_trapezoid) / double(num_points));

	double h = 1 - cos(alpha);

	double length = 2 * num_divisions * (area / h);
	 
	cout << length;
	return 0;
}