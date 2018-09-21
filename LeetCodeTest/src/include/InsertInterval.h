/*
57. Insert Interval
Total Accepted: 51578 Total Submissions: 223239 Difficulty: Hard
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <iostream>
#include <algorithm>
#include "Common.h"

namespace InsertInterval
{
  // Definition for an interval.
  struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
  };

  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
  {
    int n = intervals.size();
    if (0 == n) return vector<Interval>{ newInterval };
    vector<Interval> result;
    for (int i = 0; i < n; i++)
    {
      auto& interval = intervals[i];
      if (newInterval.start > interval.end)
      {
        // newInterval comes after interval
        result.emplace_back(interval);
        continue;
      }

      if (newInterval.end < interval.start)
      {
        // newInterval comes before interval
        // add newInterval, and then the rest of intervals
        result.emplace_back(newInterval);
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        return result;
      }
      // there is overlapping, merge interval with newInterval
      newInterval.start = min(newInterval.start, interval.start); 
      newInterval.end = max(newInterval.end, interval.end);
    }
    result.emplace_back(newInterval);
    return result;
  }

  //static bool cmp(const Interval &interval1, const Interval &interval2)
  //{
  //  return interval1.start < interval2.start;
  //}

  vector<Interval> merge(vector<Interval>& intervals)
  {
    vector<Interval> result;
    int n = intervals.size();
    if (n == 0) return move(result);
	sort(intervals.begin(), intervals.end(), [](const Interval& int1, const Interval& int2) { return int1.start < int2.start; });
    for (int i = 0; i < n; i++)
    {
      auto start = intervals[i].start;
      auto end = intervals[i].end;
      while (i < n - 1 && end >= intervals[i + 1].start)
      {
        if (intervals[i + 1].end > end)
          end = intervals[i + 1].end;
        i++;
      }
      result.emplace_back(start, end);
    }
    return move(result);
  }

  vector<Interval> insertWithMerge(vector<Interval>& intervals, Interval newInterval)
  {
    intervals.emplace_back(newInterval);
    return merge(intervals);
  }

  int Test(vector<pair<int, int>> intPairs)
  {
    vector<Interval> intervals;
    for (const auto& pair : intPairs)
    {
      cout << "[" << pair.first << "," << pair.second << "] ";
      intervals.emplace_back(pair.first, pair.second);
    }
    cout << endl;

    Interval newInterval(2, 6);
    cout << "[" << newInterval.start << "," << newInterval.end << "] ";
    cout << endl;

    auto result = insert(intervals, newInterval);
    for (const auto& interval : result)
    {
      cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
    return 0;
  }
}