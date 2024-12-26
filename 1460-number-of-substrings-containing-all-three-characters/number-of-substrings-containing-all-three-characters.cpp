class Solution {
public:
    int numberOfSubstrings(string s) {
        // declare an array called "lastseen" for three characters.
        // this is used to track the last seen of a character

        int lastseen[3] = {-1,-1,-1};
        int count=0;

        for(int i=0; i<s.size(); i++){
            // update the last seen of character to the current index.
            lastseen[s[i] -'a'] = i;

            if (lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                // count the substring with minimal length** of substring
                count = count + (1 + min(min(lastseen[0],lastseen[1]),lastseen[2]));
            }
        }
        return count;
    }
};