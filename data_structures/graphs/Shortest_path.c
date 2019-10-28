#include <stdio.h>
//#include "pathfinder.h"
#include <stdlib.h>
#include "string.h"


#define MAXCITY 20
#define MYINFINITY 99999
#define NOROAD 99999
// data structure to store graph edges

char city_array[20][MAXCITY] =
{
		"Srinagar",
		"Amritsar",
		"Dehradun",
		"Delhi",
		"Jaipur",
		"Patna",
		"Ahmedabad",
		"Surat",
		"Mumbai",
		"Nagpur",
		"Ranchi",
		"Guahati",
		"Kolkata",
		"Hyderabad",
		"Bhuvaneshwar",
		"Vizag",
		"Bangalore",
		"Chennai",
		"Kochi",
		"Ernakulam"
};
int numberOfEdgeArray[MAXCITY]= {3,3,2,8,4,3,2,4,5,3,3,2,5,6,3,3,6,4,4,3 };
int shortPath[MAXCITY];

struct EDGE_T 
{
	int destNodeID;  //destination node
	int distance; //weight of the edge, here distance between 2 cities
};

struct NODE_T
{
	char city[20];
	int thisNodeID;
	struct EDGE_T* pEdgelist;
};

struct GRAPH_T
{
	struct NODE_T* pNodeArray;
};



int Distance[MAXCITY][MAXCITY] = 
{
	{NOROAD, 410,120,220,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{410, NOROAD,NOROAD,170,220,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{120, NOROAD,NOROAD,160,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{220, 170,160,NOROAD,500,610,NOROAD,600,NOROAD,1100,NOROAD,NOROAD,NOROAD,1700,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, 220,NOROAD,500,NOROAD,NOROAD,430,400,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,610,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,330,NOROAD,NOROAD,770,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,430,NOROAD,NOROAD,NOROAD,300,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,600,400,NOROAD,300,NOROAD,200,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,200,NOROAD,500,NOROAD,NOROAD,NOROAD,700,NOROAD,NOROAD,1500,NOROAD,2000,NOROAD},
	{NOROAD, NOROAD,NOROAD,1100,NOROAD,NOROAD,NOROAD,NOROAD,500,NOROAD,NOROAD,NOROAD,1250,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,330,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,580,180,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,580,NOROAD,480,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,1250,180,480,NOROAD,810,270,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,1700,NOROAD,770,NOROAD,NOROAD,700,NOROAD,NOROAD,NOROAD,810,NOROAD,730,NOROAD,550,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,270,730,NOROAD,310,NOROAD,NOROAD,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,310,NOROAD,915,935,NOROAD,NOROAD},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,1500,NOROAD,NOROAD,NOROAD,NOROAD,550,NOROAD,915,NOROAD,330,345,520},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,935,330,NOROAD,530,455},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,2000,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,345,530,NOROAD,385},
	{NOROAD, NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,NOROAD,520,455,385,NOROAD},


};

// A data structure to represent a node of graph
GRAPH_T* createGraph();
int addCityToGraph();
int findShortestPath(int srcCity, int dstCity);
struct GRAPH_T *pGraph = NULL;


GRAPH_T* createGraph()
{
	struct GRAPH_T* graph = (struct GRAPH_T*) malloc(sizeof(GRAPH_T));

	graph->pNodeArray = (struct NODE_T*) malloc(MAXCITY* sizeof(NODE_T));

	for(int i=0; i<MAXCITY; i++)
	{
		strcpy_s(graph->pNodeArray[i].city,city_array[i]);
		graph->pNodeArray[i].thisNodeID = i;
		graph->pNodeArray[i].pEdgelist = (struct EDGE_T*) malloc(numberOfEdgeArray[i]* sizeof(EDGE_T));

	}
	return graph;
}



int addCityToGraph()
{	
	int edgeListIndex = 0;
	if(pGraph == NULL)
		return 0;
//to make the adjacency matrix
	for(int i=0; i<MAXCITY; i++)
	{
		for(int j=0; j<MAXCITY; j++)
		{
			if(Distance[i][j] != NOROAD)
			{
				pGraph->pNodeArray[i].pEdgelist[edgeListIndex].distance = Distance[i][j];
				pGraph->pNodeArray[i].pEdgelist[edgeListIndex].destNodeID = j;

				edgeListIndex++;

			}
		}

		edgeListIndex =0;
	}
	
	return 1;
}

