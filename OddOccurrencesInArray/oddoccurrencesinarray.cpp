#include <unordered_map>
int solution(vector<int> &A)
{
    std::unordered_map<int,int> map {};
    for (auto item:A)
    {
        if(map.count(item))
            map[item]++;
        else
            map[item] = 1;
    }
    for(auto item : map)
        if(item.second % 2)
            return item.first;

}
