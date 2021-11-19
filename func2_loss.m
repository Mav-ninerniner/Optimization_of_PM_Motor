function y = func2_loss(x)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
Pcu=14.5 + 214*x(2);
Pi= 10837*x(2)*(0.00129 -(0.785*power(x(1),2)));
y = Pcu + Pi;
end
