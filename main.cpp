#include <writer.h>

int main(int argc, char* argv[]){
    qfile file;
    file.init("src/database.bdb");
    summary(&file);
    file.save("src/database.bdb");
    return 0;
}
