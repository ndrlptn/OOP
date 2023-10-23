#include <iostream>
#include <cmath>
#include <limits>

const double pi = 3.14159;


double foo(double x, int n);


int main()
{
	double x;
	int n;
	std::cout << "Input x: \n";
	std::cin >> x;
	while (std::cin.fail())
	{
		std::cout << "Input correct x: \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> x;
		
	}
	

	std::cout << "input n: \n" << '\n';
	std::cin >> n;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input correct n: \n";
		std::cin >> n;
	}
	

	double y = 0;

	y = foo(x, n);

	std::cout << y;
	return 0;
}


double foo(double x, int n)
{
	double y = 0;
	double m = 1; //multiplication result

	y =  sin(pi);

	for (int k = 5; k < n; ++k)
	{
		m = m * ( 1 + (x * std::log(k)) / ( (x + 1) / (1 + std::pow(k,2)) ) );
	}

	y = y + m;

	return y;
}