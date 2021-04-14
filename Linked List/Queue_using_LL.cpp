void MyQueue:: push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if(rear == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL)
    return -1;
    QueueNode* temp = front;
    front = front->next;
    if(front == NULL)
    rear = NULL;
    int val = temp->data;
    delete(temp);
    return val;
}