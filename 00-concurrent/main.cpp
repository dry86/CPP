//
//  main.cpp
//  00-concurrent
//
//  Created by dry on 2023/4/3.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace::std;

static mutex exclusive;

void worker(int number) {
//    this_thread::sleep_for(chrono::seconds(number));
    cout << "worker:" << number << endl;
}

mutex sCoutLock;

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    thread t([]{
//        cout << "Hello world" << endl;
//    });
//
//    t.join();
  
    
    vector<thread> threads;

    unsigned concurrent_count = thread::hardware_concurrency();
    cout << "hardware_concurrency: " << concurrent_count << endl;

    for (int t = 0; t < concurrent_count; t++) {

      threads.push_back(thread(worker, t));

    }
    
    for (int i = 0; i < threads.size(); i++) {

      threads[i].join();
//      threads[i].detach();
        sCoutLock.lock();
        cout << "--- " << i << endl;
        sCoutLock.unlock();
//        printf("--- %d\n", i);
    }
    
    cout << "thread worker work over" << endl;
    
    return 0;
}
