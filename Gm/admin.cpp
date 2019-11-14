#include "admin.h"

admin::admin()
{
    size=18;
}

int admin::takesize()
{
    return size+1;
}

void admin::setsize(int n)
{
    if (n>0 && n<20) size=n-1;
}

