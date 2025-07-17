#ifndef USERINFORMATION_H
#define USERINFORMATION_H

#include <QDateTime>
#include <QList>
#include <QPixmap>
#include <QString>

class Collection;

class UserInformation
{
public:
    enum class AuthProvider { Local, Google, GitHub, Unknown };

private:
    QString m_UserName;
    QPixmap m_ProfileImage;
    QString m_Password;
    QString m_Email;
    QString m_GeminiApiKey;
    AuthProvider m_AuthProvider;
    QString m_ProviderId;

    QDateTime m_CreateTime;
    QDateTime m_UpdateTime;

    QList<Collection*> m_Collection;

public:
    // Constructor & Destructor
    UserInformation();
    ~UserInformation();

    // region Getter
    QString GetUserName() const;
    QPixmap GetProfileImage() const;
    QString GetPassword() const;
    QString GetEmail() const;
    QString GetGeminiApiKey() const;
    AuthProvider GetAuthProvider() const;
    QString GetProviderId() const;
    QDateTime GetCreateTime() const;
    QDateTime GetUpdateTime() const;
    QList<Collection*> GetCollection() const;
    // endregion

    // region Setter
    void SetUserName(const QString& UserName);
    void SetProfileImage(const QPixmap& ProfileImage);
    void SetPassword(const QString& Password);
    void SetEmail(const QString& Email);
    void SetGeminiApiKey(const QString& ApiKey);
    void SetAuthProvider(AuthProvider Provider);
    void SetProviderId(const QString& ProviderId);
    void SetCreateTime(const QDateTime& CreateTime);
    void SetUpdateTime(const QDateTime& UpdateTime);
    void SetCollection(QList<Collection*> collection);
    void AddCollection(Collection* collection);
    // endregion
};

#endif // USERINFORMATION_H
