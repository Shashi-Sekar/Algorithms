/*
LC 355. Design Twitter

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

struct Tweet{
    int tweetId;
    int time;

    Tweet(int tId, int time){
        this->tweetId = tId;
        this->time = time;
    }
};

class Twitter {

    int timestamp;

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<Tweet>> posts;
    
public:
    Twitter(): timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        posts[userId].emplace_back(tweetId, timestamp);
    }   
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> followees = following[userId];
        followees.insert(userId);

        for(int id: followees){
            auto& it = posts[id];

            for(int i=max(0, (int)it.size() - 10); i < it.size(); i++){
                pq.emplace(it[i].time, it[i].tweetId);
            }
        }

        vector<int> newsFeed;

        while(!pq.empty() && newsFeed.size() < 10){
            newsFeed.push_back(pq.top().second);
            pq.pop();
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

int main(){
    Twitter t;

    return 0;
}