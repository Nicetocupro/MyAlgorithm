class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
	{
		vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        
        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
        	int course = prerequisites[i][0];
        	int prereq = prerequisites[i][1];
        	adjList[prereq].push_back(course);
        	inDegree[course]++;
		}
		
		queue<int> MyQueue;
		
		for(int i = 0 ; i < numCourses ; i++)
		{
			if(inDegree[i] == 0)
			{
				MyQueue.push(i);
			}
		}
		
		int ans = 0;
		while(!MyQueue.empty())
		{
			int temp = MyQueue.front();
			MyQueue.pop();
			ans++;
			
			for(int i = 0 ; i < adjList[temp].size() ; i++)
			{
				int NextNode = adjList[temp][i];
				inDegree[NextNode]--;
				if(inDegree[NextNode] == 0)
				{
					MyQueue.push(NextNode);
				}
			}
		}
		
		return ans == numCourses;
    }
};