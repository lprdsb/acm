#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// 创建链表
Node* createLinkedList() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    std::cout << "请输入链表的长度：";
    std::cin >> n;

    std::cout << "请输入" << n << "个节点的值：" << std::endl;
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// 逆转链表
Node* reverseLinkedList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

// 打印链表
void printLinkedList(Node* head) {
    // cout << "asd" << endl;
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // 创建链表
    Node* head = createLinkedList();

    // 打印原始链表
    std::cout << "原始链表：";
    printLinkedList(head);

    // 逆转链表
    Node* reversedHead = reverseLinkedList(head);

    // 打印逆转后的链表
    std::cout << "逆转后的链表：";
    printLinkedList(reversedHead);

    return 0;
}