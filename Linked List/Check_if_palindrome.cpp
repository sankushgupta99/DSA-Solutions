#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    void reverse(Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next_node;
        while(curr != NULL){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        head = prev;
    }
    bool isPalindrome(Node *head)
    {
        if(head == NULL || head->next == NULL)
        return 1;
        if(head->next->next == NULL){
            if(head->data == head->next->data)
            return 1;
            else
            return 0;
        }
        Node* slow_ptr = head;
        Node* fast_ptr = head;
        Node* prev_of_slow = head;
        Node* midnode = NULL;
        while(fast_ptr->next != NULL && fast_ptr->next->next != NULL){
            fast_ptr = fast_ptr->next->next;
            prev_of_slow = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        if(fast_ptr->next == NULL){
            midnode = slow_ptr;
        }
        else{
            prev_of_slow = prev_of_slow->next;
        }
        slow_ptr = slow_ptr->next;
        prev_of_slow->next = NULL;
        reverse(slow_ptr);
        Node* ptr1 = head;
        Node* ptr2 = slow_ptr;
        int res = 1;
        while(ptr1 != NULL){
            if(ptr1->data != ptr2->data)
            res = 0;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        reverse(slow_ptr);
        if(midnode == NULL)
        prev_of_slow->next = slow_ptr;
        else{
            prev_of_slow->next = midnode;
            midnode->next = slow_ptr;
        }
        return res;
    }
};