#include "abstracttracereader.h"

AbstractTraceReader::AbstractTraceReader(QIODevice *device)
    :mDevice(device)
{

}

Trace AbstractTraceReader::trace() const
{
    Trace tt;

    tt.setBaseLocations(baseLocations());
    tt.setConfScores(confScores());
    tt.setTraces(traces());


    return tt;

}

QIODevice *AbstractTraceReader::device()
{
    return mDevice;
}
QStringList AbstractTraceReader::keys() const
{
    return mComments.keys();
}
QVariant AbstractTraceReader::value(const QString& key)
{
    return mComments.value(key);
}

void AbstractTraceReader::addComment(const QString& key, const QVariant& value)
{
    mComments[key]= value;
}

void AbstractTraceReader::clearComments()
{
    mComments.clear();
}