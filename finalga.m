FitnessFunction = @totalloss;
numberOfVariables = 7;
lb = [50, 50, 40, 0.4, 8000, 5, 10];
ub = [90, 100, 90, 0.9, 30000, 15, 25];
[x,fval,exitflag,output,population,scores] = ga(FitnessFunction,numberOfVariables,[],[],[],[],lb,ub);

