#include "fs.h"
#include <string>

int main(){
    init_fs();
    std::string cmd;
    while(true){
        std::cout << "> ";
        std::cin >> cmd;

        if(cmd == "exit") break;
        else if(cmd == "create"){
            std::string name;
            std::cin >> name;
            create_file(name.c_str());
        }
        else if(cmd == "write"){
            std::string name, data;
            std::cin >> name;
            std::cin.ignore();
            std::getline(std::cin, data);
            write_to_file(name.c_str(), data.c_str());
        }
        else if(cmd == "read"){
            std::string name;
            std::cin >> name;
            read_file(name.c_str());
        }
        else if(cmd == "delete"){
            std::string name;
            std::cin >> name;
            delete_file(name.c_str());
        }
        else if(cmd == "copy"){
            std::string a, b;
            std::cin >> a >> b;
            copy_file(a.c_str(), b.c_str());
        }
        else if(cmd == "move"){
            std::string a, b;
            std::cin >> a >> b;
            move_file(a.c_str(), b.c_str());
        }
        else if(cmd == "dump"){
            dump_fs();
        }
        else {
            std::cout << "Unknown command\n";
        }
    }
}