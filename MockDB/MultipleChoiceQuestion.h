#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include <QPixmap>
#include <QString>

class MultipleChoiceQuestion
{
private:
    QString m_QuestionText;
    QPixmap m_QuestionImage;

public:
    MultipleChoiceQuestion();
};

#endif // MULTIPLECHOICEQUESTION_H
