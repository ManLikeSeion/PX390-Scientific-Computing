warning off; close all; clear all;
% % Change default axes fonts.
set(0,'DefaultAxesFontName', 'Times New Roman');
set(0,'DefaultAxesFontSize', 20);
% % Change default text fonts.
set(0,'DefaultTextFontname', 'Times New Roman')
set(0,'DefaultTextFontSize', 20);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Numerical solution
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Load the data and the simulations parameters
data01 = load('advftcs.dat');
data02 = load('advlw.dat');
data03 = load('advuw.dat');
sim_params=load('advparams');
%
% Reshape the matrices
nx = sim_params(1);
% The data can be reshaped to a more convinient format
d1 = reshape(data01, nx, size(data01,1)/nx, size(data01,2));
d2 = reshape(data02, nx, size(data02,1)/nx, size(data02,2));
d3 = reshape(data03, nx, size(data03,1)/nx, size(data03,2));
%
% Plot 1. solutions at different times. Press any key to see the next
% time step solution (space bar will do)
figure;
for i=1:25:200
    subplot(3,1,1);
    plot(d1(:,1,1), d1(:,i,2),'LineWidth', 2); hold on;
    subplot(3,1,2);
    plot(d2(:,1,1), d2(:,i,2),'LineWidth', 2); hold on;
    ylabel('y');
    subplot(3,1,3);
    plot(d3(:,1,1), d3(:,i,2),'LineWidth', 2); hold on;
    xlabel('x_k');
    pause; % Press any key on the keyboard to continue
end
d