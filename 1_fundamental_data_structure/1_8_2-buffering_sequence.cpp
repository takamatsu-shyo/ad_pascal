#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

constexpr int N = 1024;

class CircularBuffer{
private:
    int n = 0, in = 0, out = 0;
    char buf[N];
    std::mutex mtx;
    std::condition_variable_any cv_empty, cv_full;

public:
    void deposit(char x){
        std::unique_lock<std::mutex> lock(mtx);
        cv_full.wait(lock, [this]() { return n < N; });
        n++;
        buf[in] = x;
        in = (in + 1) % N;
        cv_empty.notify_one();
    }

    char fetch(){
        std::unique_lock<std::mutex> lock(mtx);
        cv_empty.wait(lock, [this]() { return n > 0; });
        n--;
        char x = buf[out];
        out = (out + 1) % N;
        cv_full.notify_one();
        return x;
    }
};

int main(){
    CircularBuffer buffer;
    std::jthread deposit_thread([&buffer](){
        for (char c = 'a'; c <= 'z'; ++c){
            buffer.deposit(c);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::jthread fetch_thread([&buffer](){
        for (int i = 0; i < 26; ++i) {
            char fetched = buffer.fetch();
            std::cout << "Fetched char:" << fetched << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });

    return 0;
}
