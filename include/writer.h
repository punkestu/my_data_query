#ifndef WRITER_H
#define WRITER_H

#include <qfile.h>

void change(qfile* file, unsigned int id, std::string dataSet, std::string data);
void erase(qfile* file, unsigned int id);

#endif // WRITER_H
