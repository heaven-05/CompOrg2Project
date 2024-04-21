#include <chrono>
#include <cmath>
#include <iostream>
using namespace std;
using namespace std::chrono;

//create array size var for file
#define ARRAY_SIZE 1000000000

//benchmark for reading and writing to arrays
void MemoryBenchmark(){

    //create array
    int *nums = new int[ARRAY_SIZE];
    int num, i, j;

    //build array 5x10^9 times
    for(i = 0; i < 5; i++){
        for(j = 0; j < ARRAY_SIZE; j++){
            num = *(nums + j);
        }
    }
  
    for(i = 0; i < 5; i++){
        for(j = 0; j < ARRAY_SIZE; j++){
            *(nums + j) = 1;
        }
    }

    //clear nums variable
    delete [] nums;
}

//execute function
int main(){

  //start clock
    auto start = high_resolution_clock::now();

  //run benchmark
    MemoryBenchmark();

  //stop clock
    auto stop = high_resolution_clock::now();

  //store time in variable
    auto runTime_0 = duration_cast<milliseconds>(stop-start);

  //convert seconds to ms
    double seconds = runTime_0.count() / 1000.0;
    int minutes = seconds / 60;

  //print time
    cout << minutes << " m " << std::fmod(seconds, 60) << " s\n";
}
