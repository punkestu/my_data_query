#include <writer.h>

int main(int argc, char* argv[]){
    qfile file;
    //bque::summary(&file);
    //file.init("src/database.bdb");
    file.tread("src/database.bin");
    file.save("src/database.bin");
    return 0;
}
