#include <vector>
#include <algorithm>
#include <unordered_map>

int solution(int X, vector<int> &A)
{
    if(X < 1 || A.empty()) return -1;
    std::unordered_map<int,char> temp{};
    for(auto iter = A.begin(); iter!= A.end(); ++iter)
    {
        if((*iter)<= X)
        {
            temp[(*iter)] = 1;
            if(temp.size() == X)
                return std::distance(A.begin(),iter);
        }
    }
    return -1;
}
