#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

//利用Queue队列

/*
int main()
{
	int n;
	cin >> n;

	queue<pair<int, int>> country;

	for (int i = 1; i <= pow(2, n); i++)
	{
		int ability;
		cin >> ability;
		country.push(make_pair(ability, i));
	}

	pair<int, int> tempA, tempB;


	while (country.size() != 2)
	{
		tempA = country.front();
		country.pop();
		tempB = country.front();
		country.pop();

		if (tempA.first >= tempB.first)
		{
			country.push(tempA);
		}
		else
		{
			country.push(tempB);
		}
	}

	tempA = country.front();
	country.pop();
	tempB = country.front();
	country.pop();

	if (tempA.first >= tempB.first)
	{
		cout << tempB.second;
	}
	else
	{
		cout << tempA.second;
	}

	return 0;
}
*/


//利用Vector数组

/*
int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> country;

	for (int i = 0; i < pow(2, n); i++)
	{
		int ability;
		cin >> ability;
		country.push_back(make_pair(ability, i + 1));
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < country.size(); j++)
		{
			if (country[j + 1].first > country[j].first)
			{
				country.erase(country.begin() + j);
			}
			else
			{
				country.erase(country.begin() + j + 1);
			}
		}
	}

	if (country[1].first > country[0].first)
	{
		cout << country[0].second;
	}
	else
	{
		cout << country[1].second;
	}

	return 0;
}
*/