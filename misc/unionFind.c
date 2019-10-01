int p[1000000];
int find(int x)
{
  if (p[x] == x)
  {
    return x;
  }
  else
  {
    p[x] = find(p[x]); 
    return p[x];
  }
}
// Call to function join(int x, int y) to join PARAM x and y
void join(int x, int y)
{
  p[find(x)] = find(y);
}

int main() {
    return 0;
}