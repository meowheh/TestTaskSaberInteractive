#include <iostream>

// Функция вывода на экран двоичного представления целого знакового числа
// num - целое число
void BinaryRepresentation(int num)
{
	const int BITS = 8;
	// проход по всем битам числа
	for (int bit = sizeof(num) * BITS - 1; bit >= 0; --bit) {
		std::cout << static_cast<int>((num >> bit) & 1);
	};
	std::cout << std::endl;
}
