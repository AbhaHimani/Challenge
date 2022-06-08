class MyCircularQueue
{
    int *arr;
    int f, rear, maxsize, currentsize;

public:
    MyCircularQueue(int k)
    {
        arr = new int[k];
        currentsize = 0;
        maxsize = k;
        rear = -1;
        f = 0;
    }

    bool enQueue(int value)
    {
        if (!isFull())
        {
            rear = (rear + 1) % maxsize;
            arr[rear] = value;
            currentsize++;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            f = (f + 1) % maxsize;
            currentsize--;
            return true;
        }
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[f];
        }
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        return currentsize == 0;
    }

    bool isFull()
    {
        return currentsize == maxsize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */