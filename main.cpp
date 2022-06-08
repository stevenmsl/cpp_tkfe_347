#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol347;

/*
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/
tuple<vector<int>, int, vector<int>>
testfixture1()
{
  auto input = vector<int>{1, 1, 1, 2, 2, 3};
  auto output = vector<int>{1, 2};

  return make_tuple(input, 2, output);
}

/*
Input: nums = [1], k = 1
Output: [1]
*/
tuple<vector<int>, int, vector<int>>
testfixture2()
{
  auto input = vector<int>{1};
  auto output = vector<int>{1};

  return make_tuple(input, 1, output);
}

void test1()
{
  auto f = testfixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;

  Solution sol;
  cout << Util::toString(sol.topKFrequent(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testfixture2();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;

  Solution sol;
  cout << Util::toString(sol.topKFrequent(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}