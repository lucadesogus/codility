#include <vector>
#include <algorithm>
int solution(std::vector<int> & A)
{
    std::sort(A.begin(),A.end(),std::greater<int>());
    return (std::max(A.front() * A[1] * A[2],A.back() * (*(A.rbegin()+1))* A.front()));
}
