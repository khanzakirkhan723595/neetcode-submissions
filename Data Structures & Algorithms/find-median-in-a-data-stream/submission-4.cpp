class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;

    MedianFinder() {

    }

    void addNum(int num) {
        if(small.empty() || num <= small.top())
        small.push(num);
        else
            large.push(num);

        if(small.size() > large.size()+1)
        {
            large.push(small.top());
            small.pop();
        }

        if(large.size() > small.size())
        {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {

        if(large.size()>small.size())
        {
            return large.top();
        }
        if(small.size()>large.size())
        {
            return small.top();
        }
        else{
            return (small.top()+large.top())/2.0;
        }
    }
};