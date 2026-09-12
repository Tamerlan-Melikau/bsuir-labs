#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <chrono>
#include <vector>

const int CHAIRS = 4;
const int TOTAL_CLIENTS = 10;

std::mutex mtx;
int waiting = 0;
bool stop = false;

std::counting_semaphore<CHAIRS> clients(0);
std::binary_semaphore barberReady(0);

void barber(){
    std::cout << "Barber is sleeping\n";
    while (true){
        clients.acquire();

        std::unique_lock<std::mutex> lk(mtx);
        if (stop && waiting == 0){
            lk.unlock();
            break;
        }
        if(waiting > 0){
            waiting--;
        }
        lk.unlock();
        std::cout << "Barber cutting hair\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Barber haircut finished\n";
        barberReady.release();
    }
}

void client(int id){
    std::cout << "Client " << id << " arrived\n";
    std::unique_lock<std::mutex> lk(mtx);
    if(waiting < CHAIRS){
        waiting++;
        std::cout << "Client " << id << " sits ("<< waiting << "/" << CHAIRS << ")\n";
        lk.unlock();
        clients.release();
        barberReady.acquire();
        std::cout << "Client " << id << " being haircut\n";
    }else{
        lk.unlock();
        std::cout << "Client " << id << " no chairs, leaves\n";
    }
}

int main(){
    std::thread barberThread(barber);
    std::vector<std::thread> clientsThreads;

    for(int i = 0; i < TOTAL_CLIENTS; ++i){
        clientsThreads.emplace_back(client, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    for(auto& t : clientsThreads){
        t.join();
    }
    {
        std::lock_guard<std::mutex> lk(mtx);
        stop = true;
    }
    clients.release();

    barberThread.join();
    return 0;
}