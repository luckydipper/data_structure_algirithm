#ifndef __counted_queue_10_13__
#define __counted_queue_10_13__
class CountedQueue
{
private:
    int front_index;
    int rear_index;
    int length;
    const int MAX_ITEMS;
    int* const ITEMS;
    // int const items[MAX_ITEMS]; Window에서는 VLA(variable length array 지원 x)
public:
    explicit CountedQueue(const int& maxitem);
    ~CountedQueue();

    bool IsThereItem() const;
    bool IsFull() const;

    void Enqueue(const int& item);
    int Dequeue();
};

CountedQueue::CountedQueue(const int& maxitem) :
    MAX_ITEMS(maxitem),
    ITEMS(new int[maxitem]),
    front_index(0),
    rear_index(0),
    length(0)
{
    ;
}

CountedQueue::~CountedQueue()
{
    delete[] ITEMS;
}


bool CountedQueue::IsThereItem() const
{
    if (length == 0)
        return false;
    else
        return true;
}

bool CountedQueue::IsFull() const
{

    if (length >= MAX_ITEMS)
        return true;
    else
        return false;
}

void CountedQueue::Enqueue(const int& item)
{
    if (this->IsFull())
        throw "Queue is full";
    ITEMS[rear_index] = item;
    length++;
    rear_index = (rear_index + 1) % (MAX_ITEMS + 1);
}

int CountedQueue::Dequeue()
{
    if (!this->IsThereItem())
        throw "Queue is Empty";
    int result = ITEMS[front_index];
    length--;
    front_index = (front_index + 1) % (MAX_ITEMS + 1);
    return result;
}
#endif // !__counted_queue_10_13__
