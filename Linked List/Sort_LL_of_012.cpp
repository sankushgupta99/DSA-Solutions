class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zeroD = new Node(-1);
        Node* oneD = new Node(-1);
        Node* twoD = new Node(-1);
        Node* zero = zeroD;
        Node* one = oneD;
        Node* two = twoD;
        Node* curr = head;
        while(curr != NULL){
            if(curr->data == 0){
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1){
                one->next = curr;
                one  = one->next;
            }
            else{
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        if(oneD->next != NULL){
            zero->next = oneD->next;
            one->next = twoD->next;
        }
        else{
            zero->next = twoD->next;
        }
        two->next = NULL;
        Node* ans = zeroD->next;
        delete(zeroD);
        delete(oneD);
        delete(twoD);
        return ans;
    }
};