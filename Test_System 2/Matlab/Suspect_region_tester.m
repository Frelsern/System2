clc
clear all
close all


% reading in filw with region sizes
text_Regions = fileread('suspect_region_sizes.txt');
Regions_and_coordinates = str2num(text_Regions);
a = size(Regions_and_coordinates);
area = [];
x = [];
y = [];
for(i = 0:((a(2)-1)/3))
    area = [area Regions_and_coordinates(1+i*3)];
    x = [x Regions_and_coordinates(2+i*3)];
    y = [y Regions_and_coordinates(3+i*3)];
    
end



% [histogram,x] = Region_Histogram_Maker(Regions);
% figure();
% x = [-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,x];
% histogram = [0;0;0;0;0;0;0;0;0;0;histogram];
% plot(x,histogram);