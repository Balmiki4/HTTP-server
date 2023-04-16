// Run in repl.it:
// g++ -pthread -std=c++17 -o call call.cpp; ./call < call_test1.in
// Run in zeus:
// g++ -pthread -o call call.cpp; ./call < call_test1.in

#include <iostream>
#include <string>
#include <cassert>

#include "dlist.h"

/*
 * Format of input line:
 *
 *  <timestamp> <Name> <status> <duration>
 *
 * Note: first four fields terminated by whitespace
 *       request terminated by newline.
 *
 * Format of input file:
 *
 * A single line with the number of requests
 * zero or more input lines followed by EOF.
 */

enum Status
{
  NONE = 0,
  SILVER = 1,
  GOLD = 2,
  PLATINUM = 3
};

struct reqNode
{
  int timestamp;
  std::string name;
  Status status;
  int duration;
};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/***************************************************
 * INSTRUCTOR NOTE: Implement the functions below. *
 **************************************************/

// EFFECTS: Reads and parses each request from the standard input stream
// std::cin. For each request, creates a reqNode struct and enqueues their
// pointers in the requests queue, which is a Dlist of pointers to reqNode
// structs.

// PSEUDOCODE:
//  function ObtainRequests(requests: Dlist<reqNode*>) {
//      // Prompt user for number of requests
//      numRequests = read_integer_from_console()

//     // Loop through each request
//     for i from 1 to numRequests {
//         // Create a new request node
//         request = create_new_reqNode()

//         // Read request details from console
//         request.timestamp = read_integer_from_console()
//         request.name = read_string_from_console()
//         status_str = read_string_from_console()

//         // Map string status to enum status
//         if status_str == "silver" then
//             request.status = SILVER
//         else if status_str == "gold" then
//             request.status = GOLD
//         else if status_str == "platinum" then
//             request.status = PLATINUM
//         else
//             request.status = NONE

//         // Read duration and add request to list
//         request.duration = read_integer_from_console()
//         requests.InsertBack(request)
//     }
// }

void ObtainRequests(Dlist<reqNode *> &requests)
{
  int numRequests;
  std::cin >> numRequests;
  for (int i = 0; i < numRequests; i++)
  {
    reqNode *request = new reqNode;
    std::cin >> request->timestamp >> request->name;
    std::string status_str;
    std::cin >> status_str;
    if (status_str == "silver")
    {
      request->status = SILVER;
    }
    else if (status_str == "gold")
    {
      request->status = GOLD;
    }
    else if (status_str == "platinum")
    {
      request->status = PLATINUM;
    }
    else
    {
      request->status = NONE;
    }
    std::cin >> request->duration;
    requests.InsertBack(request);
  }
}

// EFFECTS: Insert any callers with timestamps equal to the tick number
// (the clock param) into their appropriate queues. When a caller is
// inserted, you should print a message that exactly matches the following
// example (with the correct name and status):
//
// Call from Jeff a silver member
//
// You can get the appropriate status by calling status_names[status].
// Note: If two (or more) calls have the same timestamp, they should be
// printed in input file-order, not in priority-order.

// PSEUDOCODE:
//  function InsertRequests(requests: Dlist<reqNode*>, queues: Dlist<reqNode*>[], clock: int, status_names: string[]) {
//      // Check if there are requests waiting
//      if !requests.IsEmpty() {
//          // Handle requests with earlier timestamps
//          while true {
//              request = requests.RemoveFront()
//              if request.timestamp <= clock {
//                  print "Call from " + request.name + " a " + status_names[request.status] + " member"
//                  queues[request.status].InsertBack(request)
//                  if requests.IsEmpty() {
//                      return
//                  }
//              }
//              else {
//                  requests.InsertFront(request)
//                  break
//              }
//          }
//      }
//  }

