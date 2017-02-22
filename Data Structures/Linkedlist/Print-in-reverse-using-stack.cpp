/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include <stack>


void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *cur = head;
    std::stack <int> stack1;
    int data;
    while(cur != NULL)
    {
        stack1.push(cur->data);
        cur = cur->next;
    }
    
  while (!stack1.empty())
  {
     std::cout <<stack1.top() <<endl;
     stack1.pop();
  }
}
