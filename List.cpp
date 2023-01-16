#include "List.h"

    // ���������� ������ � ����, ���� ������ � ������� 'fopen(path, "wb"'
void List::Serialize(FILE* file)
{
    if (file) {
        std::unordered_map<ListNode*, int> id;   //���-������� ������������ �������� � ��� �������
        int idCount = 0;
        // ����������� ������� �������� ���� �����
        for (ListNode* node = head; node != nullptr; node = node->next)
        {
            std::pair<ListNode*, int> temp(node, idCount);
            idCount++;
            id.insert(temp);
        }
        // ������ ������ ���������� ��������� ������
        fwrite((const void*)&count, sizeof(count), 1, file);
        for (ListNode* node = head; node != nullptr; node = node->next) {
            size_t sizeData = node->data.size();
            // ������ ������� ������ ������
            fwrite((const void*)&sizeData, sizeof(size_t), 1, file);
            // ������ ������ ������
            fwrite((const void*)node->data.c_str(), sizeData, 1, file);
        }
        // ������ ������� ��������� ���� rand
        for (ListNode* node = head; node != nullptr; node = node->next) {
            int randId = (node->rand) ? id[node->rand] : -1;
            fwrite((const void*)&randId, sizeof(int), 1, file);
        }
    }
}
// �������������� ������ �� �����, ���� ������ � ������� 'fopen(path, "rb")'
void List::Deserialize(FILE* file)
 {
    if (file)
    {
        Clear();
        // ������ ������ ���������� ��������� ������
        int newCount = -1;
        fread(&newCount, sizeof(int), 1, file);
        if (newCount > 0)
        {
            std::vector<ListNode*> nodes;
            for (int currentId = 0; currentId < newCount; currentId++)
            {
                size_t size = 0;
                std::string data;
                // ������ ������� ������
                fread((void*)&size, sizeof(size_t), 1, file);
                if (size > 0) {
                    data.resize(size);
                    // ������ ������
                    fread((void*)&data[0], size, 1, file);
                    // �������� �������� �����
                    Add(data);
                    nodes.push_back(tail);
                }
            }
            for (ListNode* node = head; node != nullptr; node = node->next)
            {
                // ������ ��������� rand
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
// ���������� ������ �������� � ����� ������
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
 // ������� ������
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

