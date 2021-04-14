int getNthFromLast(Node *head, int n)
{
     Node* slow_ptr = head;
     Node* fast_ptr = head;
     for(int i = 0; i < n; i++){
        if(fast_ptr == NULL)
        return -1;
        fast_ptr = fast_ptr->next;
     }
     while(fast_ptr != NULL){
         fast_ptr = fast_ptr->next;
         slow_ptr = slow_ptr->next;
     }
     return slow_ptr->data;
}