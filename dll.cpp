#include<iostream>
using namespace std;

// 双向链表节点定义
struct DblLinkNode
{
    int data;
    DblLinkNode* next;
    DblLinkNode* prev;
    
    DblLinkNode():next(nullptr), prev(nullptr) {}  // 默认构造函数
    DblLinkNode(int val): data(val), next(nullptr), prev(nullptr) {}  // 自定义构造函数
};

// 双向链表类
class DblLinkList
{
public:
    DblLinkNode* head;  // 头指针
    DblLinkNode* tail;  // 尾指针

    DblLinkList()  // 构造函数，初始化头尾指针
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // 获取第n个节点
    DblLinkNode* getn(int n)
    {
        DblLinkNode* temp = head;
        for(int i = 0; i < n && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    // 在第i个位置插入元素e
    void insert(int i, int e)
    {
        DblLinkNode* newNode = new DblLinkNode(e);

        // 如果插入到头部（i == 0），特殊处理
        if (i == 0)
        {
            if (head == nullptr)  // 链表为空的情况
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        // 找到第i-1个节点
        DblLinkNode* p = getn(i - 1);
        if (p == nullptr)  // 越界检查
        {
            cout << "Invalid position to insert." << endl;
            delete newNode;
            return;
        }

        newNode->next = p->next;
        newNode->prev = p;

        if (p->next != nullptr)  // 如果p的下一个节点存在，调整前驱
        {
            p->next->prev = newNode;
        }
        else  // 如果插入到尾部，更新tail
        {
            tail = newNode;
        }
        p->next = newNode;
    }

    // 删除第i个位置的节点
    void remove(int i)
    {
        if (head == nullptr) return;  // 链表为空

        // 删除头节点
        if (i == 0)
        {
            DblLinkNode* temp = head;
            if (head->next != nullptr)
            {
                head = head->next;
                head->prev = nullptr;
            }
            else
            {
                head = nullptr;
                tail = nullptr;  // 链表只有一个节点时
            }
            delete temp;
            return;
        }

        // 找到第i个节点
        DblLinkNode* p = getn(i);
        if (p == nullptr)  // 越界检查
        {
            cout << "Invalid position to delete." << endl;
            return;
        }

        if (p->next != nullptr)  // 如果不是尾节点
        {
            p->next->prev = p->prev;
        }
        else  // 如果是尾节点，更新tail
        {
            tail = p->prev;
        }

        p->prev->next = p->next;
        delete p;
    }

    // 获取链表长度
    int getLength()
    {
        int l = 0;
        DblLinkNode* temp = head;
        while (temp != nullptr)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    // 打印链表
    void display()
    {
        DblLinkNode* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 反向打印链表（从尾部到头部）
    void displayReverse()
    {
        DblLinkNode* temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // 析构函数，释放链表内存
    ~DblLinkList()
    {
        while (head != nullptr)
        {
            DblLinkNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DblLinkList list;
    
    list.insert(0, 10);  // 插入10到第0个位置
    list.insert(1, 20);  // 插入20到第1个位置
    list.insert(2, 30);  // 插入30到第2个位置
    list.insert(1, 15);  // 插入15到第1个位置
    
    cout << "Initial list: ";
    list.display();

    cout << "Reversed list: ";
    list.displayReverse();

    list.remove(1);  // 删除第1个位置的节点
    cout << "After removing element at index 1: ";
    list.display();

    cout << "List length: " << list.getLength() << endl;

    return 0;
}