void InsertRequests(Dlist<reqNode *> &requests, Dlist<reqNode *> queues[], int clock, std::string status_names[])
{
  // Check if there are requests waiting
  if (!requests.IsEmpty())
  {
    reqNode *request = requests.RemoveFront();
    while (request->timestamp <= clock) // Handle requests with earlier timestamps
    {
      std::cout << "Call from " << request->name << " a " << status_names[request->status] << " member\n";
      queues[request->status].InsertBack(request);
      if (requests.IsEmpty())
      {
        return;
      }
      request = requests.RemoveFront();
    }
    requests.InsertFront(request);
  }
}

// EFFECTS: Simulate the actions of the agent at this tick. The agent must
// follow these rules:
// 1. If the agent is not busy, the agent checks each queue, in priority order
// from Platinum to None. If the agent finds a call, the agent answers the
// call, and you should print a message that exactly matches the following
// example (with the correct name):
//
// Answering call from Jeff
//
// You will need to decrement time_agent_busy by 1.
//
// 2. If the agent was already busy at the beginning of this tick, the agent
// continues servicing the current client. You will need to decrement
// time_agent_busy by 1.
//
// 3. If the agent is not busy, and there are no current calls, the agent
// does nothing.
//
// If all calls have been placed, answered, and completed, then return true
// to end the program. Otherwise, return false.

// PSEUDOCODE:
//  function SimulateAgent(requests: Dlist<reqNode*>, queues: Dlist<reqNode*>[], time_agent_busy: int) -> bool {
//      // Initialize flag for all calls handled
//      all_calls_handled = true

//     // Check if agent is available
//     if time_agent_busy <= 0 {
//         // Check queues for calls to answer
//         i = 3
//         while i >= 0 {
//             if !queues[i].IsEmpty() {
//                 // Answer call and update agent's busy time
//                 request = queues[i].RemoveFront()
//                 print "Answering call from " + request.name
//                 time_agent_busy += request.duration - 1
//                 all_calls_handled = false
//                 break
//             }
//             else {
//                 i--
//             }
//         }
//     }
//     else {
//         // Update agent's busy time
//         time_agent_busy--
//         all_calls_handled = false
//     }

//     // Check if all calls are handled and no more requests are waiting
//     if all_calls_handled && requests.IsEmpty() {
//         return true
//     }
//     else {
//         return false
//     }
// }

bool SimulateAgent(Dlist<reqNode *> &requests, Dlist<reqNode *> queues[], int &time_agent_busy)
{
  bool all_calls_handled = true; // Initialize flag for all calls handled
  if (time_agent_busy <= 0)
  {
    int i = 3;
    while (i >= 0) // Check queues for calls to answer
    {
      if (!queues[i].IsEmpty()) // Answer call and update agent's busy time
      {
        reqNode *request = queues[i].RemoveFront();
        std::cout << "Answering call from " << request->name << std::endl;
        time_agent_busy += request->duration;
        time_agent_busy--;
        all_calls_handled = false;
        break;
      }
      else
      {
        i--;
        continue;
      }
    }
  }
  else
  { // Update agent's busy time
    time_agent_busy--;
    all_calls_handled = false;
  }
  if (all_calls_handled && requests.IsEmpty()) // Check if all calls are handled and no more requests are waiting
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main()
{
  // The current time, starting at tick 0.
  int clock = 0;

  // The remaining time that the agent is busy with the current
  // caller, or 0 if the agent is not busy.
  int time_agent_busy = 0;

  // An array of four queues, one for each status: regular, silver,
  // gold, platinum. Each queue is a DList of pointers to reqNode
  // structs.
  Dlist<reqNode *> queues[4];

  // A queue of requests matching the input. The queue is a DList of
  // pointers to reqNode structs.
  Dlist<reqNode *> requests;

  // Flag for whether or not the program should terminate.
  bool done = false;

  // Array of status name strings for each Status.
  std::string status_names[4];
  status_names[NONE] = "regular";
  status_names[SILVER] = "silver";
  status_names[GOLD] = "gold";
  status_names[PLATINUM] = "platinum";

  // Run call center simulation.
  ObtainRequests(requests);
  while (!done)
  {
    std::cout << "Starting tick #" << clock << std::endl;
    InsertRequests(requests, queues, clock, status_names);
    done = SimulateAgent(requests, queues, time_agent_busy);
    clock++;
  }

  return 0;
}
