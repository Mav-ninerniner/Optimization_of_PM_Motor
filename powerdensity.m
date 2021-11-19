function [x,fval,exitflag,output,population,score] = powerdensity(nvars,lb,ub,PopulationSize_Data,EliteCount_Data,CrossoverFraction_Data,MaxGenerations_Data)
%% This is an auto generated MATLAB file from Optimization Tool.

%% Start with the default options
options = optimoptions('ga');
%% Modify options setting
options = optimoptions(options,'PopulationSize', PopulationSize_Data);
options = optimoptions(options,'EliteCount', EliteCount_Data);
options = optimoptions(options,'CrossoverFraction', CrossoverFraction_Data);
options = optimoptions(options,'MigrationDirection', 'both');
options = optimoptions(options,'MaxGenerations', MaxGenerations_Data);
options = optimoptions(options,'NonlinearConstraintAlgorithm', 'penalty');
options = optimoptions(options,'SelectionFcn', @selectionroulette);
options = optimoptions(options,'Display', 'off');
options = optimoptions(options,'PlotFcn', {  @gaplotbestf });
[x,fval,exitflag,output,population,score] = ...
ga(@totalloss,nvars,[],[],[],[],lb,ub,[],[],options);
