class Solution
{
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int> &cards)
    {
        vector<double> l;
        for (const int &card : cards)
        {
            l.emplace_back(double(card));
        }
        return solve(l);
    }

    bool solve(vector<double> &cards)
    {
        if (cards.size() == 0)
        {
            return false;
        }
        else if (cards.size() == 1)
        {
            return fabs(cards[0] - TARGET) < EPSILON;
        }
        else
        {
            int len = cards.size();
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    if (i != j)
                    {
                        vector<double> l = vector<double>();
                        for (int k = 0; k < len; k++)
                        {
                            if (k != i && k != j)
                            {
                                l.emplace_back(cards[k]);
                            }
                        }

                        for (int k = 0; k < 4; k++)
                        {
                            if (k < 2 && i > j)
                            {
                                continue;
                            }
                            if (k == ADD)
                            {
                                l.emplace_back(cards[i] + cards[j]);
                            }
                            else if (k == MULTIPLY)
                            {
                                l.emplace_back(cards[i] * cards[j]);
                            }
                            else if (k == SUBTRACT)
                            {
                                l.emplace_back(cards[i] - cards[j]);
                            }
                            else if (k == DIVIDE)
                            {
                                if (fabs(cards[j]) < EPSILON)
                                {
                                    continue;
                                }
                                l.emplace_back(cards[i] / cards[j]);
                            }
                            if (solve(l))
                            {
                                return true;
                            }
                            l.pop_back();
                        }
                    }
                }
            }
        }
        return false;
    }
};