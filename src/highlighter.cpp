#include "highlighter.h"
//
highlighter::highlighter(QTextDocument * parent) : QSyntaxHighlighter(parent)
{
     HighlightingRule rule;

     keywordFormat.setForeground(Qt::darkBlue);
     keywordFormat.setFontWeight(QFont::Bold);
     QStringList keywordPatterns;
     keywordPatterns << "\\bcd\\b" << "\\bchdir\\b" << "\\bmd\\b"
                     << "\\bmkdir\\b" << "\\bconfigure\\b" << "\\bcmake\\b"
                     << "\\bcp\\b" << "\\bcat\\b" << "\\bqmake\\b"
                     << "\\bmake\\b" << "\\blrelease\\b" << "\\bmv\\b"
                     << "\\bif\\b" << "\\bthen\\b" << "\\becho\\b"
                     << "\\btest\\b" << "\\bgrep\\b" << "\\btail\\b"
                     << "\\belse\\b" << "\\bwhile\\b" << "\\bcontinue\\b"
                     << "\\bdone\\b" << "\\bread\\b" << "\\bln\\b"
                     << "\\bdo\\b" << "\\brmdir\\b" << "\\brm\\b"
                     << "\\bexport\\b" << "\\bfor\\b" << "\\bin\\b"
                     << "\\binstall\\b" << "\\bchmod\\b" << "\\brun\\b"
                     << "\\belif\\b" << "\\bfi\\b" << "\\btrue\\b"
                     << "\\bfind\\b" << "\\bgrep\\b" << "\\bawk\\b"
                     << "\\bsed\\b" << "\\bcmp\\b" << "\\bpushd\\b"
                     << "\\bpopd\\b" << "\\btee\\b" << "\\bcase\\b"
                     << "\\besac\\b" << "\\bpython\\b" << "\\btar\\b"
                     << "\\bcpio\\b" << "\\bfile\\b" << "\\bgpg\\b"
                     << "\\bgzip\\b" << "\\bid\\b" << "\\blzma\\b"
                     << "\\bxz\\b" << "\\bpatch\\b" << "\\bperl\\b"
                     << "\\bpgp\\b" << "\\brsh\\b" << "\\bssh\\b"
                     << "\\bunzip\\b" << "\\bsh\\b" << "\\bg++\\b"
                     << "\\bld\\b" << "\\bnm\\b" << "\\bstrip\\b"
                     << "\\blibtoolize\\b" << "\\baclocal\\b" << "\\bautoheader\\b"
                     << "\\bautomake\\b" << "\\bautoconf\\b"
                     ;
                     
     foreach (const QString &pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }
     
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::darkMagenta);

     keywordPatterns.clear();;
     keywordPatterns << "%\\{buildroot\\}" << "%\\{name\\}" << "%\\{version\\}"
                       << "%\\{_bindir\\}" << "%\\{_datadir\\}" << "%\\{SOURCE\\d\\}"
                       << "%defattr\\(.*\\)" << "%attr\\(\\d+\\{\\},.*,.*\\)"
                     ;

     foreach (const QString &pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = classFormat;
         highlightingRules.append(rule);
     }
/*
     rule.pattern = QRegExp("\\b_[A-Za-z]+\\b");
     rule.format = classFormat;
     highlightingRules.append(rule);
*/

     quotationFormat.setForeground(Qt::darkGreen);
     rule.pattern = QRegExp("\".*\"");
     rule.format = quotationFormat;
     highlightingRules.append(rule);

     functionFormat.setFontItalic(true);
     functionFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("%.* ");
     rule.format = classFormat;
     highlightingRules.append(rule);
     
     singleLineCommentFormat.setForeground(Qt::red);
     rule.pattern = QRegExp("#[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);
     
     xmlFormat.setForeground(Qt::cyan);
     rule.pattern = QRegExp("<.*>");
     rule.format = xmlFormat;
     highlightingRules.append(rule);
     
     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");
}

void highlighter::highlightBlock(const QString &text)
 {
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     
     setCurrentBlockState(0);
     
     int startIndex = 0;
     if (previousBlockState() != 1) startIndex = commentStartExpression.indexIn(text);
     
     while (startIndex >= 0) {
         int endIndex = commentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + commentEndExpression.matchedLength();
         }
         startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
//
