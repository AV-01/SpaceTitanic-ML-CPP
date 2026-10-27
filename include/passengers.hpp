#ifndef PASSENGERS_HPP
#define PASSENGERS_HPP

#include <string>
#include <vector>
using namespace std;

// holds data in the format it would look post processing
struct Passenger {
    string homePlanet;
    int cryoSleep;
    string deck;
    string cabin_num;
    string side;
    string destination;
    float age;
    int VIP;
    float roomService;
    float foodCourt;
    float shoppingMall;
    float spa;
    float VRDeck;
    float totalSpent;

    // won't exist for the test dataset, figure out how to deal with that later
    int transported;
};

Passenger processPassenger(const vector<string>& row);

#endif // PASSENGERS_HPP