//10828 스택 - C++17
//메모리 : 2288KB / 시간 : 348ms
//2023년 8월 7일 23:18:07

#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
    int data;
    Node* prevNode;
    Node* nextNode;
} Node;

class stack {
    int stackSize;
    public:
    Node* headNode;
    Node* tailNode;
    stack() {
        stackSize = 0;
        headNode = new Node;
        tailNode = new Node;
        headNode->data = -1;
        tailNode->data = -1;
        headNode->prevNode = NULL;
        headNode->nextNode = tailNode;
        tailNode->prevNode = headNode;
        tailNode->nextNode = NULL;
    }
    ~stack() {
        Node* tmpNode = headNode;
        Node* delNode = tmpNode;
        while(tmpNode != tailNode) {
            delNode = tmpNode;
            tmpNode = tmpNode->nextNode;
            delete delNode;
        }
        delete tmpNode;
    }
    int returnSize() {
        return stackSize;
    }
    void push(int data) {
        Node* newNode = new Node;
        stackSize += 1;
        newNode->data = data;
        newNode->prevNode = headNode;
        newNode->nextNode = headNode->nextNode;
        headNode->nextNode->prevNode = newNode;
        headNode->nextNode = newNode;
    }
    int pop() {
        if(stackSize == 0) {
            // printf("-1\n");
            return -1;
        }
        else {
            Node* delNode = headNode->nextNode;
            int data = headNode->nextNode->data;
            stackSize -= 1;
            headNode->nextNode->prevNode = headNode;
            headNode->nextNode = headNode->nextNode->nextNode;
            delete delNode;
            return data;
        }
    }
    int empty() {
        if(stackSize == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int top() {
        return headNode->nextNode->data;
    }
};

int main() {
    int n;
    string cmd;
    stack stack;
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        cin >> cmd;
        if(cmd == "push") {
            int data;
            scanf("%d", &data);
            stack.push(data);
        }
        else if(cmd == "pop") {
            printf("%d\n",stack.pop());
        }
        else if(cmd == "empty") {
            printf("%d\n", stack.empty());
        }
        else if(cmd == "top") {
            printf("%d\n", stack.top());
        }
        else if(cmd == "size") {
            printf("%d\n", stack.returnSize());
        }
    }
    
    return 0;
}