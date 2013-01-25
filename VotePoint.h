#include <iostream>

using namespace std;

class VotePoint {
    public:
        VotePoint();
        VotePoint(string in) {
            type = in;
            num = 1;
        }
        string getClass() {
            return type;
        }
        void vote() {
            num++;
        }
        int getVote() {
            return num;
        }
    private:
        string type;
        int num;
};
