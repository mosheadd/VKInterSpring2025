#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "vector"
#include "queue"



using namespace std;


void dfs(map<int, vector<int>>& graph, int startVert)
{

	cout << "dfs alg begins...\n";

	map<int, pair<bool, int>> visited;

	visited[startVert].first = true;
	visited[startVert].second = 0;

	queue<int> visiting;

	visiting.push(startVert);

	while (visiting.size() != 0)
	{

		int nextToVisit = visiting.front();
		visiting.pop();

		int distanceToCurrent = visited[nextToVisit].second;

		for (int edg : graph[nextToVisit])
		{
			if (!visited[edg].first)
			{
				visiting.push(edg);
				visited[edg].first = true;
				visited[edg].second = distanceToCurrent + 1;
			}
		}

	}

	cout << "dfs alg ends...\nOutput answer:\n";

	for (auto edg : visited)
	{
		cout << edg.second.second << endl;
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

	dfs(graph, stoi(curr_str));

}


int main()
{

	string path;
	cout << "Enter path to the file: ";
	cin >> path;

	processFile(path);

	return 0;

}
