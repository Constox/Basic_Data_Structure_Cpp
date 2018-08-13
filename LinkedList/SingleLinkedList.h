//
// Created by Yongxin on 2018/8/13.
//

#ifndef SINGLELINKEDLIST_SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_SINGLELINKEDLIST_H

struct SingleListNode {
    int val;
    SingleListNode* next;
    explicit SingleListNode(int x): val(x), next(nullptr){}
};

class MyLinkedList {
private:
    struct SingleListNode* SLNode;
    struct SingleListNode* tail;
    unsigned size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        // Single list with a head node
        SLNode = new SingleListNode(-1);
        tail = new SingleListNode(-1);
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(size == 0)
            return -1;
        if(index >= size)
            return -1;
        if(index == size - 1)
            return tail->val;
        struct SingleListNode* ptr = SLNode;
        while(index >= 0) {
            ptr = ptr->next;
            index--;
        }
        return ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(SLNode == nullptr)
            MyLinkedList();
        auto insertNode = new SingleListNode(val);
        auto temp = SLNode->next;
        SLNode->next = insertNode;
        insertNode->next = temp;
        if(size == 0)
            tail = insertNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(SLNode == nullptr)
            MyLinkedList();
        auto insertNode = new SingleListNode(val);
        tail->next = insertNode;
        tail = insertNode;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        if(index == size) {
            addAtTail(val);
            return;
        }
        auto insertNode = new SingleListNode(val);
        auto ptr = SLNode;
        while(index > 0) {
            ptr = ptr->next;
            index--;
        }
        auto temp = ptr->next;
        ptr->next = insertNode;
        insertNode->next = temp;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(SLNode == nullptr)
            return;
        if(index >= size)
            return;
        bool deleTail = false;
        if(index == size - 1)
            deleTail = true;
        auto ptr = SLNode;
        while(index > 0) {
            ptr = ptr->next;
            index--;
        }
        auto target = ptr->next;
        ptr->next = target->next;
        delete(target);
        if(deleTail)
            tail = ptr;
        size--;
    }

    int Size() {
        return size;
    }
};

#endif //SINGLELINKEDLIST_SINGLELINKEDLIST_H
