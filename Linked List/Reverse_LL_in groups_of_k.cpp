class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL)
        return head;
        node* prev = NULL;
        node* curr = head;
        node* next_node = NULL;
        int i = 0;
        while(curr != NULL && i < k){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            i++;
        }
        head->next = reverse(curr, k);
        node* res = prev;
        return res;
    }
};