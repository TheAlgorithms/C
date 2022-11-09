/*
Prompt:

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.

It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

bool isMatch(char* s, char* p);
bool matchStar(char ch, char* s, char* p);

/*
Uses Rob pikes Regexp matcher - https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
Implementation:
    // match: search for regexp anywhere in text 
    int match(char *regexp, char *text)
    {
        if (regexp[0] == '^')
            return matchhere(regexp+1, text);
        do {  
            if (matchhere(regexp, text))
                return 1;
        } while (*text++ != '\0');
        return 0;
    }
*/

bool matchStar(char ch, char* s, char* p) {
  do {
    if (isMatch(s, p))
      return true;
  } while (*s != '\0' && (*s++ == ch || ch == '.'));

  return false;
}

bool isMatch(char* s, char* p) {
  if (*p == '\0')
    return *s == '\0';

  if (p[1] == '*')
    return matchStar(p[0], s, p + 2);

  if (*s != '\0' && (p[0] == '.' || *p == *s)) {
    return isMatch(s + 1, p + 1);
  }

  return false;
}
