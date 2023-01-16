# TestTaskSaberInteractive
### Решение тестовых заданий

####  Задание 1. Напишите функцию, которая принимает на вход знакомое целое число и печатает его двоичное представление.
Решение: 
BinaryRepresentation.h
#### Задание 2. Напишите функцию, удаляющие последовательно дублирующиеся символы в строке char*.

Решение:
removedups.h

#### Задание 3. Реализуйте функции сериализации и десериализации двухсвязного списка. Данные должны быть записаны в бинарном формате. Ожидаемая алгоритмическая сложность - меньше квадратичной.
```// структуру ListNode модифицировать нельзя
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
    // ...ваши методы для заполнения списка
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int count = 0;
};
```
Решение: 
Класс List
    
