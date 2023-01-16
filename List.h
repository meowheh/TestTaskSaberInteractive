#ifndef LIST_H
#define LIST_H

// Задание 3. Реализуйте функции сериализации и десериализации двухсвязного списка.
// Данные должны быть записаны в бинарном формате. Ожидаемая алгоритмическая сложность - меньше квадратичной.

#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstdio>
#include <string>

// структура ListNode
struct ListNode {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    std::string data;
};

class List {
public:
    // сохранение списка в файл, файл открыт с помощью 'fopen(path, "wb"'
    void Serialize(FILE* file);  
    // восстановление списка из файла, файл открыт с помощью 'fopen(path, "rb")'
    void Deserialize(FILE* file);
    // добавление нового элемента в конец списка
    void Add(std::string data); 
    // Очистка списка
    void Clear();    
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int count = 0;
};

#endif // LIST_H