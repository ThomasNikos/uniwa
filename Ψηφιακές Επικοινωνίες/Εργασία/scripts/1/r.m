% Δημιουργία 10000 ομοιόμορφα κατανεμημένων (ψευδοτυχαίων) ακεραίων από 0 ως 15
data = randi([0 15], 10000, 1);

% Διαμόρφωση της ακολουθίας κατά 16QAM
modData = qammod(data,16);

% Διάγραμμα αστερισμού της αθόρυβης διαμορφωμένης ακολουθίας
scatterplot(modData);

% Προσθήκη AWGN στο σήμα με SNR=12dB
noisyData = awgn(modData, 12);

% Διάγραμμα αστερισμού της ενθόρυβης διαμορφωμένης ακολουθίας
scatterplot(noisyData);

% Αποδιαμόρφωση της ενθόρυβης ακολουθίας
demodData = qamdemod(noisyData, 16);

% Υπολογισμός του Bit Error Rate
[~, ber] = biterr(data, demodData);

% Εμφάνιση του αριθμού των λαθών
errors = ber * length(data);
fprintf('Αριθμός λαθών: %d\n', errors);