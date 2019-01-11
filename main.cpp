#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

class Debugger {                                                                                                        //debugger class
    private:
        typedef chrono::high_resolution_clock Clock;
        Clock::time_point epoch;

        int count;                                                                                                      //counter variable to track how many times a loop has run

    public:
        Debugger(){
            epoch = Clock::now();                                                                                       //sets epoch to current time
        }
        Clock::duration time_elapsed() { return Clock::now() - epoch; }                                                 //returns time elapsed since program began running

        void countLoop(int count){                                                                                      //function setting the count variable equal to its input from the main function
            this->count = count;
        }
        int getLoopCount () {                                                                                           //function to return the value of the count variable, which is the number of times a loop runs
            return this->count;
        }
        string countToString(){
           return "the loop ran " + to_string(this->getLoopCount()) + " times";                                         //function that returns how many times the loop ran
        }

        int outputInfo() {                                                                                              //function to output debug info
           ofstream outputStream;                                                                                       //debug info output file stream
          outputStream.open("debugInfo.txt");                                                                           //open file to write data to
          outputStream << "The loop ran " << this->count << " times " << endl;                                          //writing info to file
          auto elapsed = time_elapsed();                                                                                //give the "elapsed" variable a value
          outputStream << "The program ran in " << chrono::duration_cast<chrono::nanoseconds>(elapsed).count() << " nanoseconds" << endl;
          outputStream.close();                                                                                         //close file
        }
};

int main() {                                                                                                            //main function for testing
    Debugger debugger;

    auto elapsed = debugger.time_elapsed();                                                                             //set elapsed variable to the elapsed time from the clock function
    cout << "program ran in " << chrono::duration_cast<chrono::nanoseconds>(elapsed).count() << "ns" << endl;           //output total program run time

    int count = 0;                                                                                                      //initializes count variable to 0
    for(int i = 0; i < 10; i++) {                                                                                       //test loop
        count++;                                                                                                        //increment count variable
        debugger.countLoop(count);                                                                                      //call countLoop function to begin tracking loop
    }

    cout << debugger.countToString() << endl;                                                                           //output the number of times the loop ran from the toString converter function

    debugger.outputInfo();                                                                                              //runs outputInfo function which writes above information to debugInfo.txt

    return 0;
}
