int getMiddle(Node *head)
{
    if(head == NULL)
    return -1;
   Node* slow_ptr = head;
   Node* fast_ptr = head;
   while(fast_ptr != NULL && fast_ptr->next != NULL){
       fast_ptr = fast_ptr->next->next;
       slow_ptr = slow_ptr->next;
   }
   return slow_ptr->data;
}