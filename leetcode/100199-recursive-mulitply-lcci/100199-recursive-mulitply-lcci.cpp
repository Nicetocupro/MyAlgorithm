class Solution {
public:
    int multiply(int A, int B) 
    {
        if(A == 1)
        {
            return B;
        }
        else if(A % 2 == 0)
        {
            int result = multiply(A >> 1 , B);
            return result + result;
        }
        else
        {
            int result = multiply(A >> 1 , B);
            return B + result + result;
        }
    }
};