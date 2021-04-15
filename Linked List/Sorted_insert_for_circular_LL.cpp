class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       Node* curr = head;
       Node* next_node;
       int flag = 0;
       while(curr->next != head){
           next_node = curr->next;
           if(data > curr->data && data <= next_node->data){
               Node*temp = new Node(data);
               curr->next = temp;
               temp->next = next_node;
               flag = 1;
               break;
           }
           else{
               curr = curr->next;
           }
       }
       if(!flag){
           Node* temp = new Node(data);
           next_node = curr->next;
           curr->next = temp;
           temp->next = next_node;
           if(data < head->data)
           head = temp;
       }
       return head;
    }
};