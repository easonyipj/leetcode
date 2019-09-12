//
// Created by Eason on 2019/9/12.
//
/**
 *Median is the middle value in an ordered integer list. If the size of the list is even,
 * there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "queue"

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<> > smallQueue;
    priority_queue<int> bigQueue;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(smallQueue.empty()) {
            smallQueue.push(num);
        }

        if(smallQueue.size() == bigQueue.size()) {
            if(num > smallQueue.top()) {
                smallQueue.push(num);
            }else{
                bigQueue.push(num);
            }
        }

        if(smallQueue.size() < bigQueue.size()) {
            if(num < bigQueue.top()) {
                smallQueue.push(bigQueue.top());
                bigQueue.pop();
                bigQueue.push(num);
            }else{
                smallQueue.push(num);
            }
        }

        if(smallQueue.size() > bigQueue.size()) {
            if(num > smallQueue.top()) {
                bigQueue.push(smallQueue.top());
                smallQueue.pop();
                smallQueue.push(num);
            }else{
                bigQueue.push(num);
            }
        }
    }

    double findMedian() {
        if(smallQueue.size() == bigQueue.size()) {
            return ((double)smallQueue.top() + (double)bigQueue.top()) / 2;
        }

        if(smallQueue.size() < bigQueue.size()) {
            return bigQueue.top();
        }

        return smallQueue.top();
    }
};