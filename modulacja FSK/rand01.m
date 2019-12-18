function [ arr ] = rand01(m,n)

a = rand(m,n);
arr = a>0.5;

end

