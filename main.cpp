// COMSC-210 | Lab 24 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> trip;

    int choice = main_menu();
    while (choice != 4) {
        if (choice == 1) {
            add_goat(trip, names, colors);
        } else if (choice == 2) {
            delete_goat(trip);
        } else if (choice == 3) {
            display_trip(trip);
        }

        choice = main_menu();
    }

    return 0;
}

//Displays the main menu options and asks for user input
int main_menu() {
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Choice must be within 1-4" << endl;
        cout << "Choice --> ";
        cin >> choice;
    }
    cout << endl;

    return choice;
}

//Selects a specific goat from the trip
int select_goat(set<Goat> trip) {
    display_trip(trip);
    int choice;
    cout << "Select a goat: ";
    cin >> choice;

    return choice;
}

//Deletes a goat selected by user
void delete_goat(set<Goat> &trip) {
    int choice = select_goat(trip);
    int count = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it) {
        if (count == choice) { 
            trip.erase(it);
            return;
        }
        count++;
    }
    cout << endl;
}

//Adds goat with random elements
void add_goat(set<Goat> &trip, string n[] , string c[]) {
    int randNum = rand() % SZ_NAMES;
    string name =  n[randNum];
    randNum = rand() % SZ_COLORS;
    string color = c[randNum];
    randNum = rand() % (MAX_AGE + 1);
    int age = randNum;

    trip.insert(Goat(name, age, color));
}

//Displays the goats
void display_trip(set<Goat> trip) {
    int count = 0;
    for (Goat g : trip) {
        count++;
        cout << "[" << count << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl; 
    }
    cout << endl;
}