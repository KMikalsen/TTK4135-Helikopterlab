function [nonlcon, other] = nonlincon(z, nx, N)

lambda_t = 2*pi/3;
alfa = 0.2;
beta = 20;

vector = NaN(N,1);

nonlcon = @(z) alfa*exp(-beta*(z(1+mx)-lambda_t)^2)-z(5+nx);
%for i=0:N-1
%    vector(i+1) = alfa*exp(-beta*(z(1+nx*i)-lambda_t)^2)-z(5+nx*i);
%end

nonlcon = vector;
other = []

end