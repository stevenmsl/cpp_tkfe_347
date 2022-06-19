#include "solution.h"
#include <vector>
#include <queue>
using namespace sol347;
using namespace std;

/*takeaways
  - use max-heap to solve the problem
    - change the frequency to a negative value
      so the number with the least frequency will
      be on the top ready to be removed if
      needed
  - at any given time, the heap will maintain only
    k numbers
  - time complexity: O(nlogn)
    - each number will get inserted into the queue
      once
    - each insert takes logn
*/
vector<int> Solution::topKFrequent(vector<int> &nums, int k)
{
  auto freq = unordered_map<int, int>();
  for (auto n : nums)
    freq[n]++;

  /* we want the least frequent number on top of the heap
     - we want to maintain only k numbers in the queue
     - we want to pop the top whenever the size of the
       queue exceeds k
     - by default q is a max-heap so we need to change
       the frequency to a negative number so the least
       frequent number will be on top
  */
  auto q = priority_queue<pair<int, int>>();

  for (auto &[n, freq] : freq)
  {
    /* change the frequency to a negative number */
    q.push({0 - freq, n});
    if (q.size() > k)
      q.pop();
  }
  auto result = vector<int>();

  for (auto i = 0; i < k; i++)
    result.push_back(q.top().second), q.pop();

  return result;
}