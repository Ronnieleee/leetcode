// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters
// Author : Ronnie
// Date   : 2015-12-06

/*******************************************************************************
* Given a string, find the length of the longest substring without repeating
* characters. For example, the longest substring without repeating letters for
* "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
* is "b", with the length of 1.
*
*
*******************************************************************************/

#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

/* Using a map to store string's char index
 *
 * easy to get the char's pervious duplicated char's index
 *
 * such as "abcabcbb" ->
 * a->0 b->1 c->2 a->
 */
int lengthOfLongestSubstring1(string s) {
    map<char, int> m;
    int maxsubstrlen = 0;
    int lastrepeatpos = -1;
    for (int i=0; i < s.size(); i++) {
        if (m.find(s[i]) != m.end() && lastrepeatpos < m[s[i]]) {
            lastrepeatpos = m[s[i]];
        }
        if (i - lastrepeatpos > maxsubstrlen) {
            maxsubstrlen = i - lastrepeatpos;
        }
        m[s[i]] = i;
    }
    return maxsubstrlen;
}

// without map
int lengthOfLongestSubstring(string s) {
    const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxsubstrlen = 0;
    int lastrepeatpos = -1;
    for (int i=0; i < s.size(); i++) {
        if (m[s[i]] != -1 && lastrepeatpos < m[s[i]]) {
            lastrepeatpos = m[s[i]];
        }
        if (i - lastrepeatpos > maxsubstrlen) {
            maxsubstrlen = i - lastrepeatpos;
        }
        m[s[i]] = i;
    }
    return maxsubstrlen;
}

int main(int argc, char** argv) {
    string s = "abcabcbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "acbdecadca";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    s = "bcacdba";
    cout << s << " : " << lengthOfLongestSubstring(s) << endl;

    if (argc > 1) {
        s = argv[1];
        cout << s << " : " << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
