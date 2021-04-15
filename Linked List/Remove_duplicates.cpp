class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates( Node *head) 
    {
        map<int,int> m1;
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            if(m1[curr->data] == 0){
                m1[curr->data]++;
                prev = curr;
                curr = curr->next;
            }
            else{
                Node* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(temp);
            }
        }
        return head;
    }
};