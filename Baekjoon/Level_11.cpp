// 11 - 1 (Basic stack)
/*
#include<iostream>

using namespace std;
*/

// 11 - 2
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);

	int N, k, max = 0;			// N is total of numbers.		k is input variable.
	vector<int> v;				// vector v is a stack stores sequence.
	vector<string> res;			// vector res is a stack stores push and pop.

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		if (k > max)			// Push values comparing max value.
		{
			for (int j = max; j <k; j++)
			{
				v.push_back(j+1);
				res.push_back("+");
			}
		}
		else
		{
			if (v[v.size()-1] != k)		// Distinguish whether this sequence is valid or not. 
			{
				cout << "NO" << "\n";
				return 0;
			}
		}
		v.pop_back();					// Pop the max value(The last value of stack).
		res.push_back("-");

		if (max < k)
			max = k;
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";
}
*/

// 11 - 3
/*
#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

vector<string> result;

void Check(char str[51])
{
	int left = 0, right = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
			left++;
		else if (str[i] == ')' && left > right)
				right++;
	}

	if (left == right && left+right == strlen(str))
		result.push_back("YES");
	else
		result.push_back("NO");
}

int main(void)
{
	int N;
	cin >> N;
	getchar();

	char str[51];
	for (int i = 0; i < N; i++)
	{
		cin.getline(str, 51);
		Check(str);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}
*/

// 11 - 4

#include<iostream>
#include<vector>

using namespace std;

int Check(char str[])
{

	
	return 0;
}

int main(void)
{
	char str[31];
	cin.getline(str, 31);

	cout << Check(str) << "\n";
}