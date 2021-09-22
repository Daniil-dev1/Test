#include "Hashset.h"

int main()
{
	srand(time(NULL));
	Hashset<int> set_n;
	Hashset<int> set_r;
	Hashset<int> set;


	for (int i = 1; i <= 50; i++) {
		int r = (rand() * 4231 + 12345) % 1000;
		if (!(set_r.insert(r)))
			break;
		else {
			cout << "_" << r << " inserted in set_r\n";
		}
	}

	cout << " ----------------\n Set of Random numbers\n";
	cout << set_r << "\n ----------------\n";

 	for (int i = -10; i <= 50; i++) {
		if(!(set_n.insert(i)))
			break;
		else {
			cout << " " << i << " inserted in set_n\n";
		}
	}
	 
	set_n.insert(-57);
	set_n.insert(-58);

	set_n.insert(-220);
	cout << " ----------------\n Set of Natural and Negatives numbers\n";
	cout << set_n << "\n ----------------\n";



	for (int i = 0; i <= 50; i++) {
		if (!(set.insert(i)))
			break;
		else {
			cout << " " << i << " inserted in set_n\n";
		}
	}
	
	cout << "----------------\n Set of Natural numbers\n";
	cout << set << "\n ----------------\n";
}
