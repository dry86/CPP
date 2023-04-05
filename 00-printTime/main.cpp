//
//  main.cpp
//  00-printTime
//
//  Created by dry on 2023/4/3.
//

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

using namespace std;

void print_time() {
  auto now = chrono::system_clock::now();
  auto in_time_t = chrono::system_clock::to_time_t(now);

  stringstream ss;
  ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
  cout << "now is: " << ss.str() << endl;   // now is: 2023-04-03 21:35:36
}


int main(int argc, const char * argv[]) {
    // insert code here...
    auto start_time = chrono::steady_clock::now();
    print_time();
    auto end_time = chrono::steady_clock::now();
    
    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    cout << "Concurrent task finish, " << ms << "ms consumed." << endl;
    
    return 0;
}
