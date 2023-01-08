#include <iostream>
#include <fstream>
typedef long long ll;
using namespace std;

int main() {
	
	string name, path = "C:/Folder/Programming/collatz/data/input/";

	cin >> name;
	
	path = path + name + ".txt";

	ll a, z, progress;

	cin >> z;

	ofstream data;
	ofstream config;

	config.open("C:/Folder/Programming/collatz/apps/config/config.txt");

	config << name << endl;

	config << z;

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

	system("C:\\Folder\\Programming\\collatz\\apps\\plot\\plot.exe");

	return 0;

}