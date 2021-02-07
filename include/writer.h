#ifndef WRITER_H
#define WRITER_H

#include <qfile.h>

void change(qfile* file, unsigned int id, std::string dataSet, std::string data);
void erase(qfile* file, unsigned int id);
void eraseSet(qfile* file, std::string dataSet);

#endif // WRITER_H
