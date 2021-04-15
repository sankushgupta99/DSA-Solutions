Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next_node;
    while(curr != NULL){
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}
void reorderList(Node* head) {
    Node* fast_ptr = head;
    Node* slow_ptr = head;
    while(fast_ptr->next != NULL && fast_ptr->next->next != NULL){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    Node* head2 = slow_ptr->next;
    Node* head1 = head;
    slow_ptr->next = NULL;
    head2 = reverse(head2);
    Node* curr1 = head1;
    Node* curr2 = head2;
    while(curr1 != NULL && curr2 != NULL){
        Node* next1 = curr1->next;
        Node* next2 = curr2->next;
        curr1->next = curr2;
        curr2->next = next1;
        curr1 = next1;
        curr2 = next2;
    }
}