//
// Created by Yongxin on 2018/8/12.
//

#ifndef QUEUE_MYQUEUE_H
#define QUEUE_MYQUEUE_H

#include <vector>

class MyQueue {
private:
    // store elements
    std::vector<int> data;
    // a pointer to indicate the start position
    int p_start;
public:
    MyQueue() {p_start = 0;}
    /** Insert an element into the queue. Return true if the operation is successful. */
    bool enQueue(int x) {
        data.push_back(x);
        return true;
    }
    /** Delete an element from the queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        p_start++;
        return true;
    };
    /** Get the front item from the queue. */
    int Front() {
        return data[p_start];
    };
    /** Checks whether the queue is empty or not. */
    bool isEmpty()  {
        return p_start >= data.size();
    }
    /** Return the size of this queue */
    std::vector<int>::size_type size() {
        return data.size();
    }
};

#endif //QUEUE_MYQUEUE_H
