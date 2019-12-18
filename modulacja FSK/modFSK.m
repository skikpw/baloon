clc;
clear all;
close all;
%x=rand01(1,10);                                    % infor
x = [1 0 0 0 1 1 1 0 0 1];
bp=1/115200;                                                    % bit period
disp(' Binary information at Transmitter :');
% disp(x);
%XX representation of transmitting binary information as digital signal XXX
bit=[]; 
for n=1:1:length(x)
    if x(n)==1
       se=ones(1,100);
    else
        x(n)=0;
        se=zeros(1,100);
    end
     bit=[bit se];
end
t1=bp/100:bp/100:100*length(x)*(bp/100);
subplot(2,1,1);
plot(t1,bit,'lineWidth',2.5);grid on;
axis([ 0 bp*length(x) -.5 1.5]);
ylabel('amplitude(volt)');
xlabel(' time(sec)');
title('transmitting information as digital signal');

%XXXXXXXXXXXXXXXXXXXXXXX Binary-FSK modulation XXXXXXXXXXXXXXXXXXXXXXXXXXX%
A=5;                                          % Amplitude of carrier signal
br=1/bp;                                                         % bit rate
fc = 3e5;
dev = 1e5;
f1=fc-dev/2;                           % carrier frequency for information as 1
f2=fc+dev/2;                           % carrier frequency for information as 0
t2=bp/99:bp/99:bp;                 
ss=length(t2);
m=[];
for (i=1:1:length(x))
    if (x(i)==1)
        y=A*cos(2*pi*f1*t2);
    else
        y=A*cos(2*pi*f2*t2);
    end
    m=[m y];
end
t3=bp/99:bp/99:bp*length(x);
subplot(2,1,2);
plot(t3,m);
xlabel('time(sec)');
ylabel('amplitude(volt)');
title('waveform for binary FSK modulation coresponding binary information');

fID = fopen('signal2.bin','w');
fwrite(fID,m,'double');
csvwrite('signal2.csv',x);