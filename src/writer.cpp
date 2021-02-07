#include "writer.h"

void change(qfile* file, unsigned int id, std::string dataSet, std::string data){
    for(unsigned int i = 0; i < file->getData()->size(); i++){
        if(file->getData()->at(i).id == dataSet){
            file->getData()->at(i).dataSet[id-1] = data;
        }
    }
}

void erase(qfile* file, unsigned int id){
    if(id<=file->getData()->at(0).dataSet.size()){
        for(unsigned int i = 0; i < file->getData()->size(); i++){
            file->getData()->at(i).dataSet.erase(file->getData()->at(i).dataSet.begin()+id-1);
        }
    }
}

void eraseSet(qfile* file, std::string dataSet){
    for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
        if(it->id == dataSet){
            file->getData()->erase(it);
            it--;
        }
    }
}
