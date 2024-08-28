long long count(int n) {
        // your code here
        long long connected=n*(n-1);
        long long singlevertex=connected/2;
        //pick or not pick
        long long ans=pow(2,singlevertex);
        return ans;
    }