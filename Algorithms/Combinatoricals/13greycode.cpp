//beside the lexicographicall we sometimes want other forms as well like this grey code
//can be defined as T0 = e, Tn+1 = 0Tn, 1Tn^R
//eg: T1 = 0, 1; T2 = 0T1, 1T1^R = 00, 01, 11, 10; T3 = 0T2, 1T2^R = 000, 001, 011, 010, 110, 111, 101, 100 and so on nicely done
//another tyo xor wala formula lmao writing it
//Tinfty = g(0), g(1), g(2), ... = 0, 1, 11, 10, 110 and so on generated by g(k) = k XOR floor(k/2)

//grey codes are related to something called walsh functions will check later


#include <iostream>
using namespace std;

int main()
{
	const int n = 4;
	int a[n+1];
	a[n] = 0; 	//is for utiltiy we will visit an-1 .. a0
	
	for (int i = 0; i < n; ++i)
	{
		a[i] = 0;
	}
	
	while(1)
	{
		//visit here
		for (int i = n-1; i >= 0; --i)
		{
			cout << a[i];
		}
		cout << "with parity " << a[n] << endl;
		
		a[n] = 1 - a[n];
		
		int j;
		if (a[n] == 1)
		{
			j = 0;
		}
		else
		{
			j = 1;
			while (a[j-1] != 1)
			{
				++j;
			}
		}
		if (j == n)
		{
			break;
		}
		else
		{
			a[j] = 1 - a[j];
		}
	}
	return 0;
}