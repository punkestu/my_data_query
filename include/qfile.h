#ifndef QFILE_H
#define QFILE_H

#include <string>
#include <fstream>
#include <map>
#include <vector>

class qfile{
private:
    std::fstream io;
    std::map<std::string, std::vector<std::string>> container;
public:
    void init(std::string fileP);
    void save();
};

#endif // QFILE_H
