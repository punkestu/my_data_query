#include <writer.h>

int main(int argc, char* argv[]){
    qfile file;
    file.init("src/database.bdb");
    //bque::summary(&file);
    std::cout<<bque::get(&file, 1, "nama")<<std::endl;
    file.save("src/database.bdb");
    return 0;
}
