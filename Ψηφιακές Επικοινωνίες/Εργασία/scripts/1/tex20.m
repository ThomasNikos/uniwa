% Δημιουργία του σήματος
t = -4:0.1:4;
x = exp(t);

% Ομοιόμορφη κβάντιση
partition = 0:63;  % ζώνες κβάντισης
codebook = 0:64;  % επίπεδα κβάντισης
[index, quants] = quantiz(x, partition, codebook);
D1 = mean((x-quants).^2);  % μέσο τετραγωνικό σφάλμα κβάντισης

% Συμπίεση κατά µ-law
mu = 255;
y = sign(x).*log(1+mu*abs(x))/log(1+mu);
[index, quants] = quantiz(y, partition, codebook);
quants = sign(quants).*(1/mu).*((1+mu).^abs(quants)-1);  % αποσυμπίεση
D2 = mean((x-quants).^2);  % μέσο τετραγωνικό σφάλμα κβάντισης

% Εμφάνιση των αποτελεσμάτων
fprintf('Μέσο τετραγωνικό σφάλμα κβάντισης για ομοιόμορφη κβάντιση: %f\n', D1);
fprintf('Μέσο τετραγωνικό σφάλμα κβάντισης για κβάντιση με µ-law συμπίεση: %f\n', D2);