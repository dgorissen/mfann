disp('Compiling the FANN mex interface (requires the fann library to be installed)..');

mex -O CC#gcc CFLAGS#"-Wall -fPIC -O3" -lm -lfann -c helperFann.c
mex -O CC#gcc CFLAGS#"-Wall -fPIC -O3" -lm -lfann createFann.c helperFann.o
mex -O CC#gcc CFLAGS#"-Wall -fPIC -O3" -lm -lfann trainFann.c helperFann.o
mex -O CC#gcc CFLAGS#"-Wall -fPIC -O3" -lm -lfann testFann.c helperFann.o
