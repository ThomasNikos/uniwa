% Παράμετροι
t = -0.05:0.0001:0.05; % Διάνυσμα χρόνου
f_s = 1000; % Συχνότητα δειγματοληψίας

% Αρχική συνάρτηση sinc
x_t = sinc(1000 * t);

% Μετατοπισμένη συνάρτηση sinc (κεντραρισμένη στο t = 0.01s)
t_shifted = t - 0.01;
x1_t = sinc(1000 * t_shifted);

% Φάσμα συχνοτήτων
f = linspace(-f_s/2, f_s/2, length(t));
X_f = fftshift(fft(x_t));
X1_f = fftshift(fft(x1_t));

% Σχεδιασμός γραφημάτων
figure;

% Γράφημα στο πεδίο του χρόνου
subplot(3, 1, 1);
plot(t, x_t, 'b');
title('Αρχική συνάρτηση sinc');
xlabel('Χρόνος (s)');
ylabel('Αμπλιτούδα');

subplot(3, 1, 2);
plot(t_shifted, x1_t, 'r');
title('Μετατοπισμένη συνάρτηση sinc');
xlabel('Χρόνος (s)');
ylabel('Αμπλιτούδα');

% Γράφημα στο πεδίο των συχνοτήτων
subplot(3, 1, 3);
plot(f, abs(X_f), 'b');
hold on;
plot(f, abs(X1_f), 'r');
title('Φάσμα συχνοτήτων');
xlabel('Συχνότητα (Hz)');
ylabel('Μέγεθος');
legend('Αρχική sinc', 'Μετατοπισμένη sinc');
grid on;

% Εύρεση του πρώτου μηδενισμού
first_zero_index = find(x1_t >= 0, 1);
first_zero_time = t_shifted(first_zero_index);
fprintf('Ο πρώτος μηδενισμός συμβαίνει στο t = %.4f δευτερόλεπτα.\n', first_zero_time);