int findShortestPath(int srcCity, int dstCity) 
{	
	int cost[MAXCITY][2]; //cost[cityindex][0] is cost; cost[cityindex][1] is from which city
	int visited[MAXCITY];
	
	struct EDGE_T* edgeList;
	int numberOfEdge = 0;
	int pathIndex = 0;
	int cityIndex =0;
	int minNodeId,minVal;


	//to initialise
	for(int i=0; i<MAXCITY; i++)
	{
		cost[i][0] = MYINFINITY;
		cost[i][1] = MYINFINITY;
		visited[i] = 0;
		shortPath[i] = MYINFINITY;
	}
	// find src node attributes
	cost[srcCity][0] = 0;
	cost[srcCity][1] = srcCity;
	shortPath[pathIndex] = srcCity;
//	pathIndex = pathIndex+1;
	cityIndex = srcCity;
	
	while(visited[dstCity]==0)
	{
		minVal = MYINFINITY;
		visited[cityIndex] = 1;
		edgeList = pGraph->pNodeArray[cityIndex].pEdgelist;
		numberOfEdge = numberOfEdgeArray[cityIndex];

		
		
		for(int k=0; k<numberOfEdge; k++)
		{
			if(visited[edgeList[k].destNodeID] == 0)
			{
				if(cost[edgeList[k].destNodeID][0] > (edgeList[k].distance + cost[cityIndex][0] ))
				{
					cost[edgeList[k].destNodeID][0] = edgeList[k].distance + cost[cityIndex][0];
					cost[edgeList[k].destNodeID][1] = cityIndex;
				}


			}
		}

		for(int j=0; j<MAXCITY; j++)
		{
			if(visited[j] == 0)
			{
				if(cost[j][0] < minVal) 
				{
					minVal = cost[j][0];
					minNodeId = j;
				}
			}
		}

	//	pathIndex = pathIndex+1;
	//	shortPath[pathIndex] = minNodeId;
	//	visited[minNodeId] = 1;
		
		cityIndex = minNodeId;
	}

	cityIndex = dstCity;
	shortPath[pathIndex] = cityIndex;

	while(cityIndex != srcCity)
	{
		cityIndex = cost[cityIndex][1];
		pathIndex = pathIndex+1;
		shortPath[pathIndex] = cityIndex;
	}
		
	return 0;
}

int main()
{
	char srcCity[20];
	char dstCity[20];

	int srcCityID =999;
	int destCityID =999;

	int retVal = 0;

	pGraph= createGraph();

	for(int i=0; i<MAXCITY; i++)
	{
		printf(" City: %d : %s \n",i,pGraph->pNodeArray[i].city);

	}

	addCityToGraph();

	printf("Enter Source City: ");
	scanf_s("%s",srcCity, (unsigned)_countof(srcCity));



	for (int i=0; i<MAXCITY; i++)
	{
		if((strcmp(city_array[i],srcCity)==0))
		{
			srcCityID = i;
			break;
		}
	}
	if(srcCityID ==999) 
	{
		printf("Source city name not correct \n ");
		retVal = -1;
	}
	else
	{
		printf("Enter Destination City: ");
		scanf_s("%s", dstCity, (unsigned)_countof(dstCity));

		for (int j = 0; j < MAXCITY; j++)
		{
			if ((strcmp(city_array[j], dstCity) == 0))
			{
				destCityID = j;
				break;
			}
		}
		if (destCityID == 999)
		{
			printf("Destination city name not correct\n ");
			retVal = -1;
		}

		if ((destCityID == srcCityID) && (destCityID != 999) && (srcCityID != 999))
		{
			printf("Destination and source city same \n");
			retVal = -1;
		}

		if (retVal == 0)
		{
			findShortestPath(srcCityID, destCityID);//sends the source and destination city to function to compute route
			printf("Shortest path is :  ");
			for (int x = MAXCITY - 1; x >= 0; x--)
			{
				if (shortPath[x] != MYINFINITY)
				{
					printf("--> %s ", pGraph->pNodeArray[shortPath[x]].city);

				}
			}
		}
	}
	return retVal;
}