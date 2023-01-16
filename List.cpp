#include "List.h"

    // сохранение списка в файл, файл открыт с помощью 'fopen(path, "wb"'
void List::Serialize(FILE* file)
{
    if (file) {
        std::unordered_map<ListNode*, int> id;   //хеш-таблица соответствия элемента с его номером
        int idCount = 0;
        // присваиваем каждому элементу свой номер
        for (ListNode* node = head; node != nullptr; node = node->next)
        {
            std::pair<ListNode*, int> temp(node, idCount);
            idCount++;
            id.insert(temp);
        }
        // запись общего количества элементов списка
        fwrite((const void*)&count, sizeof(count), 1, file);
        for (ListNode* node = head; node != nullptr; node = node->next) {
            size_t sizeData = node->data.size();
            // запись размера строки данных
            fwrite((const void*)&sizeData, sizeof(size_t), 1, file);
            // запись строки данных
            fwrite((const void*)node->data.c_str(), sizeData, 1, file);
        }
        // запись номеров элементов поля rand
        for (ListNode* node = head; node != nullptr; node = node->next) {
            int randId = (node->rand) ? id[node->rand] : -1;
            fwrite((const void*)&randId, sizeof(int), 1, file);
        }
    }
}
// восстановление списка из файла, файл открыт с помощью 'fopen(path, "rb")'
void List::Deserialize(FILE* file)
 {
    if (file)
    {
        Clear();
        // чтение общего количества элементов списка
        int newCount = -1;
        fread(&newCount, sizeof(int), 1, file);
        if (newCount > 0)
        {
            std::vector<ListNode*> nodes;
            for (int currentId = 0; currentId < newCount; currentId++)
            {
                size_t size = 0;
                std::string data;
                // чтение размера строки
                fread((void*)&size, sizeof(size_t), 1, file);
                if (size > 0) {
                    data.resize(size);
                    // чтение строки
                    fread((void*)&data[0], size, 1, file);
                    // создание элемента спика
                    Add(data);
                    nodes.push_back(tail);
                }
            }
            for (ListNode* node = head; node != nullptr; node = node->next)
            {
                // чтение параметра rand
                int randId = -1;
                fread((void*)&randId, sizeof(int), 1, file);
                if (randId >= 0 && randId < count)
                {
                    node->rand = nodes[randId];
                }
            }
        }
    }
}
// добавление нового элемента в конец списка
void List::Add(std::string data)
{
    ListNode* node = new ListNode;
    node->data = data;
    node->next = nullptr;
    node->rand = nullptr;
    node->prev = tail;
    if (tail)
    {
        tail->next = node;
    }
    tail = node;
    if (head == nullptr)
    {
        head = node;
    }
    count++;

}
 // Очистка списка
void List::Clear()
{
    ListNode* node = head;
    while (head)
    {
        head = head->next;
        delete node;
        node = head;
    }
    count = 0;
}

