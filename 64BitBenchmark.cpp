#include <chrono>
#include <cmath>
#include <iostream>
using namespace std;
using namespace std::chrono;

//benchmark function doing float arithmetic 
void FloatBenchmark(){

    //create result variable
    int result;

    //10^10 additions
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < pow(10,10); j++){
            result = 1.0 + 1.0;
        }
    }


  //5 x 10^9 multipactions
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < pow(10,9); j++){
            result = 1.0 * 1.0;
        }
    }

    //2 x 10^9 divisions
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < pow(10,9); j++){
            result = 1.0 / 1.0;
        }
    }          
}

//execute function
int main(){

    //start clock to time benchmark
    auto start = high_resolution_clock::now();

    //run benchmark
    FloatBenchmark();

    //stop clock
    auto stop = high_resolution_clock::now();

    //store time in variable
    auto runTime = duration_cast<milliseconds>(stop-start);

    //convert time to ms
    double seconds = runTime.count() / 1000.0;
    int minutes = seconds / 60;

    //print time
    cout << minutes << " m " << std::fmod(seconds, 60) << " s\n";

}
