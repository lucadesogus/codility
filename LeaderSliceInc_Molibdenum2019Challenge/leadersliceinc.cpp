
//Golden Award: https://app.codility.com/cert/view/certPAJJ8K-FGGUC773HCTE4USE/ 

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
vector<int> solution(int K, int M, vector<int> &A) {
    size_t A_sz = A.size();
    if(1 == A_sz)
        return (std::vector<int> (1,A.at(0)+1));
    std::unordered_map<int,int> timesInA_map {};
    std::unordered_map<int,int> winwin_map {};
    for (auto i = 0; i != 2 + M; ++i)
    {
        timesInA_map[i] = 0;
        winwin_map[i] = 0;
    }
    for (const auto & item: A)
        timesInA_map[item]++;
    if(1 != K)
    {
        std::unordered_map<int,int> temp_map{};
        for (auto i = 0; i != 2 + M; ++i)
            temp_map[i] = 0;
        for (auto i = 0; i != K; ++i)
            temp_map[A.at(i)] += 1;

        for (auto i = 0; i!=1 + M; ++i)
        {
            winwin_map[1+i] = (temp_map.at(i) - temp_map.at(1 + i));
        }

        for (auto i = K; i != A_sz; ++i )
        {
            int ll = A.at(i);
            temp_map[ll]++;
            int vv = A.at(i-K);
            temp_map[vv]--;
            int hh = temp_map[ll] - temp_map[ll+1];
            if(hh > winwin_map[ll+1])
                winwin_map[ll+1] = hh;
            hh = temp_map[vv] - temp_map[vv+1];
            if(hh > winwin_map[vv+1])
                winwin_map[vv+1] = hh;
            hh = temp_map[ll -1] - temp_map[ll];
            if(hh > winwin_map[ll])
                winwin_map[ll] = hh;
            hh = temp_map[vv -1] - temp_map[vv];
            if(hh > winwin_map[vv])
                winwin_map[vv] = hh;
       }
       for (auto i = 0; i!=1 + M; ++i)
       {
           int uu = temp_map[i] - temp_map[1+i];
           if (uu > winwin_map[1+i])
               winwin_map[1+i] = uu;
       }
    }
    else
    {
        for (auto i = 1; i != 1 + M; ++i)
            if(0 != timesInA_map[i])
                winwin_map[1+i] = 1;
    }

    std::map<int,int,std::less<int>> l_ret {};
    for (auto i = 1; i != 2 + M; ++i)
        if(2*(timesInA_map[i] +  winwin_map[i]) > A_sz)
            l_ret[i] = 1;
    std::vector<int> l_retV{};
    l_retV.reserve(l_ret.size());
    for(auto const& imap: l_ret)
        l_retV.push_back(imap.first);
    return l_retV;
}

