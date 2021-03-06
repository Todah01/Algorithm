#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define LEN 100000

using namespace std;

string main()
{
	vector<string> participant;
	vector<string> completion;
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
			return participant[i];
	}
	return participant[participant.size() - 1];
}