#include "db.h"
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost;

DB::DB()
{
    GetConfInfo();
}

DB::~DB()
{
    delete mConn;
}
void DB::GetConfInfo()
{
    property_tree::ptree pt;
    read_json("./conf/configure.json",pt);
    pt = pt.get_child("DB");
    mDBIP = pt.get<std::string>("DBIP");
    mDBPort = pt.get<std::string>("DBPort");
    mDBName = pt.get<std::string>("DBName");
    mDBUser = pt.get<std::string>("DBUser");
    mDBUserPWD = pt.get<std::string>("DBUserPWD");
}

void DB::InitDBConn()
{
    std::stringstream ss;
    ss<<"hostaddr="<<mDBIP<<" port="<<mDBPort
     <<" dbname="<<mDBName<<" user="<<mDBUser
     <<" password="<<mDBUserPWD;
    mConn = new pqxx::connection(ss.str());
    if(mConn->is_open())
        std::cout<<"connect successed"<<std::endl;
}
