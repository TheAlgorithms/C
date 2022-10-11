bool isMatch(char* s, char* p);
bool matchStar(char ch, char* s, char* p);

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
