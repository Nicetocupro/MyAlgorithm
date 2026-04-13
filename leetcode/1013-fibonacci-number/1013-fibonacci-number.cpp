class Solution
{
public:
    int fib(int n)
    {
        int temp1 = 0, temp2 = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                temp1 = temp1 + temp2;
            }
            else
            {
                temp2 = temp1 + temp2;
            }
        }
        if (n % 2 == 0)
        {
            return temp1;
        }
        else
        {
            return temp2;
        }
    }
};