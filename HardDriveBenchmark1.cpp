#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

//benchmark function testing read + write functionality for 100 bytes
void HardDriveBenchmark1(char * txt){
    fstream file;

    //open file
    file.open("file.txt", ios::out | ios::app | ios::binary);

    //make loop variable for iteration
    int loop = pow(10, 9);

    //write to the file
    for(int i = 0; i < loop; i++){
        file.write(txt, 100);
    }

    file.seekg(0);

    //read the file
    for(int i = 0; i < loop; i++){
        file.read(txt, 100);
    }

    //close file
    file.close();
}

//execute function
int main(){

    //100 bytes
    char text[100];
    for(int i = 0; i < 100; i++){
        text[i] = 'a';
    }

    //start clock
    auto start = high_resolution_clock::now();

    //run benchmark
    HardDriveBenchmark1(text);

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
