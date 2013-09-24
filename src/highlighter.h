#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H
//
#include <QSyntaxHighlighter>
//
class highlighter : public QSyntaxHighlighter
{
Q_OBJECT
public:
	highlighter(QTextDocument *parent = 0);
 protected:
     void highlightBlock(const QString &text);

private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QRegExp commentStartExpression;
     QRegExp commentEndExpression;

     QTextCharFormat keywordFormat;
     QTextCharFormat classFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat functionFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat xmlFormat;
};
#endif
