#include <iostream>
using namespace std;

// 尾插法
struct Node {
    int data;
    Node* next;

    Node() : next(nullptr) {}
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class LinkList {
public:
    Node* head;

    LinkList() {
        this->head = nullptr;
    }

    LinkList(Node* head) {
        this->head = head;
    }
};

// 修改后的 move 函数，集成合并逻辑
LinkList move(LinkList& L) {
    Node* cur = L.head;

    // 创建两个虚拟头节点，分别用于存储小于0和大于等于0的节点
    Node* Empty=new Node(0,nullptr);//虚拟头节点，避免空链表判断
    LinkList L1(Empty),L2(Empty);

    // 尾指针初始化为虚拟头节点
    Node* tail1 = Empty;
    Node* tail2 = Empty;

    // 遍历原链表，将节点分配到 L1 或 L2
    while (cur != nullptr) {
        Node* s = cur;
        cur = cur->next;
        s->next = nullptr; // 断开当前节点与原链表的连接，防止环

        if (s->data < 0) {
            tail1->next = s;
            tail1 = s; // 更新 L1 的尾指针
        } else {
            tail2->next = s;
            tail2 = s; // 更新 L2 的尾指针
        }
    }

    // 将 L2 链表连接到 L1 链表的尾部
    tail1->next = L2.head->next;

    // 新链表的头节点是 L1 虚拟头节点的下一个节点
    Node* newHead = L1.head->next;



    return LinkList(newHead);
}

void printList(LinkList& L) {
    Node* cur = L.head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    // 创建链表节点
    Node* n1 = new Node{1, nullptr};
    Node* n2 = new Node{-2, nullptr};
    Node* n3 = new Node{3, nullptr};
    Node* n4 = new Node{-4, nullptr};

    // 链接节点
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    LinkList list(n1);

    cout << "origin: ";
    printList(list);

    // 调用 move 函数
    list = move(list);

    cout << "adjusted: ";
    printList(list);

    // 释放原始节点的内存（如果不再需要）
    // 注意：此处没有完全释放所有节点的内存，建议在实际使用中添加内存清理代码

    return 0;
}
