figure;
hold on;
hexX = [1.5, 0, -1.5, -1.5, 0, 1.5, 1.5];
hexY = sqrt (3) * [0.5,1,0.5,-0.5,-1,-0.5,0.5];
genT = [3,0];
genS = [1.5,sqrt(3)*1.5];
kmax = 3;
lmax = 3;
for k = -kmax:kmax
   for l = -lmax:lmax
        trans = k*genT + l*genS;
        newhexX = hexX + trans(1);
        newhexY = hexY + trans(2);
    plot(newhexX,newhexY);
end
end
axis equal;
axis off;
hold off;