#include <vector>
#include <algorithm>
int solution(vector<int> &A) 
{
	if(A.empty()) return 1;
	std::sort(A.begin(),A.end());
	auto last = std::unique(A.begin(),A.end());
	A.erase(last,A.end());
	std::remove_if(A.begin(), A.end(), [] (const auto & item) {return item < 1;});
	auto iter = A.begin();
	for (auto i = 1; ; ++i)
	{
		iter = std::find(iter,A.end(),i);
		if(iter != A.end())
			continue;
		else
			return i;
	}
}


//another solution

#include <vector>
#include <algorithm>
int solution(vector<int> &A)
{
    if(A.empty())return 1;
    A.erase(std::remove_if(A.begin(),A.end(),[](const int & item){return (item < 1);}),A.end());
    if(A.empty())return 1;
    std::sort(A.begin(),A.end());
    auto  it = std::unique(A.begin(),A.end());
    if(A.empty() || A.front() != 1) return 1;
    int l_ret = 1;
    for(auto iter = A.begin(); iter != it -1; ++iter)
    {
        if((*iter)+1 != (*(iter+1)))
        {
           return (*iter)+1;
        }
        l_ret++;
    }
    return ++l_ret;
}
