#ifndef YAMLMGR_H
#define YAMLMGR_H

#include <QString>

class UserInformation;

class YamlMgr
{
public:
    YamlMgr();

    bool WriteUserInfoData(QString filePath, UserInformation* userInformation);
    bool ReadUserInfoData(QString filePath, UserInformation* userInformation);
};

#endif // YAMLMGR_H
