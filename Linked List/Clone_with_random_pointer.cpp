Node *copyList(Node *head) {
    Node* curr = head;
    while(curr != NULL){
        Node* temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    curr = head;
    while(curr != NULL){
        if(curr->arb != NULL)
        curr->next->arb = curr->arb->next;
        curr = curr->next->next;
    }
    curr = head;
    Node* clone_head = head->next;
    Node* next_node = head->next;
    while(curr != NULL){
        curr->next = next_node->next;
        if(curr->next != NULL)
        next_node->next = curr->next->next;
        else
        next_node->next = NULL;
        curr = curr->next;
        next_node = next_node->next;
    }
    return clone_head;
}