function y = multiobj(x)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
p=4;
ns=1000;
Kw=0.9;
y1 = (1.11*p*p*ns*Kw*4*(x(3)*x(4)*power(x(1),2))/((power((x(1)+2*(x(5)+x(6))),2))*3.14));
y(1) = -(y1);

y2 = (10837*x(2)*(0.00129 -(0.785*(x(1)^2))))+14.5 + 214*x(2);
y(2) = y2;

end