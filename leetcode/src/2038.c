// Remove Colored Pieces if Both Neighbors are the Same Color
// Runtime: O(n)
// Space: O(1)
bool winnerOfGame(char* colors)
{
    int points[] = {0, 0};
    int len = strlen(colors);

    for (int i = 1; i < len; i++)
    {
        if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            points[colors[i] - 'A'] += 1;
    }

    return points[0] > points[1];
}
