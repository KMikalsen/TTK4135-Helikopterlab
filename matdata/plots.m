%% Plot parameters
clear; clc; clf;
% set(0, 'defaultTextInterpreter', 'latex'); 
t0 = 1;
xpos_master = -1.5;
nSub = 3;
labelSize = 14;
% set(0, 'DefaultAxesFontSize',14);

%% Day 2
t1 = 35000;
figure(1); clf(1);

xpos = xpos_master - .3;

ti = get(gca,'TightInset')
set(gca,'Position',[ti(1) ti(2) 1-ti(3)-ti(1) 1-ti(4)-ti(2)]);

subplot(nSub,1,1);
load('ElevasjonDay2');
plot(Elevasjon(1,1:t1), Elevasjon(2,1:t1));
yl = ylabel('elevation', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(nSub,1,2);
load('PitchDay2');
plot(Pitch(1,1:t1), Pitch(2,1:t1));
yl = ylabel('pitch', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(nSub,1,3);
load('TravelDay2');
plot(travel(1,t0:t1), travel(2,t0:t1));
%axis([0 20 5900 6180]);
yl = ylabel('travel', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

xlabel('Time [s]', 'FontSize', 20)

%% Day 3
t1 = 35000;
figure(2); clf(2);

xpos = xpos_master - .3;

subplot(3,1,1);
load('ElevasjonDay3');
plot(Elevasjon(1,1:t1), Elevasjon(2,1:t1));
yl = ylabel('elevation', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,2);
load('PitchDay3');
plot(Pitch(1,1:t1), Pitch(2,1:t1));
yl = ylabel('pitch', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,3);
load('travelDay3');
plot(travel(1,t0:t1), travel(2,t0:t1));
%axis([0 20 0 250]);
yl = ylabel('travel', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

xlabel('Time [s]', 'FontSize', 20)

%% Day 4 no feedback
t1 = 20000;
figure(3); clf(3);

xpos = xpos_master + .1;

subplot(3,1,1);
load('ElevasjonDay4UnFeed');
plot(Elevasjon(1,1:t1), Elevasjon(2,1:t1));
yl = ylabel('elevation', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,2);
load('PitchDay4UnFeed');
plot(Pitch(1,1:t1), Pitch(2,1:t1));
yl = ylabel('pitch', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,3);
load('travelDay4UnFeed');
plot(travel(1,t0:t1), travel(2,t0:t1));
axis([0 15 0 250]);
yl = ylabel('travel', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

xlabel('Time [s]', 'FontSize', 20)

%% Day 4 with feedback
t1 = 20000;
xpos = xpos_master - .7;
figure(4); clf(4);

subplot(3,1,1);
load('ElevasjonDay4MFeed');
plot(Elevasjon(1,1:t1), Elevasjon(2,1:t1));
axis([0 24 -50 50]);
yl = ylabel('elevation', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,2);
load('PitchDay4MFeed');
plot(Pitch(1,1:t1), Pitch(2,1:t1));
axis([0 24 -50 50]);
yl = ylabel('pitch', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

subplot(3,1,3);
load('travelDay4MFeed');
plot(travel(1,t0:t1), travel(2,t0:t1));
axis([0 24 -30 250]);
yl = ylabel('travel', 'FontSize', labelSize);
pos = get(yl,'Pos');
set(yl,'Pos',[xpos pos(2) pos(3)])

xlabel('Time [s]', 'FontSize', labelSize)