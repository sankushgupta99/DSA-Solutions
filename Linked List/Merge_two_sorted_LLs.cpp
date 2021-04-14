Node* sortedMerge(Node* head1, Node* head2)  
{  
   if(head1 == NULL)
   return head2;
   if(head2 == NULL)
   return head1;
   
   Node* dummy = new Node(-1);
   Node* prev = dummy;
   Node* c1 = head1;
   Node* c2 = head2;
   
   while(c1 != NULL && c2 != NULL){
       if(c1->data < c2->data){
           prev->next = c1;
           c1 = c1->next;
       }
       else{
           prev->next = c2;
           c2 = c2->next;
       }
       prev = prev->next;
   }
   if(c1 != NULL)
   prev->next = c1;
   else
   prev->next = c2;
   return dummy->next;
}  