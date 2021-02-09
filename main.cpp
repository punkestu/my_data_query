#include <writer.h>

int main(int argc, char* argv[]){
    qfile file;
    file.tread("src/database.bin");
    file.save("src/database.bin");
    return 0;
}
