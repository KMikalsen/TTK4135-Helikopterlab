function y = blkdiag(varargin) % Silly func
y = [];
for k=1:nargin
  x = varargin{k};
  [p1,m1] = size(y); [p2,m2] = size(x);
  y = [y zeros(p1,m2); zeros(p2,m1) x];
end
