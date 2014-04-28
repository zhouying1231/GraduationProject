#include <iostream>
#include "db.h"

using namespace std;

int main()
{
    DB* mDB = new DB();
    mDB->InitDBConn();
    return 0;
}

