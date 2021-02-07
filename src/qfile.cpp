#include "qfile.h"

void qfile::init(std::string fileP){
    io.open(fileP.c_str(), std::ios_base::in);
    if(!io.fail()){
        std::cout<<"init"<<std::endl;
        unsigned int line = 0;
        unsigned int dataN = 0;
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
                    container[dataN].longest = temp.size();
                    dataN++;
                }else{
                    if(line<=container.size()){
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

void qfile::save(std::string fileN){
    io.open(fileN.c_str(), std::ios_base::out|std::ios_base::ate);
    if(!io.fail()){

    for(unsigned int i = 0; i < container.size(); i++){
        io<<container[i].id;
        io<<" ";
    }
    io<<"[n]\n";
    for(unsigned int i = 0; i < container.size(); i++){
        for(unsigned int j = 0; j < container[i].dataSet.size(); j++){
            io<<container[i].dataSet[j];
            io<<" ";
        }
        io<<"[n]\n";
    }
    }else{
        std::cout<<"fail"<<std::endl;
    }

    io.close();
}
