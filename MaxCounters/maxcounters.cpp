#include <vector>
#include <algorithm>
std::vector<int> solution(int N, std::vector<int> &A)
{
    std::vector<int> l_ret (N,0);
    const int allToMAx = N + 1;
    bool lastWasAllToMax = false;
    int max = 0;
    int lastAppliedMax = 0;
    for (const auto & item: A)
    {
        if(item != allToMAx)
        {
            if(l_ret[item-1] < lastAppliedMax)
                l_ret[item-1] = lastAppliedMax;
            l_ret[item-1] ++;
            if(l_ret[item-1] > max)
                max = l_ret[item-1];
            lastWasAllToMax = false;
        }
        else if(!lastWasAllToMax)
        {
            lastWasAllToMax = true;
            lastAppliedMax = max;
        }
    }
    for(auto & item : l_ret)
    {
        if(lastAppliedMax>item)
            item = lastAppliedMax;
    }
    return l_ret;
}
