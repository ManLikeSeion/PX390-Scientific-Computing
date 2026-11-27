scriptDir = fileparts(mfilename('fullpath'));
data = readmatrix(fullfile(scriptDir, 'output.txt'), 'NumHeaderLines', 1);

plotStep = max(1, ceil(size(data, 1) / 50000));
plot(data(1:plotStep:end, 1), data(1:plotStep:end, 2));
axis equal;
grid on;
xlabel('x (m)');
ylabel('y (m)');
title('Earth orbit around the Sun');