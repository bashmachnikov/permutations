#include <vector>
#include <iostream>
#include <iterator>
#include <stdlib.h>


using namespace std;

typedef vector<int> perm_t;
typedef vector<perm_t> perm_collection_t;


// fill the out vector of permutations with input permutation expanded with
// the new number
void permute(int n, const perm_t& in, perm_collection_t& out){
	perm_t::const_iterator it;
	perm_t::const_iterator it_end;
	int m = in.size()+1;
	int i;

	perm_t p;
	p.resize(m);
	p[0] = n;
	copy( in.begin(), in.end(), p.begin()+1 );
	out.push_back(p);

	p.clear();
	p.resize(m);

	p[m-1] = n;
	copy( in.begin(), in.end(), p.begin() );
	out.push_back(p);

	for( i=1; i<m-1; ++i){
		p.clear();
		p.resize(m);

		p[i] = n;

		it = in.begin();
		copy( it, it+i, p.begin() );

		it = in.begin();
		copy( it+i, in.end(), p.begin()+i+1 );

		out.push_back(p);
	}
}

// recursively expand permutations
// input: current - value that will be entered into all position
// 				n - stop condition
//		       in - collection of permutations to expand
//	output: out - collection of all permutations
void permute_create(int current, int n, const perm_collection_t& in, perm_collection_t& out){

	if( current > n ){
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

//
int main(int argc, char *argv[])
{
	perm_collection_t a;

	permute_n( atoi(argv[1]), a);

	cout<<"result\n";

	print_collection(a);

	return 0;
}
