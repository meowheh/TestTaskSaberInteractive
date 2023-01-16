#ifndef LIST_H
#define LIST_H

// ������� 3. ���������� ������� ������������ � �������������� ������������ ������.
// ������ ������ ���� �������� � �������� �������. ��������� ��������������� ��������� - ������ ������������.

#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstdio>
#include <string>

// ��������� ListNode
struct ListNode {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    std::string data;
};

class List {
public:
    // ���������� ������ � ����, ���� ������ � ������� 'fopen(path, "wb"'
    void Serialize(FILE* file);  
    // �������������� ������ �� �����, ���� ������ � ������� 'fopen(path, "rb")'
    void Deserialize(FILE* file);
    // ���������� ������ �������� � ����� ������
    void Add(std::string data); 
    // ������� ������
    void Clear();    
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int count = 0;
};

#endif // LIST_H