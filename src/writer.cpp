#include "writer.h"

void bque::change(qfile* file, unsigned int id, std::string dataSet, std::string data){
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        if(file->getData()->at(i).id == dataSet){
            file->getData()->at(i).dataSet[id-1] = data;
            std::cout<<"i*data changed"<<std::endl;
            break;
        }
    }
}

void bque::add(qfile* file, unsigned int id, std::string dataSet, std::string data){
    if(file->nDataSet()!=0){
        bool exist = false;
        for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
            if(it->id == dataSet){
                exist = true;
                break;
            }
        }
        if(exist){
            for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
                if(it->id == dataSet){
                    if(it->longest<data.size()){
                        it->longest = data.size();
                    }
                    if(id>file->dsLength()){
                        it->dataSet.push_back(data);
                    }else{
                        it->dataSet.insert(it->dataSet.begin()+id-1, data);
                    }
                    std::cout<<"i*data added"<<std::endl;
                }else{
                    if(it->longest<1){
                        it->longest = 1;
                    }
                    if(id>file->dsLength()){
                        it->dataSet.push_back("-");
                    }else{
                        it->dataSet.insert(it->dataSet.begin()+id-1, "-");
                    }
                }
            }
        }else{
            std::cout<<"i*set not found"<<std::endl;
        }
    }else{
        std::cout<<"i*query is empty, set not found"<<std::endl;
    }
}

void bque::addSet(qfile* file, unsigned int order, std::string dataSet){
    bool exist = false;
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        if(file->getData()->at(i).id == dataSet){exist = true; break;}
    }
    if(!exist){
        dataG dSet;
        dSet.id = dataSet;
        dSet.longest = 0;
        for(unsigned int i = 0; i < file->dsLength(); i++){
            dSet.dataSet.push_back("-");
        }
        if(file->nDataSet()>order){
            file->getData()->insert(file->getData()->begin()+order-1, dSet);
        }else{
            file->getData()->push_back(dSet);
        }
        std::cout<<"i*set created"<<std::endl;
    }else{
        std::cout<<"i*set existed"<<std::endl;
    }
}

void bque::erase(qfile* file, unsigned int id){
    if(id<=file->dsLength()){
        for(unsigned int i = 0; i < file->nDataSet(); i++){
            file->getData()->at(i).dataSet.erase(file->getData()->at(i).dataSet.begin()+id-1);
        }
        std::cout<<"i*data erased"<<std::endl;
    }
}

void bque::eraseSet(qfile* file, std::string dataSet){
    for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
        if(it->id == dataSet){
            file->getData()->erase(it);
            it--;
            std::cout<<"i*set erased"<<std::endl;
            break;
        }
    }
}

void bque::moveSet(qfile* file, std::string dataSet, unsigned int newPos){
    dataG dataBuffer;
    bool exist = false;
    for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
        if(it->id == dataSet){
            exist = true;
            dataBuffer = *it;
            file->getData()->erase(it);
            it--;
            break;
        }
    }
    if(exist){
        if(newPos<file->getData()->size()){
            file->getData()->insert(file->getData()->begin()+newPos-1, dataBuffer);
        }else{
            file->getData()->push_back(dataBuffer);
        }
        std::cout<<"i*moved"<<std::endl;
    }else{
        std::cout<<"i*set not found"<<std::endl;
    }
}
