#ifndef COLLECTION_H
#define COLLECTION_H

#include <QList>
#include <QPixmap>
#include <QString>

class MultipleChoiceQuestion;
class SubjectiveQuestion;

class Collection
{
private:
    QString m_Name;
    QString m_Explanation;
    QPixmap m_RepresentativeImage;

    QList<MultipleChoiceQuestion *> m_multipleChoiceQuestions;
    QList<SubjectiveQuestion *> m_subjectiveQuestions;

public:
    Collection();
};

#endif // COLLECTION_H
