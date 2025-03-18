#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "vector"
#include "queue"



using namespace std;


void bfs(map<int, vector<int>>& graph, int startVert, int vertices)
{

	cout << "dfs alg begins...\n";

	vector<bool> vvisited(vertices, false);
	vector<int> distance(vertices, -1);

	vvisited[startVert] = true;
	distance[startVert] = 0;

	queue<int> visiting;
	visiting.push(startVert);

	while (visiting.size() != 0)
	{

		int nextToVisit = visiting.front();
		visiting.pop();

		int distanceToCurrent = distance[nextToVisit];

		for (int edg : graph[nextToVisit])
		{
			if (!vvisited[edg])
			{
				visiting.push(edg);
				vvisited[edg] = true;
				distance[edg] = distanceToCurrent + 1;
			}
		}

	}

	cout << "dfs alg ends...\nOutput answer:\n";

	for (int edg : distance)
	{
		cout << edg << endl;
	}

}


void processFile(string path)
{

	ifstream graphFile;
	graphFile.open(path);

	int vertices, edges;

	string verticesSTR, edgesSTR;
	getline(graphFile, verticesSTR);
	getline(graphFile, edgesSTR);

	vertices = stoi(verticesSTR);
	edges = stoi(edgesSTR);

	map<int, vector<int>> graph;

	string curr_str;
	for (int i = 0; i < edges; i++)
	{

		getline(graphFile, curr_str);
		size_t curr_str_size = curr_str.size();

		int j = 0;

		string vertFirst = "";
		for (; curr_str[j] != ' '; j++)
			vertFirst += curr_str[j];

		string vertSecond = "";
		for (j++; j < curr_str_size; j++)
			vertSecond += curr_str[j];

		int ivertFirst = stoi(vertFirst);
		int ivertSecond = stoi(vertSecond);

		if (ivertFirst == ivertSecond)
			continue;

		graph[ivertFirst].push_back(ivertSecond);
		graph[ivertSecond].push_back(ivertFirst);


	}

	getline(graphFile, curr_str);

	graphFile.close();

	bfs(graph, stoi(curr_str), vertices);

}


int main()
{

	string path;
	cout << "Enter path to the file: ";
	cin >> path;

	processFile(path);

	return 0;

}
