#include "UserInformation.h"
#include "Collection.h"

UserInformation::UserInformation()
    : m_AuthProvider(AuthProvider::Unknown)
    , m_CreateTime(QDateTime::currentDateTime())
    , m_UpdateTime(QDateTime::currentDateTime())
{}

UserInformation::~UserInformation() {}

QString UserInformation::GetUserName() const
{
    return m_UserName;
}

QPixmap UserInformation::GetProfileImage() const
{
    return m_ProfileImage;
}

QString UserInformation::GetPassword() const
{
    return m_Password;
}

QString UserInformation::GetEmail() const
{
    return m_Email;
}

QString UserInformation::GetGeminiApiKey() const
{
    return m_GeminiApiKey;
}

UserInformation::AuthProvider UserInformation::GetAuthProvider() const
{
    return m_AuthProvider;
}

QString UserInformation::GetProviderId() const
{
    return m_ProviderId;
}

QDateTime UserInformation::GetCreateTime() const
{
    return m_CreateTime;
}

QDateTime UserInformation::GetUpdateTime() const
{
    return m_UpdateTime;
}

QList<Collection*> UserInformation::GetCollection() const
{
    return m_Collection;
}

void UserInformation::SetUserName(const QString& UserName)
{
    m_UserName = UserName;
}

void UserInformation::SetProfileImage(const QPixmap& ProfileImage)
{
    m_ProfileImage = ProfileImage;
}

void UserInformation::SetPassword(const QString& Password)
{
    m_Password = Password;
}

void UserInformation::SetEmail(const QString& Email)
{
    m_Email = Email;
}

void UserInformation::SetGeminiApiKey(const QString& ApiKey)
{
    m_GeminiApiKey = ApiKey;
}

void UserInformation::SetAuthProvider(AuthProvider Provider)
{
    m_AuthProvider = Provider;
}

void UserInformation::SetProviderId(const QString& ProviderId)
{
    m_ProviderId = ProviderId;
}

void UserInformation::SetCreateTime(const QDateTime& CreateTime)
{
    m_CreateTime = CreateTime;
}

void UserInformation::SetUpdateTime(const QDateTime& UpdateTime)
{
    m_UpdateTime = UpdateTime;
}

void UserInformation::SetCollection(QList<Collection*> collection)
{
    m_Collection = collection;
}

void UserInformation::AddCollection(Collection* collection)
{
    m_Collection.push_back(collection);
}
