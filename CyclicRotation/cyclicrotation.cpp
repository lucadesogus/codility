#include <vector>
#include <algorithm> 
std::vector<int> solution(vector<int> &A, int K)
{
    if(A.empty() ||  K < 0 || A.size() == K)
        return A;
    int rotations = K;
    if(K > A.size())
       rotations = K % A.size();
    std::rotate(A.begin(),A.end()-rotations  ,A.end());
    return A;
}
