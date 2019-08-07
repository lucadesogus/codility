#include <vector>
#include <algorithm>

int solution(vector<int> &A)
{
    if(A.empty())return 1;
    int max= A.size() +1;
    std::sort(A.begin(),A.end());
    if(A.front() != 1) return 1;
    if(A.back() != max) return max;
    for(auto iter = A.begin(); iter != A.end() -1; ++iter)
    {
        if((*iter) + 1 != (*(iter+1)))
            return ((*iter) + 1);
    }
}
