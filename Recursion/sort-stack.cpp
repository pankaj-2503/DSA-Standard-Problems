// Time complexity - O(N*N)
void SortedStack :: sort()
{
   //pehle saare element stack ke khali krdo 
   if(s.size()==1) return;
   int x=s.top();
   s.pop();
   sort();
   if(x>s.top()){
       s.push(x);
   }
   else{
       int y=s.top();
       s.pop();
       s.push(x);
       sort();
       s.push(y);
   }
   
}