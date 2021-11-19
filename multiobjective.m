function [x,fval,exitflag,output,population,score] = multiobjective(nvars,lb,ub,PopulationSize_Data)
%% This is an auto generated MATLAB file from Optimization Tool.

%% Start with the default options
options = optimoptions('gamultiobj');
%% Modify options setting
options = optimoptions(options,'PopulationSize', PopulationSize_Data);
options = optimoptions(options,'MigrationDirection', 'both');
options = optimoptions(options,'SelectionFcn', {  @selectiontournament 8  });
options = optimoptions(options,'CrossoverFcn', {  @crossoverheuristic [] });
options = optimoptions(options,'Display', 'off');
[x,fval,exitflag,output,population,score] = ...
gamultiobj(@multiobj,nvars,[],[],[],[],lb,ub,[],options);
