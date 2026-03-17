class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1.size() == 1 && num2.size() == 1)
        {
            int str1 = num1[0] - '0';
            int str2 = num2[0] - '0';

            return to_string(str1 * str2);
        }
        else
        {
            pair<string , string> result1 , result2;
            result1 = splitString(num1);
            result2 = splitString(num2);
            string ac = multiply(result1.first , result2.first);
            string bd = multiply(result1.second , result2.second);
            string ad = multiply(result1.first , result2.second);
            string bc = multiply(result1.second , result2.first);

            ac = ac + string(result1.second.size() + result2.second.size() , '0');
            ad = ad + string(result1.second.size() , '0');
            bc = bc + string(result2.second.size() , '0');

            return removeLeadingZeros(addStrings(addStrings(ac, ad), addStrings(bc , bd)));
        }
    }

    pair<string, string> splitString(const string& str) 
    {
        pair<string, string> result;
        if(str.size() == 1)
        {
            result.first = "0";
            result.second = str;
        }
        else
        {
            int length = str.length();
            int mid = length / 2;

            if (length % 2 == 0) {  // 如果字符串长度为偶数
                result.first = str.substr(0, mid);
                result.second = str.substr(mid);
            } 
            else    
            {  // 如果字符串长度为奇数
                result.first = str.substr(0, mid + 1);
                result.second = str.substr(mid + 1);
            }
        }

        return result;
    }

    string addStrings(const string& num1, const string& num2) {
        int carry = 0;
        string result = "";
        int i = num1.length() - 1, j = num2.length() - 1;
    
        // 从个位开始逐位相加
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
            int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;
        
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result = to_string(sum % 10) + result;
        }
        return result;
    }
    // 去除结果中的前导零
    string removeLeadingZeros(const string& num) 
    {
        unsigned int index = 0;
        while (index < num.length() - 1 && num[index] == '0') 
        {
            index++;
        }
        return num.substr(index);
    }
};