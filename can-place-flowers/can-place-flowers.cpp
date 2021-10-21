class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int len = a.size();
        
        if(len==1){
            if(a[0]!=1 && n > 0)
                --n;
            return (n==0);
        }
        
        for(int i = 0; i < len && n > 0; ++i) {
            if(a[i]==1) {
                ++i;    
                continue;
            } 
            if(i==0 && a[i]==0){
                if(a[i+1]==0){
                    a[i++]=1;
                    --n;
                } else
                    continue;
            }
            else if(i==len-1 && a[i]==0){
                if(a[i-1]==0) {
                    a[i++]=1;
                    --n;
                } else
                    continue;
            }
            
            else{
                if(a[i-1]==a[i+1] && a[i-1]==0){
                    a[i++]=1;
                    --n;
                }
            }
        }
        return n==0;
    }
};