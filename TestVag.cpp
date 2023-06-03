#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;


// C++ class MySub

class MySub {

//name of the newspapers and their prices are stored in array of strings and 2D-Array.

//where index name[0] is for TOI and newspaper[0][0] is for Monday's Price of TOI
private:
	string name[5] = {"TOI", "Hindu", "ET", "BM", "HT"};
	float newspapers[5][7] = {
		{3, 3, 3, 3, 3, 5, 6},
		{2.5, 2.5, 2.5, 2.5, 2.5, 4, 4},
		{4, 4, 4, 4, 4, 4, 10},
		{1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
		{2, 2, 2, 2, 2, 4, 4}
	};

public:
	float weeklyCost[5];
// function to calculate weekly total cost of a particular newspaper.

	void calculateTotalCost() {
		for (int i = 0; i < 5; i++) {
			float sum = 0;
			for (int j = 0; j < 7; j++) {
				sum += newspapers[i][j];

			}
			weeklyCost[i] = sum;
		}

		for (int i = 0; i < 5; i++) {
			cout << weeklyCost[i] << endl;
		}
	}


// recursive function to find all the possible combinations of newspapers.
	void findComb(int ind, int bud, vector<vector<string>> & res, vector<string> & temp) {


		// base case
		if (ind == 5) {
			if (bud >= 0) {

				// picking only the combinations >= 2.
				if (temp.size() >= 2)
					res.push_back(temp);
			}

			return;
		}


		//picking up the element in the combination.
		if (weeklyCost[ind] <= bud) {
			temp.push_back(name[ind]);

			findComb(ind + 1, bud - weeklyCost[ind], res, temp);

			temp.pop_back();
		}

		//not picking up the element in the combination.
		findComb(ind + 1, bud, res, temp);

	}


	// helper function to call the above functions.
	vector<vector<string>> combinations(int bud) {

		calculateTotalCost();
		vector<vector<string>> res;
		vector<string> temp;

		findComb(0, bud, res, temp);

		return res;	//the res 2d string vector is updated and returned.

	}

};




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int weeklyBudget;
	vector <vector<string>> arr;

	cin >> weeklyBudget;

	MySub obj1;
	arr = obj1.combinations(weeklyBudget);

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}



}
