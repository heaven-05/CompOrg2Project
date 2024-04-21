#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;

//benchmark function testing read + write functionality for 10000 bytes
void HardDriveBenchmark2(char * txt){
    fstream file;
  
    //open file
    file.open("file.txt", ios::out | ios::app | ios::binary);
    
    //make loop variable for iteration
    int loop = pow(10, 9);

    //write to the file
    for(int i = 0; i < loop; i++){
        file.write(txt, 10000);
    }
  
    file.seekg(0);
  
    //read the file
    for(int i = 0; i < loop; i++){
        file.read(txt, 10000);
    }

   //close file
    file.close();
}

//execute function
int main(){

  //10000 bytes
    char text[10000];
    for(int i = 0; i < 10000; i++){
        text[i] = 'a';
    }

    //start clock
    auto start = high_resolution_clock::now();

    //run benchmark
    HardDriveBenchmark2(text);

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
