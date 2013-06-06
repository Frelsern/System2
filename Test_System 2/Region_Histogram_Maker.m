function [histogram,x] = Region_Histogram_Maker(regions)
% takes in a list of numbers and make a histogram based on the numbers

histogram = zeros(255,1);
x = 1:max(regions);
for k = 1:max(regions)
    num_el = size(find(regions==k));
    histogram(k) = num_el(2);
end

end


