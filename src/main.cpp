#include <iostream>
#include <vector>
#include "csv_parser.hpp"
#include "passengers.hpp"
using namespace std;

int main() {
    // data loading
    CSVParser train, test;
    train.parse("data/train.csv");
    test.parse("data/test.csv");

    vector<Passenger> processed_train(train.data.size() - 1);
    cout << train.data[51][5] << endl;
    for (size_t i = 1; i < train.data.size(); i++) {
        const vector<string>& row = train.data[i];
        Passenger p = processPassenger(row);
        processed_train[i - 1] = p;
    }

    int index = 0;
    for (Passenger& p : processed_train) {
        cout << "Passenger " << index << ": " << p.homePlanet << ", " << p.cryoSleep << ", " << p.deck << ", " << p.cabin_num << ", " << p.side << ", " << p.destination << ", " << p.age << ", " << p.VIP << ", " << p.roomService << ", " << p.foodCourt << ", " << p.shoppingMall << ", " << p.spa << ", " << p.VRDeck << ", " << p.transported << ", " << p.totalSpent << endl;
        index++;
    }

    return 0;
}
