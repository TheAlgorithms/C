/**
 * @file k_means_clustering.cpp
 * @brief K Means Clustering Algorithm implemented
 * @details
 * This file has K Means algorithm implemmented
 * It prints test output in eps format
 * @author [Lakhan Nad](https://github.com/Lakhan-Nad)
 */

#include <math.h>    // PI, sin, cos
#include <stdio.h>   // printf
#include <stdlib.h>  // rand

/*! \struct observation
 *  a class to store points in 2d plane
 *  the name observation is used to denote
 *  a random point in plane
 */
typedef struct observation {
  double x, y;  // for coordinates in 2D Plane
  int group;    // the group no in which this observation would go
} observation;

/*! \struct cluster
 *  this class stores the coordinates
 *  of centroid of all the points
 *  in that cluster it also
 *  stores the count of observations
 *  belonging to this cluster
 */
typedef struct cluster {
  double x, y;   // Coordinates of centroid of this cluster
  size_t count;  // count of observations present in this cluster
} cluster;

/*! \fn printEPS
 * A function to print observations and clusters
 * The code is taken from
 * @link http://rosettacode.org/wiki/K-means%2B%2B_clustering
 * its C implementation
 * Even the K Means code is also inspired from it
 *
 * to print in a file use pipeline operator ( ./a.out > image.eps )
 *
 * @param observations - observations array
 * @param len - size of observation array
 * @param cent - clusters centroid's array
 * @param k - size of cent array
 */
void printEPS(observation pts[], size_t len, cluster cent[], int k) {
  int W = 400, H = 400;
  double min_x = __DBL_MAX__, max_x = __DBL_MIN__, min_y = __DBL_MAX__,
         max_y = __DBL_MIN__;
  double scale = 0, cx = 0, cy = 0;
  double* colors = (double*)malloc(sizeof(double) * k * 3);
  int i;
  size_t j;
  double kd = k * 1.0;
  for (i = 0; i < 3 * k; i += 3) {
    *(colors + i + 0) = (3 * (i + 1) % k) / kd;
    *(colors + i + 1) = (7 * i % k) / kd;
    *(colors + i + 2) = (9 * i % k) / kd;
  }

  for (j = 0; j < len; j++) {
    if (max_x < pts[j].x) max_x = pts[j].x;
    if (min_x > pts[j].x) min_x = pts[j].x;
    if (max_y < pts[j].y) max_y = pts[j].y;
    if (min_y > pts[j].y) min_y = pts[j].y;
  }
  scale = W / (max_x - min_x);
  if (scale > H / (max_y - min_y)) scale = H / (max_y - min_y);
  cx = (max_x + min_x) / 2;
  cy = (max_y + min_y) / 2;

  printf("%%!PS-Adobe-3.0\n%%%%BoundingBox: -5 -5 %d %d\n", W + 10, H + 10);
  printf(
      "/l {rlineto} def /m {rmoveto} def\n"
      "/c { .25 sub exch .25 sub exch .5 0 360 arc fill } def\n"
      "/s { moveto -2 0 m 2 2 l 2 -2 l -2 -2 l closepath "
      "	gsave 1 setgray fill grestore gsave 3 setlinewidth"
      " 1 setgray stroke grestore 0 setgray stroke }def\n");
  for (int i = 0; i < k; i++) {
    printf("%g %g %g setrgbcolor\n", *(colors + 3 * i), *(colors + 3 * i + 1),
           *(colors + 3 * i + 2));
    for (j = 0; j < len; j++) {
      if (pts[j].group != i) continue;
      printf("%.3f %.3f c\n", (pts[j].x - cx) * scale + W / 2,
             (pts[j].y - cy) * scale + H / 2);
    }
    printf("\n0 setgray %g %g s\n", (cent[i].x - cx) * scale + W / 2,
           (cent[i].y - cy) * scale + H / 2);
  }
  printf("\n%%%%EOF");

  // free accquired memory
  free(colors);
}

/*! \fn calculateNearest
 * Returns the index of centroid nearest to
 * given observation
 *
 * @param o - observation
 * @param clusters - array of cluster having centroids coordinates
 * @param k - size of clusters array
 */
int calculateNearst(observation* o, cluster clusters[], int k) {
  double minD = __DBL_MAX__;
  double dist = 0;
  int index = -1;
  int i = 0;
  for (; i < k; i++) {
    /* Calculate Squared Distance*/
    dist = (clusters[i].x - o->x) * (clusters[i].x - o->x) +
           (clusters[i].y - o->y) * (clusters[i].y - o->y);
    if (dist < minD) {
      minD = dist;
      index = i;
    }
  }
  return index;
}

