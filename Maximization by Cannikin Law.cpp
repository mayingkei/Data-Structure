#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//function to sort by weakness descendingly
bool sortability(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] > v2[1];
}

//function to sort by strength descendingly
bool sortsample(const vector<int>& v1, const vector<int>& v2) {
	return v1[0] > v2[0];
}

int main() {
	int n, k, res = 0;
	cin >> n >> k;

	//create a 2d vector to store strength and weakness
	vector<vector<int>> ability(n, vector<int>(2));

	//store strength in first column
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		ability[i][0] = temp;
	}

	//store weakness in second column
	for (int j = 0; j < n; j++) {
		int temp;
		cin >> temp;
		ability[j][1] = temp;
	}

	//sort by weakness descendingly
	sort(ability.begin(), ability.end(), sortability);

	//start by comparing k people then add one more people to the sample each time
	for (int i = k; i <= n; i++) {
		vector<vector<int>> sample;
		int sum = 0, multi = INT_MAX, temp;

		//make a sample with size i that contain people with greatest weakness
		for (int j = 0; j < i; j++) {
			sample.push_back(ability[j]);
		}

		//sort the sameple by strength descendingly
		sort(sample.begin(), sample .end(), sortsample);

		for (int m = 0; m < k; m++) {

			//sum up the highest k strength
			sum += sample[m][0];

			//obtain the lowest weakness among the selected k people
			if (sample[m][1] < multi)
				multi = sample[m][1];
		}

		//get the current power of team
		temp = sum * multi;
		if (temp > res)
			res = temp;
	}

	//return max power of team
	cout << res;
}

