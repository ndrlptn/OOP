#include <iostream>
#include <limits>


const int N = 3, M = 1;


void sort(double** matrix);
void makeMatrix(double** &matrix);
void printMatrix(double** matrix);


int main()
{
	double** matrix = new double*[N];
	
	makeMatrix(matrix);
	printMatrix(matrix);

	sort(matrix);
	printMatrix(matrix);

}


void makeMatrix(double** &matrix)
{
	double val;

	for (int i = 0; i < N; ++i)
	{
		double* vector = new double[M];

		for (int j = 0; j < M; ++j)
		{
			std::cout << "input value: ";
			std::cin >> val;
			while (std::cin.fail())
			{
				std::cout << "Input correct x: \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> val;

			}
			*vector = val;
			++vector;
		}
		*matrix = vector - M;
		++matrix;
	}
	matrix = matrix - N;
}

void printMatrix(double** matrix)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cout << **matrix << ' ';
			++*matrix;
		}
		*matrix = *matrix - M;
		++matrix;
		std::cout << '\n';
	}
	std::cout << '\n';
	matrix = matrix - N;
}

void sort(double** matrix)
{
	double** arrow = matrix;

	for (int i = 0; i < N; ++i)
	{
		arrow = matrix + i;
		for (int j = i + 1; j <= N - 1; ++j)
		{
			
			double** arrow1 = matrix + j;

			if (**arrow > **arrow1)
			{
				for (int k = 0; k < M; ++k)
				{
					double memory = **arrow;

					*(*(matrix + i) + k) = *(*(matrix + j) + k);
					*(*(matrix + j) + k) = memory;
				}
			}
		}
	}
	
}
