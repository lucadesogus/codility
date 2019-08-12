#include <vector>
#include <algorithm>
int solution(std::vector<int> & A)
{
    if(A.empty())return 0;
    int l_ret = 1;
    if(A.size() != 1)
    {
        std::sort(A.begin(),A.end());
        auto iter = std::unique(A.begin(),A.end());
        l_ret = std::distance(A.begin(),iter);
    }
    return l_ret;
}
