#include <iostream>

using namespace std;
int modulo(int a, int n)
{
    int q=a/n;
    int r= a-(q*n);
    if(r<0)
        return n-r;
    return r;

}

int euclides(int a, int b)
{
    int r;
    while(b!= 0)
    {
        r= modulo(a,b);
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    cout << euclides(15,26);
}
