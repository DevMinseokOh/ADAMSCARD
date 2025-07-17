#ifndef JSONMGR_H
#define JSONMGR_H

#include <QString>

class UserInformation;

class JsonMgr
{
public:
    JsonMgr();

    bool WriteUserInfoData(QString filePath, UserInformation* userInformation);
    bool ReadUserInfoData(QString filePath, UserInformation* userInformation);
};

#endif // JSONMGR_H
