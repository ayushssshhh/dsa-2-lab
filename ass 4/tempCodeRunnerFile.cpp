#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> b;
        b[0] = nums[0];
        
        int n=0 , subArrMax = nums[0];
        for(int x : nums)
            b.push_back(x+b[n++]);
        
        for(int i=0 ; i<=n ; i++)
        {
            int sum = 0;
            for(int j=i ; j<=n ; j++)
            {
                sum = i>0 ? b[j] - b[j-i] : b[j];
                subArrMax = subArrMax<sum ? sum : subArrMax;
            }
        }
        
        return subArrMax;
        
    }
}s;

/*class Solution {

public:

    int maxSubArray(vector<int>& nums) {
        int i=0 , max=nums[0] , sub=max;
        for(int x : nums)
            i++;
        for(int x=0 ; x<=i ; x++ )
        {
            sub = 0;
            for(int y=x ; y<i ; y++)
            {
                sub += nums[y];
                max = max>sub ? max : sub;
            }
           // max = max>sub ? max : sub;
        }
        
        return max;
    }
}s;*/

int main(){
    vector<int> a;

    int n; 
    cin>>n;

    for(int i=0 ; i<n ; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    cout<<s.maxSubArray(a);

    return 0; 
}

//9 -2 3 4 -1 5 -12 6 1 3 