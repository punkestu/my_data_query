#ifndef READER_H
#define READER_H

#include "qfile.h"

namespace bque{
    void summary(qfile* file);
    std::string get(qfile* file, unsigned int id, std::string dataSet);
}

#endif // READER_H
