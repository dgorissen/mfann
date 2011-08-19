/*
 * Mex interface for the FANN library
 */

#include "helperFann.h"
#include <stdio.h>

//--------------------------------------------------------------------------------------------------------
//Calling syntax: [values] = testFann(ann,samples);
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

	if(nrhs != 2){
		mexErrMsgTxt("testFann usage: 'values = testFann(ann,samples)'");
		return;
	}

	struct fann* ann = createFannFromMatlabStruct(prhs[0]);

	unsigned int numInputs = fann_get_num_input(ann);
	unsigned int numOutputs = fann_get_num_output(ann);

	//Get the samples
	const mxArray *xData = prhs[1];
	const double* samples = mxGetPr(xData);
	int sRowLen = mxGetN(xData);
	int sColLen = mxGetM(xData);
	//printf("%i by %i samples received\n",sRowLen,sColLen);

	if(numInputs != sRowLen){
		mexErrMsgTxt("The network input dimension does not match the dimension of the passed samples!");
		return;
	}

	//Allocate memory and assign output pointer
	plhs[0] = mxCreateDoubleMatrix(sColLen, numOutputs, mxREAL);

	//Get a pointer to the data space in our newly allocated memory
	double *values = mxGetPr(plhs[0]);

	//evaluate the network on the given samples
	evaluateNetwork(ann, samples, values, sColLen);

	//printf("The tested network is\n");
	//fann_print_connections(ann);

	//destroy the ann since its no longer needed
	fann_destroy(ann);
}
//--------------------------------------------------------------------------------------------------------
