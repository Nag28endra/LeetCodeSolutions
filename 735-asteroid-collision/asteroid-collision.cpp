class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // defining a stack in the form of vector so no need of reversing it at the end.
        vector<int> st;

        for(int i = 0; i<asteroids.size(); i++){
            // if the asteroid is moving in positive direction push it.
            if (asteroids[i] > 0) st.push_back(asteroids[i]);

            // if the asteroid is moving in negative direction check for collosion
            else{
                // if the asteroid in stack is positive and lesser than the asteroid traveling
                // in oppositie direction pop them out.
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
                      st.pop_back();
                // if the asteroid in the top of the stack is equals to the asteroid travelling
                // oppositie direction also pop it out.
                if(!st.empty() && st.back() == abs(asteroids[i])) st.pop_back();
                // if stack is empty and the asteriod is travelling in oppositie direction
                // push it into the stack.
                else if (st.empty() || st.back() < 0) st.push_back(asteroids[i]);
            } 
        }
        return st;
    }
};