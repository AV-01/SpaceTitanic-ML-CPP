#include "passengers.hpp"
#include <limits>

Passenger processPassenger(const vector<string>& row, bool has_label){
    string homePlanet = row[1];

    // collect cryoSleep as a string, turn into int later
    string cryoSleep = row[2];

    // split cabin by slashes to get deck, cabin_num, and side
    const string& cabin = row[3];
    const size_t firstSlash = cabin.find('/');
    const size_t secondSlash = firstSlash == string::npos
        ? string::npos : cabin.find('/', firstSlash + 1);
    string deck = cabin.substr(0, firstSlash);
    string cabin_num = firstSlash == string::npos ? ""
        : cabin.substr(firstSlash + 1, secondSlash == string::npos
            ? string::npos : secondSlash - firstSlash - 1);
    string side = secondSlash == string::npos ? "" : cabin.substr(secondSlash + 1);

    string destination = row[4];

    // hard code default as 30, since that's like the average
    float age = row[5].empty() ? 30 : stof(row[5]);

    string VIP = row[6];

    // easy parsing for the rest of the values, just convert to float
    float roomService = stof(row[7].empty() ? "0" : row[7]);
    float foodCourt = stof(row[8].empty() ? "0" : row[8]);
    float shoppingMall = stof(row[9].empty() ? "0" : row[9]);
    float spa = stof(row[10].empty() ? "0" : row[10]);
    float VRDeck = stof(row[11].empty() ? "0" : row[11]);
    
    string transported;
    if (has_label) {
        transported = row[13];
    } else {
        transported = "False";
    }
    float totalSpent = roomService + foodCourt + shoppingMall + spa + VRDeck;

    Passenger to_return;

    to_return.homePlanet = homePlanet;
    if (cryoSleep == "True") {
        to_return.cryoSleep = 1;
    } else if (cryoSleep == "False") {
        to_return.cryoSleep = 0;
    } else if (totalSpent == 0) {
        // this is a null value, we can assume that since this guy spend 0 money, he was prob in cryoSleep
        to_return.cryoSleep = 1;
    } else {
        // if they spent money, they were prob awake and not in cryosleep
        to_return.cryoSleep = 0;
    }
    to_return.deck = deck;
    to_return.cabin_num = stoi(cabin_num.empty() ? 0 : cabin_num);
    to_return.side = side;
    to_return.destination = destination;
    to_return.age = age;
    // simple ternary to deal with the VIP string to int conversion
    to_return.VIP = VIP == "True" ? 1 : 0;
    to_return.roomService = roomService;
    to_return.foodCourt = foodCourt;
    to_return.shoppingMall = shoppingMall;
    to_return.spa = spa;
    to_return.VRDeck = VRDeck;
    to_return.transported = (transported == "True") ? 1 : 0;
    to_return.totalSpent = totalSpent;
    to_return.has_label = has_label;
    return to_return;
}
