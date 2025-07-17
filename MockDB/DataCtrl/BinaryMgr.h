#ifndef BINARYMGR_H
#define BINARYMGR_H

#include <QString>

class UserInformation;

class BinaryMgr
{
public:
    BinaryMgr();

    bool WriteUserInfoData(QString filePath, UserInformation* userInformation);
    bool ReadUserInfoData(QString filePath, UserInformation* userInformation);
};

#endif // BINARYMGR_H
