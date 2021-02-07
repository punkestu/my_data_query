#include <writer.h>

int main(int argc, char* argv[]){
    qfile file;
    file.init("src/database.bdb");
    add(&file, 1, "nama", "bima");
    summary(&file);
    //addSet(&file, 2, "alamat");
    //std::cout<<file.getData()->at(0).dataSet[0]<<std::endl;
    file.save("src/database.bdb");
    return 0;
}
//    std::cout<<file.getData()->size()<<std::endl;
//    std::cout<<"id";
//    for(unsigned int i = 0; i < std::to_string(file.dsLength()).size()-2; i++){
//        std::cout<<" ";
//    }
//    std::cout<<" | ";
//    for(data::iterator it = file.getData()->begin(); it != file.getData()->end(); it++){
//        std::cout<<it->id;
//        for(unsigned int i = 0; i < ( it->longest-it->id.size()); i++){
//            std::cout<<" ";
//        }
//        std::cout<<" | ";
//    }
//    std::cout<<std::endl;
//    for(unsigned int i = 0; i < std::to_string(file.dsLength()).size(); i++){
//        std::cout<<"-";
//    }
//    std::cout<<"-+-";
//    for(data::iterator it = file.getData()->begin(); it != file.getData()->end(); it++){
//        for(unsigned int i = 0; i < it->longest; i++){
//            std::cout<<"-";
//        }
//        std::cout<<"-+-";
//    }
//    std::cout<<std::endl;
//    for(unsigned int j = 0; j < file.dsLength(); j++){
//        std::cout<<j+1;
//        for(unsigned int i = 0; i < std::to_string(file.dsLength()).size()-std::to_string(j+1).size(); i++){
//            std::cout<<" ";
//        }
//        std::cout<<" | ";
//        for(unsigned int i = 0; i < file.getData()->size(); i++){
//            std::cout<<(*file.getData())[i].dataSet[j];
//            for(unsigned int k = 0; k < ((*file.getData())[i].longest-(*file.getData())[i].dataSet[j].size()); k++){
//                std::cout<<" ";
//            }
//            std::cout<<" | ";
//        }
//        std::cout<<std::endl;
//    }
//    std::cout<<std::endl;
