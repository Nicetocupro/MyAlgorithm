class Solution {
public:
    int trainWays(int num) {
        int a = 1 , b = 1; //a 0 b 1
        for(int i = 2 ; i <= num ; i++)
        {
            if(i % 2 == 0)
            {
                a = (a + b) % 1000000007;
            }
            else
            {
                b = (a + b) % 1000000007;
            }
        }
        if(num % 2 == 0)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
};