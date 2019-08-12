int solution(int A, int B, int K)
{
    if(B < A) return 0;
    if(K == 1) return (B - A  + 1);
    int l_ret = 0;
    for(auto i = A; i != B + 1; ++i)
    {
        if(i % K == 0)//first number divisible by K
        {
            l_ret = 1+ ( (B - i) / K);
            break;
        }
    }
    return l_ret;
}
