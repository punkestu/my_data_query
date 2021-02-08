#include "reader.h"

void bque::summary(qfile* file){
    if(file->nDataSet()!=0){
        if(file->dsLength()!=0){
            //top border
            std::cout<<"+-";
            for(unsigned int i = 0; i < (std::to_string(file->dsLength()).size()>(unsigned int)(2)?
                                         std::to_string(file->dsLength()).size():2); i++){
                std::cout<<"-";
            }
            std::cout<<"-+-";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                for(unsigned int j = 0;
                j < (file->getData()->at(i).longest > file->getData()->at(i).id.size()?
                     file->getData()->at(i).longest:file->getData()->at(i).id.size()); j++)
                {std::cout<<"-";}
                if(i+1!=file->nDataSet()){
                    std::cout<<"-+-";
                }else{
                    std::cout<<"-+";
                }
            }
            std::cout<<std::endl;
            //
            //set name
            std::cout<<"| id";
            for(unsigned int i = 0; i < (std::to_string(file->dsLength()).size()>(unsigned int)(2)?
                                         std::to_string(file->dsLength()).size()-2:0); i++){
                std::cout<<" ";
            }
            std::cout<<" | ";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                std::cout<<file->getData()->at(i).id;
                for(unsigned int j = 0;
                j < file->getData()->at(i).longest-file->getData()->at(i).id.size(); j++)
                {std::cout<<" ";}
                if(i+1!=file->nDataSet()){
                    std::cout<<" | ";
                }else{
                    std::cout<<" |";
                }
            }
            std::cout<<std::endl;
            //
            //mid border
            std::cout<<"+-";
            for(unsigned int i = 0; i < (std::to_string(file->dsLength()).size()>(unsigned int)(2)?
                                         std::to_string(file->dsLength()).size():2); i++){
                std::cout<<"-";
            }
            std::cout<<"-+-";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                for(unsigned int j = 0;
                j < (file->getData()->at(i).longest > file->getData()->at(i).id.size()?
                     file->getData()->at(i).longest:file->getData()->at(i).id.size()); j++)
                {std::cout<<"-";}
                if(i+1!=file->nDataSet()){
                    std::cout<<"-+-";
                }else{
                    std::cout<<"-+";
                }
            }
            std::cout<<std::endl;
            //
            //data list
            for(unsigned int j = 0; j < file->dsLength(); j++){
                std::cout<<"| "<<j+1;
                for(unsigned int i = 0; i < (std::to_string(file->dsLength()).size()>(unsigned int)(2)?
                                             std::to_string(file->dsLength()).size()-std::to_string(j+1).size():
                                             (unsigned int)(2)-std::to_string(j+1).size()); i++){
                    std::cout<<" ";
                }
                std::cout<<" | ";
                for(unsigned int i = 0; i < file->nDataSet(); i++){
                    std::cout<<file->getData()->at(i).dataSet[j];
                    for(unsigned int k = 0; k < file->getData()->at(i).longest-file->getData()->at(i).dataSet[j].size(); k++)
                    {std::cout<<" ";}
                    std::cout<<" | ";
                }
                std::cout<<std::endl;
            }
            //
            //bottom border
            std::cout<<"+-";
            for(unsigned int i = 0; i < (std::to_string(file->dsLength()).size()>(unsigned int)(2)?
                                         std::to_string(file->dsLength()).size():2); i++){
                std::cout<<"-";
            }
            std::cout<<"-+-";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                for(unsigned int j = 0;
                j < (file->getData()->at(i).longest > file->getData()->at(i).id.size()?
                     file->getData()->at(i).longest:file->getData()->at(i).id.size()); j++)
                {std::cout<<"-";}
                if(i+1!=file->nDataSet()){
                    std::cout<<"-+-";
                }else{
                    std::cout<<"-+";
                }
            }
            std::cout<<std::endl;
            //
        }else{
            //top border
            std::cout<<"+----+-";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                for(unsigned int j = 0; j < file->getData()->at(i).id.size(); j++){std::cout<<"-";}
                if(i+1!=file->nDataSet()){
                    std::cout<<"-+-";
                }else{
                    std::cout<<"-+";
                }
            }
            std::cout<<std::endl;
            //
            //set name
            std::cout<<"| id | ";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                std::cout<<file->getData()->at(i).id;
                if(i+1!=file->nDataSet()){
                    std::cout<<" | ";
                }else{
                    std::cout<<" |";
                }
            }
            std::cout<<std::endl;
            //
            //bottom border
            std::cout<<"+----+-";
            for(unsigned int i = 0; i < file->nDataSet(); i++){
                for(unsigned int j = 0; j < file->getData()->at(i).id.size(); j++){std::cout<<"-";}
                if(i+1!=file->nDataSet()){
                    std::cout<<"-+-";
                }else{
                    std::cout<<"-+";
                }
            }
            std::cout<<std::endl;
            //
        }
    }else{
        std::cout<<"i*blank query"<<std::endl;
    }
}
