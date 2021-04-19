int uneatenLeaves(int arr[],int n,int k)
{
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int flag = 0;
        for(int j = 0; j < k; j++){
            if(i % arr[j] == 0){
                flag++;
                break;
            }
        }
        if(!flag)
        ans++;
    }
    return ans;
}