#include <vector>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef vector<int> perm_t;
typedef vector<perm_t> perm_collection_t;

void create_perm(int n, perm_t& p)
{
	int i;
	for(i=0; i<n;++i){
		p.push_back(i);
	}
}

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

//clearly this version using std::next_permutation is beautiful
int main(int argc, char *argv[])
{
	int i;
	int n = atoi(argv[1]);
	int f = factorial(n);
	perm_t p;
	create_perm(n, p);


	i=0;
	do {
		cout<<++i<<": ";
		copy( p.begin(), p.end(), ostream_iterator<int>( cout, ", ") );
		cout<<"\n";
	} while ( std::next_permutation(p.begin(),p.end()) );

	cout << "expected last line number "<< f <<"\n";

	return 0;
}
