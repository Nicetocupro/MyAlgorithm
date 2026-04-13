class Solution {
public:
    bool canMeasureWater(int x, int y, int target) 
    {
        //一共6个状态
        //装满x 装满y 倒空x 倒空y 将x倒入y 将y倒入x
        queue<pair<int , int>> myQueue;
        set<pair<int, int>> visited; // 用于记录已访问的状态
        
        
        myQueue.push(make_pair(0, 0));
        visited.insert(make_pair(0, 0));
        
        while(!myQueue.empty())
        {
            pair<int, int> temp = myQueue.front();
            //cout << temp.first << " " << temp.second << endl;
            myQueue.pop();
            if(temp.first + temp.second == target || temp.first == target || temp.second == target)
            {
                return true;
            }

           // 装满x
            if (temp.first != x) {
                pair<int, int> newState = make_pair(x, temp.second);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }

            // 装满y
            if (temp.second != y) {
                pair<int, int> newState = make_pair(temp.first, y);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }

            // 倒空x
            if (temp.first != 0) {
                pair<int, int> newState = make_pair(0, temp.second);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }

            // 倒空y
            if (temp.second != 0) {
                pair<int, int> newState = make_pair(temp.first, 0);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }

            // 将x倒入y
            if (temp.first != 0 && temp.second != y) {
                int pourAmount = min(temp.first, y - temp.second);
                pair<int, int> newState = make_pair(temp.first - pourAmount, temp.second + pourAmount);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }

            // 将y倒入x
            if (temp.second != 0 && temp.first != x) {
                int pourAmount = min(temp.second, x - temp.first);
                pair<int, int> newState = make_pair(temp.first + pourAmount, temp.second - pourAmount);
                if (visited.find(newState) == visited.end()) {
                    myQueue.push(newState);
                    visited.insert(newState);
                }
            }
        }
        return false;
    }
};