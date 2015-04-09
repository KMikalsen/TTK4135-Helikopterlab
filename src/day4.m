% ********************************************************
% *                                                      *
% *       Optimization and Control                       *
% *                                                      *
% *       Helikopterlab                                  *
% *                                                      *
% * MAIN1NY.m                                            *
% *                                                      *
% *                                                      *
% * Updated on 04/2009 by Agus Ismail Hasan              *
% *                                                      *
% ********************************************************

init04;
delta_t	  = 0.25;	                    % sampling time
sek_forst = 5;

q = 0.1;
% System model. x=[lambda r p p_dot]'

A = [1 delta_t 0 0 0 0;
      0 1 -K_2*delta_t 0 0 0;
      0 0 1 delta_t 0 0;
      0 0 -K_1*K_pp*delta_t 1-K_1*K_pd*delta_t 0 0;
      0 0 0 0 1 delta_t;
      0 0 0 0 -delta_t*K_3*K_ep 1-delta_t*K_3*K_ed];
  
B = [0 0; 0 0; 0 0; K_1*K_pp*delta_t 0; 0 0; 0 delta_t*K_3*K_ep];

% Number of states and inputs

mx = size(A,2);                        % Number of states (number of columns in A)
mu = size(B,2);                        % Number of inputs(number of columns in B)

% Initial values

x1_0 = pi;                              % Lambda
x2_0 = 0;                               % r
x3_0 = 0;                               % p
x4_0 = 0;                               % p_dot
x5_0 = 0;                               % e
x6_0 = 0;                               % e_dot
x0   = [x1_0 x2_0 x3_0 x4_0 x5_0 x6_0]';          % Initial values

q_1 = 1;
q_2 = 1;
alfa = 0.2;
beta = 20;
lambda_t = 2*pi/3;

% Time horizon and initialization

N  = 40;                                % Time horizon for states
M  = N;                                 % Time horizon for inputs
z  = zeros(N*mx+M*mu,1);                % Initialize z for the whole horizon
z0 = z;                                 % Initial value for optimization


% Bounds

ul 	    = -30*pi/180;                   % Lower bound on control -- u1
uu 	    = 30*pi/180;                    % Upper bound on control -- u1

xl      = -Inf*ones(mx,1);              % Lower bound on states (no bound)
xu      = Inf*ones(mx,1);               % Upper bound on states (no bound)
xl(3)   = ul;                           % Lower bound on state x3
xu(3)   = uu;                           % Upper bound on state x3

% Generate constraints on measurements and inputs

[vlb,vub]       = genBegr2(N,M,xl,xu,ul,uu);
vlb(N*mx+M*mu)  = 0;                    % We want the last input to be zero
vub(N*mx+M*mu)  = 0;                    % We want the last input to be zero

% Generate system matrixes for linear model
Aeq = gena2(A,B,N,mx,mu);          % Generate A
beq = zeros(1, size(Aeq,1));         % Generate b
beq(1:mx) = A*x0; 	        	        % Initial value

% Generate the matrix Q and the vector c (objecitve function weights in the QP problem) 

Q1 = zeros(mx,mx);
Q1(1,1) = 1;                            % Weight on state x1
Q1(2,2) = 0;                            % Weight on state x2
Q1(3,3) = q;                            % Weight on state x3
Q1(4,4) = 0;                            % Weight on state x4
Q1(5,5) = 0;
Q1(6,6) = 0;
P1 = zeros(mu, mu);
P1(1,1) = q_1;                            % Weight on input
P1(2,2) = q_2;
Q = 2*genq2(Q1,P1,N,M,mu);              % Generate Q
c = zeros(N*mx+M*mu,1);                 % Generate c

% Solve Qp problem with linear model

costf = @(z) 0.5*z'*Q*z;
%tic
%[z,lambda] = quadprog(Q, c, [], [], Aeq, beq, vlb, vub, z0);
%t1=toc;
nonlcon = @(z) alfa*exp(-beta*(z(1+mx)-lambda_t)^2)-z(5+mx);
z = fmincon(costf, z0, [], [], Aeq, beq, vlb, vub, @mycon);
% Calculate objective value

phi1 = 0.0;
PhiOut = zeros(N*mx+M*mu,1);
for i=1:N*mx+M*mu
  phi1=phi1+Q(i,i)*z(i)*z(i);
  PhiOut(i) = phi1;
end

% Extract control inputs and states

u  = [z(N*mx+1:N*mx+M*mu);z(N*mx+M*mu)]; % Control input from solution

x1 = [x0(1);z(1:mx:N*mx)];              % State x1 from solution
x2 = [x0(2);z(2:mx:N*mx)];              % State x2 from solution
x3 = [x0(3);z(3:mx:N*mx)];              % State x3 from solution
x4 = [x0(4);z(4:mx:N*mx)];              % State x4 from solution

Antall = 5/delta_t;
Nuller = zeros(Antall,1);
Enere  = ones(Antall,1);

u   = [Nuller; u; Nuller];
x1  = [pi*Enere; x1; Nuller];
x2  = [Nuller; x2; Nuller];
x3  = [Nuller; x3; Nuller];
x4  = [Nuller; x4; Nuller];

%save trajektor1ny
t = 0:delta_t:delta_t*(length(u)-1); % real time

simin = [t' u];

% figure
                

figure(2)
subplot(511)
stairs(t,u),grid
ylabel('u')
subplot(512)
plot(t,x1,'m',t,x1,'mo'),grid
ylabel('lambda')
subplot(513)
plot(t,x2,'m',t,x2','mo'),grid
ylabel('r')
subplot(514)
plot(t,x3,'m',t,x3,'mo'),grid
ylabel('p')
subplot(515)
plot(t,x4,'m',t,x4','mo'),grid
xlabel('tid (s)'),ylabel('pdot')

x = [t' x1 x2 x3 x4];

