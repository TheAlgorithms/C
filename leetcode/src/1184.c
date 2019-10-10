int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){

  int sum1 = 0, sum2 = 0;
  if (start > destination) {
      int tmp = start;
      start = destination;
      destination = tmp;
  }
  for (auto i = 0; i < distanceSize; ++i) {
    if (i >= start && i < destination)
        sum1 += distance[i];
    else
        sum2 += distance[i];
  }
  return sum1 < sum2 ? sum1 : sum2;
}
