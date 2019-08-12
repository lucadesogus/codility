#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int solution(int K, int M, vector<int> &A)
{
    if(A.empty())return 0;
    int min = *(std::max_element(A.begin(),A.end()));
    int max = std::accumulate(A.begin(),A.end(),0);
    int l_ret = max;
    auto checkF = [&A,&K](int mid)->bool
    {
        int nBlock = K;
        int sum = 0;
        bool l_r = true;
        for (const auto & item: A)
        {
            sum += item;
            if(mid < sum)
            {
                nBlock--;
                sum = item;
            }
            if(0 == nBlock)
            {
                l_r = false;
                break;
            }
        }
        return l_r;
    };
    int mid = 0;
    for(;min <= max;)
    {
        mid = (min + max) / 2;
        if(checkF(mid))
        {
            l_ret = mid;
            max = mid -1;
        }
        else
            min = 1 + mid;
    }
    return l_ret;
}
