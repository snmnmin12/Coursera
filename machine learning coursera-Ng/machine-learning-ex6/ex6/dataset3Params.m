function [C, sigma] = dataset3Params(X, y, Xval, yval)
%EX6PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = EX6PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.3;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%
sigma0 = [0.01 0.1 1 10];
C0 = [0.03 0.3 3 30];

max = 1000;

for i = 1 : 4
    for j = 1 : 4
    Cx = C0(i);
    sigmax = sigma0(j);
    model= svmTrain(X, y, Cx, @(x1, x2)gaussianKernel(x1, x2, sigmax)); 
    predictions  = svmPredict(model, Xval);
    error = mean(double(predictions ~= yval));
     if abs(error) < max
         max = abs(error);
         C = Cx;
         sigma = sigmax;
     end
    end
end

% =========================================================================
end
