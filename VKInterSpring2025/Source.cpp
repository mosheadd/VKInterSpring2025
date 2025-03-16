#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "vector"
#include "stack"
#include "queue"



using namespace std;


void dfs(map<char, vector<char>> graph, char startVert)
{

	map<char, pair<bool, int>> visited;

	visited[startVert].first = true;
	visited[startVert].second = 0;

	queue<char> visiting;

	visiting.push(startVert);

	while (visiting.size() != 0)
	{

		char nextToVisit = visiting.front();
		visiting.pop();

		int distanceToCurrent = visited[nextToVisit].second;

		for (char edg : graph[nextToVisit])
		{
			if (!visited[edg].first)
			{
				visiting.push(edg);
				visited[edg].first = true;
				visited[edg].second = distanceToCurrent + 1;
			}
		}

		cout << nextToVisit << endl;

	}


	for (auto edg : visited)
	{
		cout << edg.first << " " << edg.second.second << endl;
	}

}


int main()
{

	ifstream graphFile;
	graphFile.open("test1.txt");


	int vertices, edges;

	string verticesSTR, edgesSTR;
	getline(graphFile, verticesSTR);
	getline(graphFile, edgesSTR);

	vertices = stoi(verticesSTR);
	edges = stoi(edgesSTR);

	cout << "Vertices of this grpah: " << vertices << endl;
	cout << "Edges of this grpah: " << edges << endl;


	map<char, vector<char>> graph;

	string curr_str;
	for(int i=0;i<edges;i++)
	{

		getline(graphFile, curr_str);

		int vertFirst = curr_str[0];
		int vertSecond = curr_str[2];

		graph[vertFirst].push_back(vertSecond);
		graph[vertSecond].push_back(vertFirst);

	}

	getline(graphFile, curr_str);
	char startingVert = curr_str[0];

	graphFile.close();

	dfs(graph, startingVert);


	return 0;

}
