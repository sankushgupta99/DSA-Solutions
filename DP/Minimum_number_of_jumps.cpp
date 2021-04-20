class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==1)
        return 0;
        long int jumps=1;
        long int i_prev=0;
        long int i_new=arr[0];
        int flag=0;
        while(i_new<n-1){
            jumps++;
            long int max_final=i_new;
            for(int j=i_new;j>i_prev;j--){
                if(j+arr[j]>max_final){
                    max_final=j+arr[j];
                }
            }
            if(max_final==i_new){
                flag++;
                break;
            }
            i_prev=i_new;
            i_new=max_final;
        }
        if(flag)
        return -1;
        return jumps;
    }
};