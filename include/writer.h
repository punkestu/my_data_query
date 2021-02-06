#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <fstream>
#include <map>

class writer{
private:
    std::fstream write;
public:
    void create(std::string queryName);
    void write()
};

#endif // WRITER_H
