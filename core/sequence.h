#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <QtCore>
#include "nucleotidalphabet.h"
#include "proteinalphabet.h"

class Sequence
{
public:
    enum Type {
        Dna     = 0x01,
        Rna     = 0x02,
        Protein = 0x03
    };

    enum Strand {
        Forward = 0x01, // 5' to 3'
        Reverse = 0x02  // 3' to 5'
    };

    enum ReadFame{
        Frame1,
        Frame2,
        Frame3
    };

    // to String format
    enum Format {
        SymbolFormat,
        ShortFormat,
        HumanFormat
    };

    Sequence(const char *data);
    Sequence(const QByteArray& bytes);
    Sequence();
    Sequence(const QByteArray& bytes, Strand strand, Type type);

    Sequence complement() const;
    Sequence translate(ReadFame frame = Frame1) const;
    Sequence reverse() const;

    QString name() const;
    void setName(const QString &name);

    Strand strand() const;
    void setStrand(const Strand &strand);

    Type type() const;
    void setType(const Type &type);

    QString typeName();

    int length() const;
    char at(int index) const;

    void setByteArray(const QByteArray& array);
    const QByteArray& byteArray() const;
    QString toString(Format format = Format::SymbolFormat) const;

    float gcPercent() const;


    void append(char base);

    void cut(int start, int len);



private:
    QByteArray mArray;
    Strand mStrand;
    Type mType;
    QString mName;


};

#endif // SEQUENCE_H
