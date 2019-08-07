int solution(int X, int Y, int D)
{
 if(Y <= X)
     return 0;
 if(D >= (Y - X))
     return 1;
 int m = (Y - X) % D;
 return ((Y - X) / D) + (m?1:0);
}
