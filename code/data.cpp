#include <iostream>
#include <fstream>
#include <ctime>
typedef long long ll;
using namespace std;

int main() {
	
	string name, path = "C:/collatz/data/input/";

	cin >> name;

	path = path + name + ".txt";

	ll a, z, progress;

	cin >> z;

	ofstream data;
	ofstream config;

	config.open("C:/collatz/code/config.txt");

	config << name << endl;
	config << z;

	clock_t t1 = clock();

	config.close();
	data.open(path);

	for (ll n = 2; n < z + 1; n++) {

		a = n;

		progress = double(a) / z * 100;

		cout << progress << "%\r";
		data << a << ";";

		while (true) {

			if (a == 1) {
				break;

			}

			if (a % 2 == 0) {

				a /= 2;

				if (a == 1) {

					data << a;

				}

				else {

					data << a << ";";

				}
					

			}

			else {

				a = a * 3 + 1;

				data << a << ";";

			}
		}

		data << "\n";
		
	}

	data.close();

	clock_t t2 = clock();
	cout << "data - " << (t2 - t1 + .0) / CLOCKS_PER_SEC << "s" << "\n";

	system("python.exe plot.py");

	return 0;

}