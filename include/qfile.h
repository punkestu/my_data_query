#ifndef QFILE_H
#define QFILE_H

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <string>

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
    void create(std::string fileN, bool force = false);
    void init(std::string fileP);
    void save(std::string fileN);
    void clear();
    unsigned int dsLength(){return container.size()!=0?container[0].dataSet.size():0;}
    unsigned int nDataSet(){return container.size();}
    data* getData(){return &container;}
};

#endif // QFILE_H
