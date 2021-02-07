#ifndef QFILE_H
#define QFILE_H

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>

struct dataG{
    unsigned int longest;
    std::string id;
    std::vector<std::string> dataSet;
};

using data = std::vector<dataG>;

class qfile{
private:
    std::fstream io;
    data container;
public:
    void init(std::string fileP);
    void save(std::string fileN);
    unsigned int dsLength(){return container.size()!=0?container[0].dataSet.size():0;}
    data* getData(){return &container;}
};

#endif // QFILE_H
