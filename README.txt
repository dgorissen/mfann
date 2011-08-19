Matlab bindings for FANN - The Fast Artificial Neural Network Library

** Background
From the FANN website (http://leenissen.dk/fann/wp/):

Fast Artificial Neural Network Library is a free open source neural network library, which implements multilayer artificial neural networks in C with support for both fully connected and sparsely connected networks. Cross-platform execution in both fixed and floating point are supported. It includes a framework for easy handling of training data sets. It is easy to use, versatile, well documented, and fast. PHP, C++, .NET, Ada, Python, Delphi, Octave, Ruby, Prolog Pure Data and Mathematica bindings are available. A reference manual accompanies the library with examples and recommendations on how to use the library. A graphical user interface is also available for the library.
FANN Matlab bindings

The Matlab Neural Network toolbox is a great piece of software but can be very slow at times. Hence the bindings for FANN. My C skills are rusty to say the least so I thought it would be a good exercise. They are pretty basic but should work fine. Note that I am only interested in regression (function approximation) so my bindings only reflect that tiny subset of the total FANN features.

** Setup

Version of the FANN library required: at least 2.1beta 

Simply run make.  The Makefile may need a little editing to fit your environtment but that should be straightforward.

Make sure the mex files are in your Matlab path and Matlab knows where to find the FANN library (e.g., see LD_LIBRARY_PATH on unix systems).

** Usage

Create a network:

  ann = createFann([2 5 3 1],connectivity)

Train a network
  
  ann = trainFann(ann,samples,values,[desired error],[max epochs])

Use a network
  
  values = testFann(ann,samples)

Where samples are the input data points and values the output values, both in column format (1 column per dimension).
Note: do not use a connectivity different from 1 for else you will get wrong results (I hope this can be fixed with the new fann library)
