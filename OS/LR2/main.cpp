#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <chrono>
#include <vector>
#include <queue>
#include <deque>

const int CHAIRS = 3;
const int TOTAL_CLIENTS = 10;

std::mutex mtx;
int waiting = 0;
bool stop = false;
bool barberSleeping = true;

std::queue<int> waitingQueue;
std::deque<std::binary_semaphore> clientSem;
std::counting_semaphore<CHAIRS> clients(0);

void barber(){
    std::cout << "Barber is sleeping\n";
    while (true){
        clients.acquire();

        int nextClient = -1;
        {
            std::lock_guard<std::mutex> lk(mtx);
            if (stop && waiting == 0) break;
            barberSleeping = false;
            if (!waitingQueue.empty()) {
                nextClient = waitingQueue.front();
                waitingQueue.pop();
                waiting--;
            }
        }

        if (nextClient == -1) continue;

        std::cout << "Barber cutting hair (client " << nextClient << ")\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Barber haircut finished (client " << nextClient << ")\n";

        clientSem[nextClient].release();

        {
            std::lock_guard<std::mutex> lk(mtx);
            if (waiting == 0) {
                barberSleeping = true;
                std::cout << "Barber is sleeping\n";
            }
            if (stop && waiting == 0) break;
        }
    }
}

void client(int id){
    std::cout << "Client " << id << " arrived\n";
    std::unique_lock<std::mutex> lk(mtx);

    if (barberSleeping) {
        barberSleeping = false;
        waitingQueue.push(id);
        waiting++;
        std::cout << "Client " << id << " wakes up barber\n";
        lk.unlock();
        clients.release();
        clientSem[id].acquire();
    }
    else {
        if (waiting < CHAIRS) {
            waitingQueue.push(id);
            waiting++;
            std::cout << "Client " << id << " sits in waiting room (" << waiting << "/" << CHAIRS << ")\n";
            lk.unlock();
            clients.release();
            clientSem[id].acquire();
        }
        else {
            lk.unlock();
            std::cout << "Client " << id << " no chairs, leaves\n";
        }
    }
}

int main(){
    for (int i = 0; i <= TOTAL_CLIENTS; ++i) {
        clientSem.emplace_back(0);
    }

    std::thread barberThread(barber);
    std::vector<std::thread> clientsThreads;

    for(int i = 1; i <= TOTAL_CLIENTS; ++i){
        clientsThreads.emplace_back(client, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    for(auto& t : clientsThreads) t.join();

    {
        std::lock_guard<std::mutex> lk(mtx);
        stop = true;
    }
    clients.release();

    barberThread.join();
    return 0;
}