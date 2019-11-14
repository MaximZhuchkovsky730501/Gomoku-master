#ifndef ADMIN_H
#define ADMIN_H


class admin
{
public:
    admin();
    int takesize();
    void setsize(int n);

private:
    int size;
};

static admin user;

#endif // ADMIN_H

