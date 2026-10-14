Eb_N0_10dB = 10^(10/10); % λόγος Eb/N0 σε γραμμική κλίμακα για 10 dB

% Υπολογισμός των πιθανοτήτων σφάλματος για Eb/N0 = 10 dB
P_error_ASK_10dB = qfunc(sqrt(Eb_N0_10dB));
P_error_PSK_10dB = qfunc(sqrt(2*Eb_N0_10dB));
P_error_FSK_10dB = qfunc(sqrt(Eb_N0_10dB));
