#include <qfile.h>
#include <iostream>

int main(int argc, char* argv[]){
    qfile file;
    file.init("src/database.bdb");
    std::cout<<"id | ";
    for(data::iterator it = file.getData()->begin(); it != file.getData()->end(); it++){
        std::cout<<it->id<<" | ";
    }
    std::cout<<std::endl;
    for(unsigned int j = 0; j < file.dsLength(); j++){
        std::cout<<j+1<<" ";
        for(unsigned int i = 0; i < file.getData()->size(); i++){
            std::cout<<(*file.getData())[i].dataSet[j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}
