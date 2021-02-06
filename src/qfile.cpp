#include "qfile.h"

void qfile::init(std::string fileP){
    io.open(fileP.c_str(), std::ios_base::in);
    if(!io.fail()){
        std::cout<<"init"<<std::endl;
        unsigned int line = 0;
        while(!io.eof()){
            std::string temp;
            io>>temp;
            if(temp == "[n]"){
                line++;
                std::cout<<"no"<<std::endl;
            }else{
                if(line == 0){
                    dataG dataT;
                    dataT.id = temp;
                    container.push_back(dataT);
                    container[line].longest = 0;
                }else{
                    if(line<=container.size()){
                        std::cout<<"add"<<std::endl;
                        container[line-1].dataSet.push_back(temp);
                        if(container[line-1].longest<temp.size()){
                            container[line-1].longest = temp.size();
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        std::cout<<"end loop"<<std::endl;
    }else{
        std::cout<<"fail to init"<<std::endl;
    }

    io.close();
}
