/* QUEUES */
/*
 * A queue is a linear data structure that follows the First In First Out (FIFO) principle. 
 * This means that the first element added to the queue will be the first one to be removed.
 * 
 * Always handle underflow and overflow conditions in queues.
 * Ensure that dynamically allocated memory is properly managed and freed, especially in linked list implementations.
 * Keep queue operations (enqueue, dequeue, front, rear) consistent and clear.
 */

/*
#include <iostream>
using namespace std;

class QNode {
public:
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
public:
    QNode* front, * rear;
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int k) {
        QNode* temp = new QNode(k);

        if (rear == nullptr) {
            front = rear = temp;
            cout << k << " enqueued to queue\n";
            return;
        }

        rear->next = temp;
        rear = temp;
        cout << k << " enqueued to queue\n";
    }

    int dequeue() {
        if (front == nullptr)
            return INT_MIN;

        QNode* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        int data = temp->data;
        delete temp;
        return data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << " dequeued from queue\n";
    cout << q.dequeue() << " dequeued from queue\n";

    return 0;
}
*/

#include <iostream>
#include <climits>
using namespace std;

#define MAX 1000

class Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
public:
    Queue(unsigned capacity) : front(0), size(0), rear(capacity - 1), capacity(capacity) {
        array = new int[capacity];
    }

    ~Queue() {
        delete[] array;
    }

    bool isFull() const {
        return (size == capacity);
    }

    bool isEmpty() const {
        return (size == 0);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
        cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return INT_MIN;
        }
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return array[front];
    }

    int getRear() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return array[rear];
    }

    void printQueue() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int count = size;
        int i = front;
        while (count--) {
            cout << array[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue queue(MAX);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << queue.dequeue() << " dequeued from queue\n";
    cout << "Front item is " << queue.getFront() << endl;
    cout << "Rear item is " << queue.getRear() << endl;

    queue.printQueue();

    return 0;
}
