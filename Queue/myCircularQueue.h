//
// Created by Yongxin on 2018/8/12.
//

#ifndef CIRCULARQUEUE_MYCIRCULARQUEUE_H
#define CIRCULARQUEUE_MYCIRCULARQUEUE_H

#include <vector>

class MyCircularQueue {
private:
    //store elements
    std::vector<int> data;
    //a pointer to indicate the start position
    int front;
    //a pointer to indicate the end position
    int rear;
    //size of the circular queue
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize((std::vector<int>::size_type)k);
        front = -1;
        rear = -1;
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
            front = 0;
        data[(rear + 1) % size] = value;
        rear = (rear + 1) % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        else
            return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return data[rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (front==-1);
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};

#endif //CIRCULARQUEUE_MYCIRCULARQUEUE_H
