 long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long low=1,high=x;
        long long ans=1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid<=x) low=mid+1;
            else high=mid-1;
        }
        return high;
        
    }