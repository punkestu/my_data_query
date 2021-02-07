#include "writer.h"

void change(qfile* file, unsigned int id, std::string dataSet, std::string data){
    for(unsigned int i = 0; i < file->getData()->size(); i++){
        if(file->getData()->at(i).id == dataSet){
            file->getData()->at(i).dataSet[id-1] = data;
            break;
        }
    }
}

void add(qfile* file, unsigned int id, std::string dataSet, std::string data){
    for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
        if(it->id == dataSet){
            if(id>file->dsLength()){
                it->dataSet.push_back(data);
            }else{
                it->dataSet.insert(it->dataSet.begin()+id-1, data);
            }
            break;
        }
    }
}

void addSet(qfile* file, unsigned int order, std::string dataSet){
    dataG dSet;
    dSet.id = dataSet;
    dSet.longest = 0;
    for(unsigned int i = 0; i < file->dsLength(); i++){
        dSet.dataSet.push_back("-");
    }
    file->getData()->insert(file->getData()->begin()+order-1, dSet);
}

void erase(qfile* file, unsigned int id){
    if(id<=file->dsLength()){
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
            break;
        }
    }
}

void moveSet(qfile* file, std::string dataSet, unsigned int newPos){
    dataG dataBuffer;
    for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
        if(it->id == dataSet){
            dataBuffer = *it;
            file->getData()->erase(it);
            it--;
            break;
        }
    }
    if(newPos<file->getData()->size()){
        file->getData()->insert(file->getData()->begin()+newPos-1, dataBuffer);
    }else{
        file->getData()->push_back(dataBuffer);
    }
}
