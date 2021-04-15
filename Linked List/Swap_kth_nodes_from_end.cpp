Node *swapkthnode(Node* head, int num, int k)
{
    if(k > num){
        return head;
    }
    if(num % 2 == 1 && ((k*2)-1 == num)){
        return head;
    }
    Node* y = head;
    Node* prev_y = NULL;
    for(int i = 1; i < k; i++){
        prev_y = y;
        y = y->next;
    }
    Node* x = head;
    Node* prev_x = NULL;
    for(int i = 1; i < num-k+1; i++){
        prev_x = x;
        x = x->next;
    }
    if(prev_y)
    prev_y->next = x;
    if(prev_x)
    prev_x->next = y;
    
    Node* temp = y->next;
    y->next = x->next;
    x->next = temp;
    
    if(k == 1)
    head = x;
    
    if(k == num)
    head = y;
    return head;
}