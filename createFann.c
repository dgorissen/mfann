/*
 * Mex interface for the FANN library
 */

#include "helperFann.h"
#include <stdio.h>

//--------------------------------------------------------------------------------------------------------
//Calling syntax: [ann] = createFann(layers,connectivity);
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
	
	//Declarations
	const mxArray *xData;
	double *xValues;
	int j;
	int numLayers, lRowLen, lColLen;

	if(nrhs == 2){
		//do nothing
	}else{
		mexErrMsgTxt("createFann usage: 'ann = createFann(layers,connectivity''");
		return;

	}

	//Get the layers
	xData = prhs[0];
	xValues = mxGetPr(xData);
	lRowLen = mxGetN(xData);
	lColLen = mxGetM(xData);

	if(lColLen != 1){
		mexErrMsgTxt("Layers must be a vector!");
		return;
	}
	
	numLayers = lRowLen;

	unsigned int *layers = mxCalloc(numLayers, sizeof(unsigned int));

	for(j=0;j<numLayers;j++) {
		layers[j] = (unsigned int) xValues[j];
	}

	//Get the connectivity
	float connectivity = (float)(mxGetScalar(prhs[1]));

	//Create the network
	struct fann *ann = createNetwork(numLayers,layers,connectivity);

	mxArray *layersCopy = mxDuplicateArray(prhs[0]);

	//Create the struct representing this ann in matlab
	plhs[0] = createMatlabStruct(ann, layersCopy, connectivity);

	//printf("The created network is\n");
	//fann_print_connections(ann);

	//destroy the ann its no longer needed
	fann_destroy(ann);
}
//--------------------------------------------------------------------------------------------------------
