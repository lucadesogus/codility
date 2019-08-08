#include <vector>
#include <algorithm>
int solution(vector<int> &A)
{
    if(A.empty()) return 0;
    std::sort(A.begin(),A.end());
    if(A.front() != 1 || A.back() != A.size()) return 0; 
    for (auto iter = A.begin();iter != A.end() -1 ; ++iter) 
    {
        if ((*iter) +1 != (*(iter+1)))
            return 0;
    }
    return 1;
}
