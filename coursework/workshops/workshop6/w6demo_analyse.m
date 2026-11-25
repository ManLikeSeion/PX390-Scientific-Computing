warning off; close all; clear all;
% % Change default axes fonts.
set(0,'DefaultAxesFontName', 'Times New Roman');
set(0,'DefaultAxesFontSize', 16);
% % Change default text fonts.
set(0,'DefaultTextFontname', 'Times New Roman')
set(0,'DefaultTextFontSize', 16);
%
%% Numerical solution
% Load the data and the simulations parameters
data0=load('w6demo.dat');
sim_params=load('w6demo_params');
nx = sim_params(1);
%
% The data can be reshaped to a more convinient format
% You can double-click on the data0/data in the right-hand window
% to examine what their structure is after executing this line.
% You can execute the following in Matlab (Python):
% slice_0 = data(:,1,:)
% which should correspond to the initial time (initial condition).
% This will show you that in each slice we have time in the element the
% element (:,:,1), space grid in (:,:,2) and the temperature in (:,:,3); 
data=reshape(data0, nx, size(data0,1)/nx, size(data0,2));
%
% We can visualise the time evolution of temperature by plotting the
% temperature as a color along the grid and at increasing time
%
figure;
pcolor(data(:,:,1), data(:,:,2), data(:,:,3));
shading flat; colormap(jet(100)); newcolmap=colormap;
xlabel('Time'); ylabel('Position');
%
%% Compare numerical and analytic solutions
% Sample analytic solution at these locations and at final time tf=t(end)
xa=0:0.01:1.0;
t=data(1,:,1); tf=t(end);
% Construct analytic solution
ya=sin(pi.*xa).*exp(-pi*pi*tf);
% Plot analytic and numerical solutions
figure; hold all;
p1 = plot(xa, ya,'k-', 'LineWidth', 2); 
p1.DisplayName = 'Analytic(t=t_{final})';
% Assign the spatial grid of numerical solution. Grid points are in
% position (:,:,2) and are taken from the first temporal slice (:,1,2).
% For the temperature, we want to compare the final time so and the key
% word 'end' here indicates the last temporal slice, with T being in the
% third position.
xn=data(:,1,2); yn=data(:,end,3);
p2 = plot(xn, yn, 'ro', 'LineWidth', 2);
p2.DisplayName = 'Numerical(t=t_{final})';
legend('Location','South','Orientation','horizontal','Box','off');
clear p1 p2;