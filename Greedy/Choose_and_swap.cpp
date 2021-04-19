class Solution{
public:
    string chooseandswap(string a){
        int arr[30];
        memset(arr,-1,sizeof(arr));
        int len = a.length(), flag=0, s;
        char x,y;
        for(int i = 0; i < len; i++){
            if(arr[a[i]-'a'] == -1)
            arr[a[i]-'a'] = i;
        }
        for(int i = 0; i < len; i++){
            s = a[i] - 'a';
            for(int j = 0; j < s; j++){
                if(arr[j] > i){
                    x = a[i];
                    y = j + 'a';
                    flag++;
                    break;
                }
            }
            if(flag)
            break;
        }
        if(flag){
            for(int i = 0; i < len; i++){
                if(a[i] == x)
                a[i] = y;
                else if(a[i] == y)
                a[i] = x;
            }
        }
        return a;
    }
    
};