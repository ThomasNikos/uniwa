% Παράμετροι σήματος
Eb_N0_dB = 0:40; % λόγος Eb/N0 σε dB
Eb_N0 = 10.^(Eb_N0_dB/10); % λόγος Eb/N0 σε γραμμική κλίμακα

% Υπολογισμός των πιθανοτήτων σφάλματος
P_error_monopolar = qfunc(sqrt(Eb_N0));
P_error_bipolar_correlated = 1.5 * qfunc(sqrt(Eb_N0));
P_error_bipolar = qfunc(sqrt(2*Eb_N0));

% Γραφική παράσταση των πιθανοτήτων σφάλματος
figure;
loglog(Eb_N0_dB, P_error_monopolar, Eb_N0_dB, P_error_bipolar_correlated, Eb_N0_dB, P_error_bipolar);
title('Σύγκριση πιθανοτήτων σφάλματος συστημάτων σηματοδόσεων βασικής ζώνης');
xlabel('Λόγος Eb/N0 (dB)');
ylabel('Πιθανότητα σφάλματος');
legend('Μονοπολική σηματοδόσία', 'Αντίστροφη εναλλασσόμενη σηματοδόσία', 'Διπολική σηματοδόσία');
grid on;