// 1¹ø
#if 1
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	queue<int> q;

	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		q.push(i);
;	}

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << endl;

	return 0;
}
#endif

//2¹ø
#if 1
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int n, key, imp;
	int loc, val;
	int cnt = 0;

	priority_queue<int> imp_q;
	queue<pair<int, int>> q;

	cin >> n; cin >> key;

	for (int i = 0; i < n; i++)
	{
		cin >> imp;
		imp_q.push(imp);
		q.push({ i, imp });
	}

	while (!q.empty())
	{
		loc = q.front().first;
		val = q.front().second;

		q.pop();

		if (imp_q.top() == val)
		{
			imp_q.pop();
			++cnt;
			if (key == loc)
			{
				printf("%d\n", cnt);
				break;
			}
		}
		else
		{
			q.push({ loc, val });
		}
	}
}
#endif