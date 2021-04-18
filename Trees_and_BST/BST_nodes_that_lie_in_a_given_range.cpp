int getCount(Node *root, int l, int h)
{
  if(root == NULL)
  return 0;
  
  if(root->data >= l && root->data <= h)
  return 1 + getCount(root->left,l ,h) + getCount(root->right, l, h);
 
  if(root->data < l)
  return getCount(root->right, l, h);
  
  return getCount(root->left,l ,h);
}
//OR
int getCount(Node *root, int l, int h)
{
  if(root == NULL)
  return 0;
  int left_count = getCount(root->left,l ,h);
  int right_count = getCount(root->right, l, h);
  if(root->data >= l && root->data <= h)
  return 1 + left_count + right_count;
  else
  return left_count + right_count;
}