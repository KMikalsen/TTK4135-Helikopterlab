function [a, b] = mycon(x)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

% system parameters
alpha = 0.2;
beta = 20;
lambda_t = 2*pi/3;
N = 40;

myc = @(lambda, e) alpha * exp(-beta .* (lambda - lambda_t).^2) - e;
c = @(x) myc(x(1 : 6 : 6*N), x(5 : 6 : 6*N));

a = c(x);
b = [];
%mycon = @(x) [c(x), []];

end


