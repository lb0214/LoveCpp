/*
849. Maximize Distance to Closest Person

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include "Common.h"

namespace MaxDistToClosest
{

int maxDistToClosest(vector<int>& seats) {
    int loDist = 0;
    while (seats[loDist] == 0) loDist++;
    int hiDist = 0;
    while (seats[seats.size() - hiDist - 1] == 0) hiDist++;
    int preSeat = loDist;
    int maxDist = 0;
    for (auto i = loDist + 1; i < seats.size() - hiDist; i++) {
        if (seats[i] == 0) continue;
        maxDist = max(maxDist, i - preSeat);
        preSeat = i;
    }
    return max(max(loDist, hiDist), maxDist / 2);
}

static void Test()
{
    vector<int> seats = { 1,0,0,1 };
    std::cout << maxDistToClosest(seats) << std::endl;
}
}
