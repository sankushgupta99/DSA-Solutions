Node* merge(Node* first, Node* second){
    Node* ptr1 = first;
    Node* ptr2 = second;
    Node* prev = new Node(-1);
    Node* head = prev;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            prev->bottom = ptr1;
            ptr1 = ptr1->bottom;
            prev = prev->bottom;
        }
        else{
            prev->bottom = ptr2;
            ptr2 = ptr2->bottom;
            prev = prev->bottom;
        }
    }
    if(ptr1 == NULL){
        prev->bottom = ptr2;
    }
    else{
        prev->bottom = ptr1;
    }
    return head->bottom;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL){
        return root;
    }
    Node* second = flatten(root->next);
    Node* res = merge(root, second);
    return res;
    
}