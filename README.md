# permutations

# there are 2 versions of the same action.
# 	v1 works recursively and produces non sorted result using additional memory 
#	v2 just use of the std::next_permutation - beutiful
# application will run both versions and compare the number of solutions 


vector of permutations
# To download:
```sh
git clone https://github.com/bashmachnikov/permutations
cd permutations
```
# To build:
```sh
mkdir build
cd build
cmake ..
make
```

#to Run:
```sh
./permutations 3
~/src/permutations/build$ ./permutations 4
version 1 recursive Non-sorted returned 24 results
version 2 using std::next_permutation 24 results
```

! No input checks are done !
