//
// Created by Owen Powell on 12/4/18.
//

#ifndef PROJECT3_DEBUGGER_H
#define PROJECT3_DEBUGGER_H

#include <iostream>
#include <fstream>
#include <chrono>

class Debugger{
private:
    typedef std::chrono::high_resolution_clock Clock;
    Clock::time_point epoch;

    int count;

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
    std::string countToString(){
        return "the loop ran " + std::to_string(this->getLoopCount()) + " times";                                   //function that returns how many times the loop ran
    }

    int outputInfo() {                                                                                              //function to output debug info
        std::ofstream outputStream;                                                                                 //debug info output file stream
        outputStream.open("debugInfo.txt");                                                                         //open file to write data to
        outputStream << "The loop ran " << this->count << " times " << std::endl;                                   //writing info to file
        auto elapsed = time_elapsed();                                                                              //give the "elapsed" variable a value
        outputStream << "The program ran in " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << " nanoseconds" << std::endl;
        outputStream.close();                                                                                       //close file
    }

};


#endif //PROJECT3_DEBUGGER_H
