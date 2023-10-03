#include <iostream>
#include <cmath>
const int N = 1000;
void correct(int N, double mas[1000])
{
	for (int index = 0; index < N; ++index)
	{
		if (mas[index])
		{
			mas[index] = 0;
		}
	}
	return;
}
void writeelem(int n, double mas[N])
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> mas[i];
	}
	return;
}
void rand1(int n, double  mas[N], int a, int b)
{
	for (int i = 0; i < n; ++i)
	{
		mas[i] = rand() % (b - a) + a;
	}
	return;
}
void rand2(int n, double  mas[N], int a, int b)
{
	for (int i = 0; i < n; ++i)
	{
		mas[i] = rand() % (a - b) + b;
	}
	return;
}
int main()
{
	double mas[N];
	int n = 0,b = 0, a = 0, mode = 0;
	double max = 0;
	std::cout << " Write number: " << '\n';
	std::cin >> n;
	correct(N, mas);
	if (n < 1)
	{
		std::cout << " Uncorrect number " << '\n';
	}
	else
	{
		std::cout << " choose elements ( press 1 ) or random elements ( press 2 ) " << '\n';
		std::cin >> mode;
		switch (mode)
		{
		case 1:
			std::cout << " Write array elements: " << '\n';
			writeelem(n, mas);
			break;
		case 2:
			std::cout << " Write diapazon: " << '\n';
			std::cout << " Input min " << '\n';
			std::cin >> a;
			std::cout << " Input max " << '\n';
			std::cin >> b;
			if (a < b)
			{
				rand1(n, mas, a, b);
			}
			else
			{		
				rand2(n, mas, a, b);
			}
			break;
		default:
			std::cout << " Wrong command " << '\n';
			return false;
			break;
		}
		std::cout << " Current array: ";
		for ( int i = 0; i < n; ++i)
		{
			std::cout << mas[i] << " ";
		}
		std::cout << '\n';
		max = mas[0];
		for (int i = 0; i < n; ++i)
		{
			if (max < mas[i])
			{
				max = mas[i];
			}
		}

		int MaxLength = 1;
		int CurrentLength = 1;
		for (int i = 1; i < n; ++i) 
		{
			if (mas[i] != mas[i - 1]) 
			{
				++CurrentLength;
			}
			else 
			{
				if (CurrentLength > MaxLength)
				{
					MaxLength = CurrentLength;
				}
				CurrentLength = 1;
			}
		}
		if (CurrentLength > MaxLength)
		{
			MaxLength = CurrentLength;
		}
		std::cout << " The longest: " << MaxLength << '\n';

		int lastnegative = -1;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (mas[i] < 0)
			{
				lastnegative = i;
			}
		}
		if (lastnegative != -1)
		{
			for (int i = lastnegative + 1; i < n; i++)
			{
					sum += floor(mas[i]);
			}
			std::cout << " Summa of elements after last negative: " << sum << '\n';
		}
		else
		{
			std::cout << " No negative elements " << '\n';
		}

		int count = 0;
		for (int i = 0; i <= n; ++i)
		{
			if (max >= 0)
			{
				if (mas[i] >= max * 0.8)
				{
					for (int k = i; k > count; --k)
					{
						std::swap(mas[k - 1], mas[k]);
					}
					++count;
				}
			}
			else
			{
				if (mas[i] >= max * 1.2)
				{
					for (int k = i; k > count; --k)
					{
						std::swap(mas[k - 1], mas[k]);
					}
					++count;
				}
			}
		}
		std::cout << " Formed array: ";
		for (int i = 0; i < n; ++i)
		{
			std::cout << mas[i] << " ";
		}
	}
	return 0;
}