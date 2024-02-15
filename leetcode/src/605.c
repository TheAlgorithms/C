/**
 * Determines if n new flowers can be planted in the flowerbed without violating
 * the no-adjacent-flowers rule. Approach: Iterate through the flowerbed array,
 * checking for spots where a flower can be planted (i.e., where the current
 * spot and its adjacent spots are empty). Update the flowerbed array to reflect
 * the planting and increment a counter. Stop if the required number of flowers
 * (n) has been planted.
 *
 * Time Complexity: O(flowerbedSize), as we iterate through the flowerbed array
 * once. Space Complexity: O(1), as we use a fixed amount of space regardless of
 * the input size.
 *
 * @param flowerbed Pointer to the array representing the flowerbed, where 0
 * indicates an empty spot and 1 indicates a flower.
 * @param flowerbedSize The size of the flowerbed array.
 * @param n The number of flowers we wish to plant.
 * @return True if it is possible to plant n flowers without violating the rule
 * that no two flowers can be adjacent, otherwise false.
 */
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    // Handle edge case: single empty spot in flowerbed
    if (flowerbedSize == 1 && flowerbed[0] == 0)
        return true;

    int count = 0;  // Counter for the number of flowers planted
    for (int i = 0; i < flowerbedSize; i++)
    {
        // Check if current spot is empty
        if (flowerbed[i] != 1)
        {
            if (i == 0)
            {
                // Special case for the first element: check if the next element
                // is empty
                if (flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;  // Plant flower
                    count++;
                }
            }
            else if (i == flowerbedSize - 1)
            {
                // Special case for the last element: check if the previous
                // element is empty
                if (flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;  // Plant flower
                    count++;
                }
            }
            else
            {
                // For middle elements, check both previous and next elements
                // are empty
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;  // Plant flower
                    count++;
                }
            }
        }
        // Check if the required number of flowers has been planted
        if (count >= n)
            return true;
    }
    // Return false if unable to plant the required number of flowers
    return false;
}
