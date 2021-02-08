#ifndef WRITER_H
#define WRITER_H

#include "reader.h"

namespace bque{
    void change(qfile* file, unsigned int id, std::string dataSet, std::string data);
    void add(qfile* file, unsigned int id, std::string dataSet, std::string data);
    void addSet(qfile* file, unsigned int order, std::string dataSet);
    void erase(qfile* file, unsigned int id);
    void eraseSet(qfile* file, std::string dataSet);
    void moveSet(qfile* file, std::string dataSet, unsigned int newPos);
}

#endif // WRITER_H
