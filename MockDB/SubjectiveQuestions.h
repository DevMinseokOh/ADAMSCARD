#ifndef SUBJECTIVEQUESTIONS_H
#define SUBJECTIVEQUESTIONS_H

#include <QPixmap>
#include <QString>

class SubjectiveQuestion
{
private:
    QString m_Question;
    QPixmap m_QuestionImage;
    QString m_Answer;

public:
    SubjectiveQuestion();
};

#endif // SUBJECTIVEQUESTIONS_H
