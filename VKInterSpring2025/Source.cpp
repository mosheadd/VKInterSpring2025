#include "iostream"
#include "fstream"
#include "string"
#include "map"
#include "vector"
#include "queue"



using namespace std;


void bfs(map<int, vector<int>>& graph, int startVert, int vertices)
{

	cout << "bfs alg begins...\n";

	vector<bool> visited(vertices, false); // vektor, hranyashii v sebe informaciyu o tom, posetili mi etu vershinu ili net vo izbezhanii zaciklivaniya
	vector<int> distance(vertices, -1); // vektor rasstoyanii ot iznachalnoi vershini do kazhdoi vershini grafa

	visited[startVert] = true;
	distance[startVert] = 0;

	queue<int> visiting; // ochered' dlya poocheryodnoi obrabotki vershin
	visiting.push(startVert);

	while (visiting.size() != 0)
	{

		int nextToVisit = visiting.front();
		visiting.pop();

		int distanceToCurrent = distance[nextToVisit];

		for (int edg : graph[nextToVisit]) // dobavlyaem v ochered' smezhnye vershini s tekushei
		{
			if (!visited[edg]) // esli vershina ne byla do etogo poseshena
			{
				visiting.push(edg);
				visited[edg] = true;
				distance[edg] = distanceToCurrent + 1;
			}
		}

	}

	cout << "bfs alg ends...\nOutput answer : \n";

	for (int edg : distance)
	{
		cout << edg << endl;
	}

}


void processFile(string path)
{

	ifstream graphFile;
	graphFile.open(path);

	if (!graphFile.is_open())    // Esli ne naideno faila s takim putyom to brosaem oshibku s soobsheniem ob etom
		throw "File not found!";

	int vertices, edges;

	string verticesSTR, edgesSTR;
	getline(graphFile, verticesSTR);
	getline(graphFile, edgesSTR);

	vertices = stoi(verticesSTR);
	edges = stoi(edgesSTR);

	map<int, vector<int>> graph; // container hranyashii v sebe sam graf

	string curr_str;
	for (int i = 0; i < edges; i++) // prohodimsya po ryobram
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

	try
	{
		bfs(graph, stoi(curr_str), vertices); // vyzov funkcii poiska v shirinu
	}
	catch (...)
	{
		cout << "An unidentified error happened!\n";
	}

}


int main()
{
	
	string path;
	cout << "Enter path to the file: ";  // Vvod putya do faila
	cin >> path;

	try
	{
		processFile(path);
	}
	catch (const char* error_message)
	{
		cout << error_message << endl;
	}
	catch (...)
	{
		cout << "An unidentified error happened!\nMost likely the file doesnt match the template.\n";
	}


	return 0;

}
