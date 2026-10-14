% Φόρτωση του αρχείου handel.mat
load handel.mat;

% Ακούστε το σήμα
sound(y, Fs);

% Γραφική παράσταση του σήματος
figure;
plot((1:length(y))/Fs, y);
title('Σήμα μουσικής');
xlabel('Χρόνος (s)');
ylabel('Τιμή σήματος');

% Υποδειγματοληψία του σήματος
y_downsampled = downsample(y, 2);
Fs_downsampled = Fs / 2;

% Γραφική παράσταση του υποδειγματοληπτημένου σήματος
figure;
plot((1:length(y_downsampled))/Fs_downsampled, y_downsampled);
title('Υποδειγματοληπτημένο σήμα μουσικής');
xlabel('Χρόνος (s)');
ylabel('Τιμή σήματος');

% Ακούστε το υποδειγματοληπτημένο σήμα
sound(y_downsampled, Fs_downsampled);