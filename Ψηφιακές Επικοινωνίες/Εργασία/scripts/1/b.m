% Ορίζουμε τον χρόνο
t = -0.05:0.0001:0.05;

% Υπολογισμός του σήματος x(t)
x = sinc(2000 * t);

% Υπολογισμός του φάσματος πλάτους
X_magnitude = abs(fftshift(fft(x)));

% Υπολογισμός του φάσματος φάσης
X_phase = angle(fftshift(fft(x)));

% Απεικόνιση των γραφικών

% Υποπαράθυρο α)
subplot(3,1,1);
plot(t, x);
xlabel('Χρόνος (s)');
ylabel('Σήμα x(t)');
title('Αναπαράσταση του σήματος στο πεδίο του χρόνου');
grid on;

% Εύρεση του πρώτου μηδενισμού του σήματος
first_zero_index = find(x == 0, 1);
first_zero_time = t(first_zero_index);
disp(['Ο πρώτος μηδενισμός του σήματος συμβαίνει στον χρόνο: ', num2str(first_zero_time), ' δευτερόλεπτα']);

% Υποπαράθυρο β)
subplot(3,1,2);
plot(abs(X_magnitude));
xlabel('Συχνότητα (Hz)');
ylabel('Πλάτος');
title('Φάσμα πλάτους του σήματος');
grid on;

% Υποπαράθυρο γ)
subplot(3,1,3);
plot(X_phase);
xlabel('Συχνότητα (Hz)');
ylabel('Φάση (rad)');
title('Φάσμα φάσης του σήματος');
grid on;