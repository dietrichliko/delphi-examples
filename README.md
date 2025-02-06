# Moden DELPHI Examples

## Quickstart
Use DELPHI software with CMAKE and C++

To run an example check out the repository

```bash
git clone git@github.com:dietrichliko/delphi-examples.git
cd delphi-examples
```
and build the example program
```bash
mkdir build_example01
cd build_example01
cmake ../example01
make
cd ..
```
There is a script to run the program. One can pass a fatman
nickname as parameter.
```bash
scripts/example01.sh
```

### Example01

Run PHDST with Fortran. Demonstrate the use of patchy with cmake. 

### Example02

Run the SKELANA example SKELEXA.CAR. 

The program has been patched to produce a dimuon and a hadron CSV file.

### Example03

Run SKELANA and list some quantities.

### Example04

Run PHDST from C++. No need for Patchy, but for the PHDST language 
bindings.

### Example05 (to be done)

Run SKELANA from C++ and list some quantities

### Example06 (to be done)

Run SKELANA and produce a ROOT Ntuple of some qunatities.
