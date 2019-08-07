#include <vector>
#include <algorithm>
#include <numeric>
#include <limits.h>

int solution(vector<int> &A)
{
    if(A.size()<2) return 0;
    if(A.size() == 2) return (A[0]>A[1]?A[0]-A[1]:A[1]-A[0]);
    int l_ret = INT_MAX;
    int left_sum = A[0];
    int right_sum = std::accumulate(A.begin() +1,A.end(),0);
    for(auto iter = A.begin()+1; iter!= A.end();++iter)
    {
        int res = left_sum>right_sum?left_sum-right_sum:right_sum-left_sum;
        if(res != 0)
        {
            if(res < l_ret)
                l_ret = res;
            left_sum += (*iter);
            right_sum -= (*iter);
        }
        else
            return 0;
    }
    return l_ret;
}
