class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num2 == "0" || num1 == "0")
        {
            return "0";
        }

        string result = "";
        int step = 0;
        int lastNum = 0;
        while(step <= num1.size() + num2.size() - 2)
        {
            int temp = 0;
            for(int i = 0; i <= step; i++)
            {
                if(i < num1.size() && (step - i) < num2.size())
                {
                    temp += (num1[num1.size() - i - 1] - '0') * (num2[num2.size() - step + i - 1] - '0');
                }
            }
            temp += lastNum;
            lastNum = temp / 10;
            temp = temp % 10;
            result = '0' + temp + result;
            step++;
        }
        if(lastNum)
        {
            result = std::to_string(lastNum) + result;
        }

        return result;
    }
};