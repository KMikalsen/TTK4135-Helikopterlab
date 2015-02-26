function Q = genq2(Q1,P1,N,M,mu)

% Funksjon for aa bygge opp Q-matrisa som brukes i QP-problemet 
%                                                               
%       min sum(xi'Q1xi + ui'P1ui)                              
%       x,u                                                     
%                                                               
% i det tidsdiskrete systemet. Innholder et system for hvert    
% tidsskritt og er p� formen                                    
%                                                               
%      -           -                                            
%      |Q1         |                                            
%  Q = |  .        |                                            
%      |   Q1      |                                            
%      |     P1    |                                            
%      |       .   |                                            
%      |         P1|                                            
%      -           -                                            
%                                                               
% Kall: Q = genq2(Q1,P1,N,M,mu)                                      
%                                                               
% Q1 - Vekt p� tilstandene i kriteriet  (mx*mx matrise)                       
% P1 - Vekt p� p�dragene i kriteriet    (mu*mu matrise)                          
% N  - Tidshorisont for tilstander      (antall tidsskritt)
% M  - Tidshorisont for p�drag          (M<N ved p�dragsblokkering)
%                                                               
% 08.03.2001 Geir Stian Landsverk                               


p1	= blkdiag2(P1,M);
q1	= blkdiag2(Q1,N);

Q	= blkdiag(q1,p1); 