#include "reader.h"

void summary(qfile* file){
    std::cout<<"+-";
    for(unsigned int i = 0; i < std::to_string(file->dsLength()).size(); i++){std::cout<<"-";}std::cout<<"-+-";
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        for(unsigned int j = 0; j < file->getData()->at(i).longest; j++){std::cout<<"-";}
        if(i+1 == file->nDataSet()){
            std::cout<<"-+";
        }else{
            std::cout<<"-+-";
        }
    }std::cout<<std::endl;
    std::cout<<"| id";for(unsigned int i = 0; i < std::to_string(file->dsLength()).size()-2; i++){std::cout<<" ";}std::cout<<" | ";
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        std::cout<<file->getData()->at(i).id;
        for(unsigned int j = 0; j < file->getData()->at(i).longest-file->getData()->at(i).id.size(); j++){std::cout<<" ";}
        std::cout<<" | ";
    }std::cout<<std::endl;
    std::cout<<"+-";
    for(unsigned int i = 0; i < std::to_string(file->dsLength()).size(); i++){std::cout<<"-";}std::cout<<"-+-";
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        for(unsigned int j = 0; j < file->getData()->at(i).longest; j++){std::cout<<"-";}
        if(i+1 == file->nDataSet()){
            std::cout<<"-+";
        }else{
            std::cout<<"-+-";
        }
    }std::cout<<std::endl;
    for(unsigned int i = 0; i < file->dsLength(); i++){
        std::cout<<"| "<<i+1;
        for(unsigned int j = 0; j < std::to_string(file->dsLength()).size()-std::to_string(i+1).size(); j++){std::cout<<" ";}
        std::cout<<" | ";

        for(data::iterator it = file->getData()->begin(); it != file->getData()->end(); it++){
            std::cout<<it->dataSet[i];
            for(unsigned int j = 0; j < it->longest - it->dataSet[i].size(); j++){std::cout<<" ";}
            std::cout<<" | ";
        }

        std::cout<<std::endl;
    }
    std::cout<<"+-";
    for(unsigned int i = 0; i < std::to_string(file->dsLength()).size(); i++){std::cout<<"-";}std::cout<<"-+-";
    for(unsigned int i = 0; i < file->nDataSet(); i++){
        for(unsigned int j = 0; j < file->getData()->at(i).longest; j++){std::cout<<"-";}
        if(i+1 == file->nDataSet()){
            std::cout<<"-+";
        }else{
            std::cout<<"-+-";
        }
    }std::cout<<std::endl;
}
