#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int number_of_points;
    cout << "Enter number of points: ";
    cin >> number_of_points;

    double pi;
    int number_of_hits;
    double x, y;

    number_of_hits=0;
    x = 0;
    y = 0;

    srand(time(0));
    for (int j = 0; j < number_of_points; j++)
    {
        x = double(rand()) / double(RAND_MAX);
        y = double(rand()) / double(RAND_MAX);

        if(y <= sqrt(1 - (x*x)))
            number_of_hits++;
    }

    pi = 4 * (double(number_of_hits) / double(number_of_points));
    cout <<  fixed << setprecision(10) << pi << endl;


    return 0;
}