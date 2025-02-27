//10845 큐 - C++17
//메모리 : 2288KB / 시간 : 452ms
//2023년 8월 6일 11:59:18

#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
    int data;
    Node* nextNode;
    Node* prevNode;
} Node;

class queue {
    int queueSize;
    public :
    Node* headNode;
    Node* tailNode;
    queue() {
        queueSize = 0;
        headNode = new Node;
        tailNode = new Node;
        headNode->data = -1;
        tailNode->data = -1;
        headNode->prevNode = NULL;
        tailNode->prevNode = headNode;
        headNode->nextNode = tailNode;
        tailNode->nextNode = NULL;
    }
    ~queue() {
        Node* tempNode = headNode;
        Node* delNode = tempNode;
        while(tempNode != tailNode) {
            delNode = tempNode;
            tempNode = tempNode->nextNode;
            delete delNode;
        }
        delete tempNode;
    }
    int returnSize() {
        return queueSize;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        tailNode->prevNode->nextNode = newNode;
        newNode->prevNode = tailNode->prevNode;
        newNode->nextNode = tailNode;
        tailNode->prevNode = newNode;
        queueSize = queueSize + 1;
    }
    int pop() {
        if(queueSize == 0) {
            return -1;
        }
        Node* delNode = headNode->nextNode;
        int data = headNode->nextNode->data;
        headNode->nextNode->nextNode->prevNode = headNode;
        headNode->nextNode = headNode->nextNode->nextNode;
        delete delNode;
        queueSize = queueSize - 1;
        return data;
    }
    void printQueue() {
        if(queueSize == 0) {
            // cout << "null" << endl;
            printf("null\n");
        }
        else {
            Node* tempNode = headNode;
            while(tempNode != tailNode) {
                cout << tempNode->data << " ";
                tempNode = tempNode->nextNode;
            }
            cout << tempNode->data << endl;
        }
    }
};

int main() {
    queue queue;
    int n;
    string cmd;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> cmd;
        if(cmd == "push") {
            int data;
            cin >> data;
            queue.push(data);
            // cout << "push" << data;
        }
        else if(cmd == "pop") {
            // cout << queue.pop() << endl;
            printf("%d\n", queue.pop());
        }
        else if(cmd == "size") {
            // cout << queue.returnSize() << endl;
            printf("%d\n", queue.returnSize());
        }
        else if(cmd == "empty") {
            if(queue.returnSize() == 0) {
                // cout << "1" << endl;
                printf("1\n");
            }
            else {
                // cout << "0" << endl;
                printf("0\n");
            }
        }
        else if(cmd == "front") {
            // cout << queue.headNode->nextNode->data << endl;
            printf("%d\n", queue.headNode->nextNode->data);
        }
        else if(cmd == "back") {
            // cout << queue.tailNode->prevNode->data << endl;
            printf("%d\n", queue.tailNode->prevNode->data);
        }
    }
    return 0;
}