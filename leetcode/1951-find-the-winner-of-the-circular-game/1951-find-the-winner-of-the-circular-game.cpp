class Solution {
public:
    int findTheWinner(int n, int k)
    {
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return (findTheWinner(n - 1 , k) - 1 + k ) % n + 1;
        }
    }
};
