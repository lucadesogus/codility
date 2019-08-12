#include <vector>

int solution(std::vector<int> & A)
{
    std::vector <int> fibSeries{0,1,2};
    do
    {
        fibSeries.push_back((*(fibSeries.rbegin())) +(*(fibSeries.rbegin()+1)));
    }
    while(A.size() > fibSeries.back());
    std::vector<std::pair<int,int>>positions{{-1,0}};
    for (auto i = 0;;++i)
    {
        if (i == positions.size())
            return -1;
        auto posPair = *(positions.begin()+i);
        for (auto iter = fibSeries.rbegin(); iter != fibSeries.rend(); ++iter)
        {
            int newPos = posPair.first + (*iter);
            if (newPos == A.size())
                return posPair.second + 1;
            else if (newPos > A.size() || newPos < 0 || 0==A[newPos])
            {
            }
            else
            {
                positions.push_back({newPos,posPair.second+1});
                A[newPos]=0;
            }
        }
    }
}
