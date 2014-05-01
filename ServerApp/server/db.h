#ifndef DB_H
#define DB_H

#include <pqxx/pqxx>

class DB
{
public:
    DB();
    ~DB();
    void InitDBConn();
    pqxx::connection* GetConn(){return mConn;}
private:
    void GetConfInfo();
private:
    pqxx::connection* mConn;
    std::string       mDBIP;
    std::string       mDBPort;
    std::string       mDBName;
    std::string       mDBUser;
    std::string       mDBUserPWD;
};

#endif // DB_H
