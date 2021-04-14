class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
      Node* del_next = del->next;
      del->data = del_next->data;
      del->next = del_next->next;
      delete(del_next);
      // OR
      //*del = *(del->next);
    }

};