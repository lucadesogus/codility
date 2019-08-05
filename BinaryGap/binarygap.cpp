int solution(int N) {
    int l_ret = 0;
    int temp = N;
    bool lf = false;
    int max = 0;
    while (temp != 0)
    {
        if(temp & 0x01 != 0)
        {
            lf = true;
            if(max != 0)
            {
                l_ret = max > l_ret ? max : l_ret;
                max = 0;
            }
        }
        else if( lf == true)
            max ++;
        temp = temp >> 1;
    }
    return l_ret;
}
