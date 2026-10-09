#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

int main() {
    std::cout << "Terminal with ID " << getppid() << " created Procces_1 with ID " << getpid() << "\n";
    std::cout << " Procces_1 PID: " << getpid() << "\n";
    std::cout << " Procces_1 PPID: " << getppid() << "\n\n";

    pid_t pid = fork();
   
    if (pid == 0) {
        std::cout << "  Procces_1 with ID " << getppid() << " created Procces_2 with ID " << getpid() << "\n";
        std::cout << "   Procces_2 PID: " << getpid() << "\n";
        std::cout << "   Procces_2 PPID: " << getppid() << "\n\n";

        pid_t p3 = fork();
        
        if (p3 == 0) {
            std::cout << "      Procces_2 with ID " << getppid() << " created Procces_3 with ID " << getpid() << "\n";
            std::cout << "       Procces_3 PID: " << getpid() << "\n";
            std::cout << "       Procces_3 PPID: " << getppid() << "\n\n";

            pid_t p5 = fork();
            if (p5 == 0) {
                std::cout << "          Procces_3 with ID " << getppid() << " created Procces_5 with ID " << getpid() << "\n";
                std::cout << "           Procces_5 PID: " << getpid() << "\n";
                std::cout << "           Procces_5 PPID: " << getppid() << "\n\n";

                std::cout << "           Procces_5 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
                _exit(0);
            }
            else {
                wait(nullptr);
                std::cout << "          Procces_3 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
                _exit(0);
            }
        }
        else {
            pid_t p4 = fork();
        
            if (p4 == 0) {
                std::cout << "      Procces_2 with ID " << getppid() << " created Procces_4 with ID " << getpid() << "\n";
                std::cout << "       Procces_4 PID: " << getpid() << "\n";
                std::cout << "       Procces_4 PPID: " << getppid() << "\n\n";

                pid_t p6 = fork();
                
                if (p6 == 0) {
                    std::cout << "          Procces_4 with ID " << getppid() << " created Procces_6 with ID " << getpid() << "\n";
                    std::cout << "           Procces_6 PID: " << getpid() << "\n";
                    std::cout << "           Procces_6 PPID: " << getppid() << "\n\n";

                    pid_t p7 = fork();
    
                    if (p7 == 0) {
                        std::cout << "              Procces_6 with ID " << getppid() << " created Procces_7 with ID " << getpid() << "\n";
                        std::cout << "               Procces_7 PID: " << getpid() << "\n";
                        std::cout << "               Procces_7 PPID: " << getppid() << "\n";
                        std::cout << "               Whoami started: \n";
                        execlp("whoami", "whoami", nullptr);
                    }
                    else {
                        wait(nullptr);
                        std::cout << "              Procces_6 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
                        _exit(0);
                    }
                }
                else {
                    wait(nullptr);
                    std::cout << "          Procces_4 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
                    _exit(0);
                }
            }
            else {
                wait(nullptr);
                wait(nullptr);
                std::cout << "      Procces_2 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
                _exit(0);
            }
        }
    }
    else {
        wait(nullptr);
        std::cout << "  Procces_1 with ID: " << getpid() << " and parent ID: " << getppid() << " finished\n\n";
    }

    return 0;
}