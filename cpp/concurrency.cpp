// Concurrency in C++: threads, mutex, future
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>

std::mutex mtx;
int counter = 0;

void worker(int id) {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
    std::cout << "worker " << id << " done\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) threads.emplace_back(worker, i);
    for (auto &t : threads) t.join();
    std::cout << "counter = " << counter << "\n";

    // async future
    auto fut = std::async(std::launch::async, []{ return 42; });
    std::cout << "future result = " << fut.get() << "\n";
    return 0;
}
