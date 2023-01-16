#include <cstdio>

// функция, удаляющая дублирующиеся символы в строке                       
// str - строка
void RemoveDups(char* str)
{
	if (str != nullptr)
	{
		int writePos = 0; // позиция для записи нового элемента строки
		if (str[writePos] != '\0') {
			// проходим по всем элементам строки до её конца
			for (int readPos = 1; str[readPos] != '\0'; readPos++) {
				// запись нового уникального элемента
				if (str[readPos] != str[writePos])
				{
					writePos++;
					str[writePos] = str[readPos];
				}
			}
			// добавление символа окончания строки
			str[++writePos] = '\0';
		}
	}
}