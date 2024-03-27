// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 10A
// Create a new program time.cpp. 
// (Copy the class Time declaration in your program, it should be placed before main() function.)

#include <iostream>
#include <string>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

Time addMinutes(Time time0, int min){
    Time time = time0;
    int minutes = min;
    while (minutes >= 60) {
        // If minutes is 60 or more, we need to adjust the time
        time.h += 1;    // Increment the hour by 1
        minutes -= 60;  // Subtract 60 minutes from the total
    }

        // Adding the remaining minutes to the current time
    time.m += minutes;

    // If minutes exceed 60, adjust hours accordingly
    if (time.m >= 60) {
        time.h += 1;    // Increment the hour by 1
        time.m -= 60;   // Subtract 60 minutes
    }
    cout << ", ends by " << time.h << ":" << time.m << " ]" << endl;
    return time;

}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    TimeSlot timeslot = ts;

    printMovie(timeslot.movie);
    cout << " [ starts at "<<timeslot.startTime.h << ":" <<  timeslot.startTime.m ;
    addMinutes({ts.startTime.h, ts.startTime.m}, ts.movie.duration);

}

int main(){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot evening2 = {movie2, {19, 15}};
    TimeSlot night = {movie1, {21, 35}};

    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(evening2);
    printTimeSlot(night);

        
    return 0; 


}