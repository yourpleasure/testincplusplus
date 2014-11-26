#ifdef MAIN1
#include <iostream>
using namespace std;
int main()
{
    int *p = new int[2];
    p[0] = 0;
    p[1] = 1;
    p++;
    cout << *p << endl;
    delete --p;
    return 0;
}
#endif
