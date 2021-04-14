int intersectPoint(Node* head1, Node* head2)
{
    int n = 0;
    int m = 0;
    Node* ptr = head1;
    while(ptr != NULL){
        n++;
        ptr = ptr->next;
    }
    ptr = head2;
    while(ptr != NULL){
        m++;
        ptr = ptr->next;
    }
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if(n > m){
        for(int i = 0; i < n - m; i++){
            ptr1 = ptr1->next;
        }
    }
    else{
        for(int i = 0; i < m - n; i++){
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1->data;
}