/*! \fn calculateCentroid
 * Calculate centoid and assign it to the cluster variable
 *
 * @param observations - an array of observations whose centroid is calculated
 * @param size - size of the observations array
 * @param centroid - a reference to cluster object to store information of
 * centroid
 */
void calculateCentroid(observation observations[], size_t size,
                       cluster* centroid) {
  size_t i = 0;
  centroid->x = 0;
  centroid->y = 0;
  centroid->count = size;
  for (; i < size; i++) {
    centroid->x += observations[i].x;
    centroid->y += observations[i].y;
    observations[i].group = 0;
  }
  centroid->x /= centroid->count;
  centroid->y /= centroid->count;
}

/*!  \fn kMeans
 *   --K Means Algorithm--
 * 1. Assign each observation to one of k groups
 *    creating a random initial clustering
 * 2. Find the centroid of observations for each
 *    cluster to form new centroids
 * 3. Find the centroid which is nearest for each
 *    observation among the calculated centroids
 * 4. Assign the observation to its nearest centroid
 *    to create a new clustering.
 * 5. Repeat step 2,3,4 until there is no change
 *    the current clustering and is same as last
 *    clustering.
 * @param observations - an array of observations to cluster
 * @param size - size of observations array
 * @param k - no of clusters to be made
 *
 * @returns pointer to cluster object
 */
cluster* kMeans(observation observations[], size_t size, int k) {
  k = k < 1 ? 1 : k;
  observation* o;
  cluster* c;
  cluster* clusters = (cluster*)malloc(sizeof(cluster) * k);
  if (k == 1) {
    /*
    If we have to cluster them only in one group
    then calculate centroid of observations and
    that will be a ingle cluster
    */
    calculateCentroid(observations, size, clusters);
  } else if (k >= size) {
    /* If no of clusters is more than observations
       each observation can be its own cluster
    */
    size_t i = 0;
    for (o = observations, c = clusters; i < size; i++, o += 1, c += 1) {
      c->x = o->x;
      c->y = o->y;
      c->count = 1;
      o->group = i;
    }
  } else {
    size_t j = 0;
    int i = 0;
    /* STEP 1 */
    for (j = 0, o = observations; j < size; j++, o += 1) {
      o->group = rand() % k;
    }
    size_t changed = 0;
    size_t minAcceptedError =
        size / 10000;  // Do until 99.99 percent points are in correct cluster
    int t = 0;
    do {
      /* Initialize clusters */
      for (i = 0, c = clusters; i < k; i++, c += 1) {
        c->x = 0;
        c->y = 0;
        c->count = 0;
      }
      /* STEP 2*/
      for (j = 0, o = observations; j < size; j++, o += 1) {
        t = o->group;
        clusters[t].x += o->x;
        clusters[t].y += o->y;
        clusters[t].count++;
      }
      for (i = 0, c = clusters; i < k; i++, c += 1) {
        c->x /= c->count;
        c->y /= c->count;
      }
      /* STEP 3 and 4 */
      changed = 0;  // this variable stores change in clustering
      for (j = 0, o = observations; j < size; j++, o += 1) {
        t = calculateNearst(o, clusters, k);
        if (t != o->group) {
          changed++;
          o->group = t;
        }
      }
    } while (changed > minAcceptedError);  // Keep on grouping until we have got
                                           // almost best clustering
  }
  return clusters;
}

/*! \fn test
 * A function to test the kMeans function
 * Generates 100000 points in square
 * (0,0),(10,0),(10,10),(0,10)
 * and cluster them into 10 clusters
 */
void test() {
  size_t size = 1000000L;
  observation* observations = (observation*)malloc(sizeof(observation) * size);
  double maxRadius = 20.00;
  double radius = 0;
  double ang = 0;
  size_t i = 0;
  for (; i < size; i++) {
    radius = (maxRadius * rand()) / RAND_MAX;
    ang = (2 * M_PI * rand()) / RAND_MAX;
    observations[i].x = radius * cos(ang);
    observations[i].y = radius * sin(ang);
  }
  int k = 11;  // No of clusters
  cluster* clusters = kMeans(observations, size, k);
  printEPS(observations, size, clusters, k);
  // Free the accquired memory
  free(observations);
  free(clusters);
}

/*! \fn main
 * This function calls the test
 * function
 */
void main() {
  test();
  return;
}
