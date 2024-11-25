// Thread Management
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) cv.wait(lck);
    // ...
    std::cout << "Thread " << id << " is running" << std::endl;
    lck.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ready = false;
    cv.notify_one();
    std::cout << "Thread " << id << " is finished" << std::endl;
    // ...
    // Perform necessary cleanup
    
}