#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// ��������
Node* createLinkedList() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    std::cout << "����������ĳ��ȣ�";
    std::cin >> n;

    std::cout << "������" << n << "���ڵ��ֵ��" << std::endl;
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

// ��ת����
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

// ��ӡ����
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
    // ��������
    Node* head = createLinkedList();

    // ��ӡԭʼ����
    std::cout << "ԭʼ����";
    printLinkedList(head);

    // ��ת����
    Node* reversedHead = reverseLinkedList(head);

    // ��ӡ��ת�������
    std::cout << "��ת�������";
    printLinkedList(reversedHead);

    return 0;
}