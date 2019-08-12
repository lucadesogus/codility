#include <vector>
#include <algorithm>
using namespace std;
#define LIMIT 1000000000
int solution(vector<int> &A)
{
    int l_ret = 0;
    if(!A.empty())
    {

        auto firstCarPassing = std::find(A.begin(),A.end(),0);
        int dP = 0;
        for(auto iter = firstCarPassing; iter!= A.end(); ++iter)
        {
            if((*iter) == 0)
                dP ++;
            else
            {
                if(l_ret + dP > LIMIT)
                    return -1;
                l_ret += dP;
            }
        }
    }
    return l_ret;
}
