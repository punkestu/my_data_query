#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <map>

class reader{
private:
public:
    std::string read(int id, std::string parent);
};

#endif // READER_H
