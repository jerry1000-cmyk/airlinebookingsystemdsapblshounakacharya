// Airline ticket booking using a queue
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Passenger {
public:
    int id;
    string name;
};

class TicketSystem {
public:
    int total = 5;
    int available = 5;
    int nextId = 1;
    queue<Passenger> q;

    void showTickets() {
        cout << "Total tickets: " << total << endl;
        cout << "Available tickets: " << available << endl;
    }

    void joinQueue(string name) {
        if (available == 0) {
            cout << "No tickets available. Booking rejected." << endl;
            return;
        }
        Passenger p;
        p.id = nextId;
        p.name = name;
        nextId++;
        q.push(p);
        cout << name << " joined the queue (token " << p.id << ")" << endl;
    }

    void serveNext() {
        if (q.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Passenger p = q.front();
        q.pop();

        // tickets may have run out while this person was waiting
        if (available == 0) {
            cout << "No tickets available. Booking rejected for " << p.name << endl;
            return;
        }
        available--;
        cout << "Ticket booked for " << p.name << " (token " << p.id << ")" << endl;
    }

    void showQueue() {
        if (q.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "People in queue: " << q.size() << endl;
        // queue can't be looped over, so print a copy
        queue<Passenger> temp = q;
        int pos = 1;
        while (!temp.empty()) {
            Passenger p = temp.front();
            temp.pop();
            cout << pos << ". " << p.name << " (token " << p.id << ")" << endl;
            pos++;
        }
    }
};

int main() {
    TicketSystem system;
    int choice;

    do {
        cout << endl;
        cout << "1. Show ticket count" << endl;
        cout << "2. Join booking queue" << endl;
        cout << "3. Show queue" << endl;
        cout << "4. Serve next person" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            choice = -1;
        }
        cin.ignore(1000, '\n');
        cout << endl;

        if (choice == 1) {
            system.showTickets();
        } else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            getline(cin, name);
            system.joinQueue(name);
        } else if (choice == 3) {
            system.showQueue();
        } else if (choice == 4) {
            system.serveNext();
        } else if (choice == 0) {
            cout << "Bye" << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}