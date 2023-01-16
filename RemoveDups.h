#include <cstdio>

// �������, ��������� ������������� ������� � ������                       
// str - ������
void RemoveDups(char* str)
{
	if (str != nullptr)
	{
		int writePos = 0; // ������� ��� ������ ������ �������� ������
		if (str[writePos] != '\0') {
			// �������� �� ���� ��������� ������ �� � �����
			for (int readPos = 1; str[readPos] != '\0'; readPos++) {
				// ������ ������ ����������� ��������
				if (str[readPos] != str[writePos])
				{
					writePos++;
					str[writePos] = str[readPos];
				}
			}
			// ���������� ������� ��������� ������
			str[++writePos] = '\0';
		}
	}
}