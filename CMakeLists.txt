cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.cpp graph/courseSchedule.cpp dp/cutSteelStrip.cpp dp/coinsCash.cpp dp/longestPalindrome.cpp string/shortestPalindrome.cpp dp/maxSubArray.cpp dp/climbStairs.cpp dp/rob.cpp dp/maxProfit.cpp dp/wordBreak.cpp backtracking/wordSearch.cpp backtracking/restoreIpAddresses.cpp)