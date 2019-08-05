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