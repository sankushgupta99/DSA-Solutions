#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        Node* curr1 = first;
        Node* curr2 = second;
        while(curr1 != NULL)
        {
            s1.push(curr1->data);
            curr1 = curr1->next;
        }
        while(curr2 != NULL)
        {
            s2.push(curr2->data);
            curr2 = curr2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty()){
            int dig1, dig2;
            if(!s1.empty()){
                dig1 = s1.top();
                s1.pop();
            }else{
                dig1 = 0;
            }
            if(!s2.empty()){
                dig2 = s2.top();
                s2.pop();
            }else{
                dig2 = 0;
            }
            int sum = dig1 + dig2 + carry;
            s3.push(sum % 10);
            carry = sum / 10;
        }
        if(carry)
        s3.push(1);
        Node* head = NULL;
        Node* prev = NULL;
        while(!s3.empty()){
            Node* temp = new Node(s3.top());
            s3.pop();
            if(head == NULL){
                head = temp;
                prev = temp;
            }
            else{
                prev->next = temp;
                prev = temp;
            }
        }
        return head;
    }
};