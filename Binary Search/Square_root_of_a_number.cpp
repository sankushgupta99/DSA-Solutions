long long int floorSqrt(long long int x) 
{
    long long int i = 0, j = x;
    while(i < j - 1){
        long long int mid = (i + j) / 2;
        if(mid * mid < x){
            i = mid;
        }
        else if(mid * mid > x){
            j = mid;
        }
        else{
            return mid;
        }
    }
    if(j * j == x)
    return j;
    else
    return i;
}