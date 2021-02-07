#include "writer.h"

void change(qfile* file, unsigned int id, std::string dataSet, std::string data){
    for(unsigned int i = 0; i < file->getData()->size(); i++){
        if(file->getData()->at(i).id == dataSet){
            file->getData()->at(i).dataSet[id-1] = data;
        }
    }
}

void erase(qfile* file, unsigned int id){
    std::cout<<file->getData()->at(0).dataSet.size()<<std::endl;
    if(id<=file->getData()->at(0).dataSet.size()){
        for(unsigned int i = 0; i < file->getData()->size(); i++){
            file->getData()->at(i).dataSet.erase(file->getData()->at(i).dataSet.begin()+id-1);
        }
    }
}
