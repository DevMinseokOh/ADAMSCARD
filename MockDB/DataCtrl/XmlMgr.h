#ifndef XMLMGR_H
#define XMLMGR_H

#include <QString>

class UserInformation;

class XmlMgr
{
public:
    XmlMgr();

    bool WriteUserInfoData(QString filePath, UserInformation* userInformation);
    bool ReadUserInfoData(QString filePath, UserInformation* userInformation);
};

#endif // XMLMGR_H
