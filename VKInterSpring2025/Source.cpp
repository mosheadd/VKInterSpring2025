#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "vector"


using namespace std;

int main()
{

	ifstream graphFile;
	graphFile.open("graph.txt");


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

	return 0;

}
