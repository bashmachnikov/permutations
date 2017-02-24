#include <vector>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef vector<int> perm_t;
typedef vector<perm_t> perm_collection_t;


// fill the out vector of permutations with input permutation expanded with
// the new number
void permute(int n, const perm_t& in, perm_collection_t& out){
	perm_t::const_iterator it;
	perm_t::const_iterator it_end;

	int i;
	int perm_sz = in.size();
	int m = perm_sz+1;
	perm_t p;
	p.resize(m);

	// add to front
	p[0] = n;
	copy( in.begin(), in.end(), p.begin()+1 );
	out.push_back(p);

	// add to end
	p[perm_sz] = n;
	copy( in.begin(), in.end(), p.begin() );
	out.push_back(p);

	it = in.begin();
	it_end = in.end();

	// add in every position
	for( i=1; i<perm_sz; ++i){
		copy( it, it+i, p.begin() );
		p[i] = n;
		copy( it+i, it_end, p.begin()+i+1 );

		out.push_back(p);
	}
}

// recursively expand permutations
// input: current - value that will be entered into all position
// 				n - stop condition
//		       in - collection of permutations to expand
//	output: out - collection of all permutations
void permute_create(int current, int n, const perm_collection_t& in, perm_collection_t& out){

	if( current == n ){
		copy( in.begin(), in.end(), back_inserter(out) );
		return;
	}

//	cout<<__LINE__<<","<<__FUNCTION__<<": "<<current<<","<<n<<"\n";

	perm_collection_t tmp;
	perm_collection_t::const_iterator it = in.begin();
	perm_collection_t::const_iterator it_end = in.end();


	for( ; it!=it_end; ++it){
		permute( current, *it, tmp );
	}

	permute_create( current+1, n, tmp, out );
}


// create collection of permutations of numbers from 0 to n;
// ! note ! will call recursive function thus for big N the might crash
// input: 	n number [0 to n]
// output:  collection of permutations
void permute_n(int n, perm_collection_t& out){
	if( n < 0 ){
		return;
	}

//	cout<<__LINE__<<","<<__FUNCTION__<<": "<<n<<"\n";

	perm_collection_t tmp;
	perm_t p;

	p.push_back(0);
	tmp.push_back( p );

	if( n == 0 ){
		out = tmp;
		return;
	}

	permute_create(1, n, tmp, out);
}


// prints collection of permutations
void print_collection(const perm_collection_t& a){
	perm_collection_t::const_iterator it = a.begin();
	perm_collection_t::const_iterator it_end = a.end();
	int i=0;

	for( ; it!=it_end; ++it, ++i ){
		cout<<i<<": ";
		copy( it->begin(), it->end(), ostream_iterator<int>( cout, ",") );
		cout<<"\n";
	}
}


int version_1(int n)
{
	perm_collection_t a;

	permute_n( n, a);

//	cout<<"result\n";

//	print_collection(a);

	return a.size();

}

void fill_perm(int n, perm_t& p)
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


int version_2(int n)
{
	int i;
	perm_t p;
	fill_perm(n, p);


	i=0;
	do {
		++i;
//		cout<<++i<<": ";
//		copy( p.begin(), p.end(), ostream_iterator<int>( cout, ", ") );
//		cout<<"\n";
	} while ( std::next_permutation(p.begin(),p.end()) );

//	cout << "expected last line number "<< f <<"\n";

	return i;

}

//
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	cout<< "version 1 recursive Non-sorted returned "<<version_1(n)<<" results\n";
	cout<< "version 2 using std::next_permutation "<<version_2(n)<<" results\n";
}

