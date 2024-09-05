// tC:O(1)
void MyQueue:: push(int x)
{
        // Your Code
       QueueNode *newnode=new QueueNode(x);
      if(rear==NULL){
         rear= front=newnode;
          return;
      }
      else{
      rear->next=newnode;
     rear=newnode;
      }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code    
        if(front==NULL){
    return -1;
}    
QueueNode *oldhead=front;
int temp=front->data;
front=front->next;
if(front==NULL){
    rear=NULL;
}
delete oldhead;
return temp;
        
}
