% Δυαδική ακολουθία
x = [1 1 0 1 0 1 0 0 1 0];

% Χρόνος
t = linspace(0, 60, 1000);  % 6 sec για κάθε παλμό, συνολικά 60 sec

% Χρόνος για τη σηματοδοσία Manchester
t_manchester = linspace(0, 60, length(x)*100);

% Σηματοδοσίες
signals = {
    'Μονοπολική NRZ', repelem(x, 100);
    'Διπολική NRZ', repelem(2*x-1, 100);
    'ΑΜΙ', repelem((2*(x - 0.5) .* ((-1).^cumsum(x))), 100);
    'Manchester', repelem((2*x-1), 100).*sign(sin(2 * pi * t_manchester / 6))
};

% Εμφάνιση γραφικών παραστάσεων
figure;
for i = 1:size(signals, 1)
    subplot(size(signals, 1), 1, i);
    plot(t, signals{i, 2});
    title(signals{i, 1});
    grid on;
end