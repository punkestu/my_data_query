#include "qfile.h"

void qfile::create(std::string fileN, bool force){
    bool exist = false;
    io.open(fileN.c_str(), std::ios_base::in);
    if(!io.fail()){
        exist = true;
        if(!force){
            std::cout<<"i*file existed, add [force] parameter to overwrite the existed file"<<std::endl;
        }
    }
    io.close();
    if(!exist){
        io.open(fileN.c_str(), std::ios_base::out);
        io.close();
        std::cout<<"i*file created"<<std::endl;
    }else{
        if(force){
            io.open(fileN.c_str(), std::ios_base::out);
            io.close();
            std::cout<<"i*existed file was overwrited, new file created"<<std::endl;
        }
    }
}

void qfile::init(std::string fileP){
    io.open(fileP.c_str(), std::ios_base::in);
    if(!io.fail()){
        std::cout<<fileP<<" inited"<<std::endl;
        unsigned int line = 0;
        unsigned int dataN = 0;
        while(!io.eof()){
            std::string temp;
            io>>temp;
            if(io.peek()!=std::ifstream::traits_type::eof()){
                if(temp == "[n]"){
                    line++;
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
            }else{
                if(dataN == 0){
                    std::cout<<"i*empty query is opened"<<std::endl;
                    break;
                }
            }
        }
    }else{
        std::cout<<"i*fail to open file"<<std::endl;
    }

    io.close();
}

void qfile::save(std::string fileN){
    //if(!container.empty()){
    io.open(fileN.c_str(), std::ios_base::out);
    if(!io.fail()){
        if(!container.empty()){
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
            io<<" ";
        }
    }else{
        std::cout<<"i*fail to open file"<<std::endl;
    }

    io.close();
//    }else{
//        std::cout<<"i*nothing to save / no change"<<std::endl;
//    }
}

void qfile::clear(){
    if(!container.empty()){
        container.clear();
        std::cout<<"i*clear"<<std::endl;
    }else{
        std::cout<<"i*nothing to clear"<<std::endl;
    }
}
