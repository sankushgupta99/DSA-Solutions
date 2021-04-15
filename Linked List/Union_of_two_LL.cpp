struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s1;
    Node* curr1 = head1;
    while(curr1 != NULL){
        s1.insert(curr1->data);
        curr1 = curr1->next;
    }
    Node* curr2 = head2;
    while(curr2 != NULL){
        s1.insert(curr2->data);
        curr2 = curr2->next;
    }
    Node* prev = NULL;
    Node* head;
    for(auto it:s1){
        Node*temp = new Node(it);
        if(prev == NULL){
            prev = temp;
            head = temp;
        }
        else{
            prev->next = temp;
            prev = prev->next;
        }
    }
    return head;
}
