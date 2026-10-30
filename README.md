# Airline Ticket Booking System

A menu-driven airline ticket booking system written in C++ to demonstrate the **queue** data structure. Passengers join a queue and are served in first-come, first-served order. Once the tickets run out, every booking attempt is rejected.

This is a DSA demonstration project, so the code is kept simple and uses the C++ STL `queue` instead of a hand-written one.

## Features

- Keeps count of total tickets and available tickets
- Passengers can join a booking queue and get a token number
- Queue status can be displayed at any time
- Booking is rejected when no tickets are available
- Menu driven: the user picks an option by entering a number

The total number of tickets is fixed at 5 in the code and is not asked from the user.

## How to run

You need a C++ compiler such as g++.

```
g++ airline_booking.cpp -o airline_booking
./airline_booking
```

On Windows, run `airline_booking.exe` instead of `./airline_booking`.

## Menu

```
1. Show ticket count
2. Join booking queue
3. Show queue
4. Serve next person
0. Exit
```

| Option | What it does |
|--------|--------------|
| 1 | Prints the total and available tickets |
| 2 | Asks for a name and adds the person to the queue. Rejected if no tickets are available |
| 3 | Prints everyone waiting in the queue, in order |
| 4 | Takes the person at the front of the queue and books a ticket for them |
| 0 | Exits the program |

## How it works

Joining the queue does not use up a ticket. It only gives the person a token number and a place in line. A ticket is used only when the person at the front is served (option 4).

Ticket availability is checked in two places:

1. When someone tries to join the queue. If there are no tickets left, they cannot join.
2. When someone is served. Tickets may have run out while they were waiting, so the check is done again and the booking is rejected if needed.

## Sample run

```
Enter choice: 2
Enter name: Asha
Asha joined the queue (token 1)

Enter choice: 3
People in queue: 1
1. Asha (token 1)

Enter choice: 4
Ticket booked for Asha (token 1)

Enter choice: 1
Total tickets: 5
Available tickets: 4
```

When all 5 tickets are booked:

```
Enter choice: 2
Enter name: Ravi
No tickets available. Booking rejected.
```

## Code structure

- `Passenger` class: stores a token number (`id`) and `name`
- `TicketSystem` class: stores the ticket counts and the queue, and has these functions:
  - `showTickets()`
  - `joinQueue()`
  - `serveNext()`
  - `showQueue()`
- `main()`: shows the menu in a loop and calls the matching function

`std::queue` cannot be looped over, so `showQueue()` prints from a copy of the queue. The original queue is not changed.

## Time complexity

| Operation | Time |
|-----------|------|
| Join queue | O(1) |
| Serve next | O(1) |
| Show ticket count | O(1) |
| Show queue | O(n) |

## Changing the number of tickets

In the `TicketSystem` class, change both `total` and `available` to the same new value:

```cpp
int total = 5;
int available = 5;
```

## Future ideas

- Ticket cancellation
- Priority booking using a priority queue
- Seat numbers and multiple flights
- Saving bookings to a file
