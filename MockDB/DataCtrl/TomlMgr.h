#ifndef TOMLMGR_H
#define TOMLMGR_H

#include <QString>

class UserInformation;

class TomlMgr
{
public:
    TomlMgr();

    bool WriteUserInfoData(QString filePath, UserInformation* userInformation);
    bool ReadUserInfoData(QString filePath, UserInformation* userInformation);
};

#endif // TOMLMGR_H
