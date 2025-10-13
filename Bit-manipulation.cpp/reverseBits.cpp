
// What we are basically doing is taking the rightmost bit of n and shifting n to right, similarly shifting result to left  
int reverseBits(int n) {
        int result=0;
        for(int i=0;i<=31;i++){
            result=result<<1;
            if(n&1){
                result|=1;
            }
            n>>=1;

        }
        return result;
}