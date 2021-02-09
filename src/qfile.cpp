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
    io.open(fileP.c_str(), std::ios_base::in|std::ios_base::binary);
    if(!io.fail()){
        std::cout<<fileP<<" inited"<<std::endl;
        unsigned int line = 0;
        unsigned int dataN = 0;
        while(!io.eof()){
            if(io.peek()!=std::ifstream::traits_type::eof()){
                std::string temp;
                io>>temp;
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

void qfile::tread(std::string fileP){
    io.open(fileP.c_str(), std::ios_base::in);

    int csize;
    io.read(reinterpret_cast<char*>(&csize), sizeof(int));
    container.resize(csize);
    std::cout<<container.size()<<std::endl;
    std::string cdata;
    int strsz;
    io.read(reinterpret_cast<char*>(&strsz), sizeof(int));
    io.read(reinterpret_cast<char*>(&cdata), strsz*sizeof(dataG));
    container[0].id = cdata;
    std::cout<<container[0].id<<std::endl;

    io.close();
}

void qfile::save(std::string fileN){
    //if(!container.empty()){
    io.open(fileN.c_str(), std::ios_base::out|std::ios_base::binary);
    if(!io.fail()){
        if(!container.empty()){
            int csize = container.size();            io.write(reinterpret_cast<char*>(&csize), sizeof(int));
            for(int i = 0; i < csize; i++){
                std::string id = container[i].id;
                int idsize = id.size();
                io.write(reinterpret_cast<char*>(&idsize), sizeof(int));
                io.write(reinterpret_cast<char*>(&id), container[i].id.size()*sizeof(std::string));
            }
//            for(unsigned int i = 0; i < container.size(); i++){
//                io<<container[i].id;
//                io<<" ";
//            }
//            io<<"[n]\n";
//            for(unsigned int i = 0; i < container.size(); i++){
//                for(unsigned int j = 0; j < container[i].dataSet.size(); j++){
//                    io<<container[i].dataSet[j];
//                    io<<" ";
//                }
//                io<<"[n]\n";
//            }
        }else{
            std::cout<<"nothing"<<std::endl;
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
