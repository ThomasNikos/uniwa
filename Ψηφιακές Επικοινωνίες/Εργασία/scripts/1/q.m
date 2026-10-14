% Παράμετροι σήματος
Eb_N0_dB = 0:40; % λόγος Eb/N0 σε dB
Eb_N0 = 10.^(Eb_N0_dB/10); % λόγος Eb/N0 σε γραμμική κλίμακα

% Υπολογισμός των πιθανοτήτων σφάλματος
P_error_ASK = qfunc(sqrt(Eb_N0));
P_error_PSK = qfunc(sqrt(2*Eb_N0));
P_error_FSK = qfunc(sqrt(Eb_N0));

% Γραφική παράσταση των πιθανοτήτων σφάλματος
figure;
loglog(Eb_N0, P_error_ASK, Eb_N0, P_error_PSK, Eb_N0, P_error_FSK);
title('Σύγκριση πιθανοτήτων σφάλματος συστημάτων σηματοδόσεων ζωνοπερατής');
xlabel('Λόγος Eb/N0');
ylabel('Πιθανότητα σφάλματος');
legend('ASK', 'PSK', 'FSK');
grid on;