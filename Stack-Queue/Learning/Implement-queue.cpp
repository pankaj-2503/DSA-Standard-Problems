void MyQueue :: push(int x)
{
        // Your Code
        arr[rear]=x;
        rear++;
        
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code  
        if(rear<=front) return -1;
        int ans=arr[front];
        front++;
        return ans;
        
}