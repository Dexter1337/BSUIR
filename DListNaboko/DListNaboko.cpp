#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>

double f(double x) {
	// функция, минимум которой ищем
	return x * x - 2 * x + 1;
}

double golden_section(double a, double b, double epsilon) {
	double d = (3 - sqrt(5)) / 2; // золотое сечение
	double x1 = b - d * (b - a);
	double x2 = a + d * (b - a);
	while (fabs(b - a) > epsilon) {
		if (f(x1) < f(x2)) {
			b = x2;
			x2 = x1;
			x1 = b - d * (b - a);
		}
		else {
			a = x1;
			x1 = x2;
			x2 = a + d * (b - a);
		}
	}
	return (a + b) / 2;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	try {
		/*std::ifstream input("input.txt");
		if (!input) {
			std::cerr << "Не удалось открыть файл\n";
			return 1;
		}
		double a, b, epsilon;
		input >> a >> b >> epsilon;

		if (epsilon >= 0)
		{
			double minimum = golden_section(a, b, epsilon);
			std::cout << "Минимум функции: " << minimum << '\n';
		}
		else
			std:: cout << "Недопустимые значения";*/
		double a = 0, b = 5, eps = 0.001;
		double min_x = golden_section(a, b, eps);
		std::cout << "Minimum point: (" << min_x << ", "<< f(min_x) << ")" << std::endl;
		return 0;
		
	}
	catch (std::exception& e) {
		std::cerr << "Ошибка: " << '\n';
		return 1;
	}
	return 0;
}
