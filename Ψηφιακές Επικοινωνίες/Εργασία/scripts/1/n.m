% Παράμετροι σήματος
N = 300000; % μήκος σήματος

% Παράμετροι Gaussian pdf
mu_values = [0.5, -3.5]; % μέσες τιμές
sigma_values = [3, 2]; % τυπικές αποκλίσεις

% Δημιουργία σήματων λευκού Gaussian θορύβου
for i = 1:length(mu_values)
    mu = mu_values(i); % μέση τιμή
    sigma = sigma_values(i); % τυπική απόκλιση

    % Δημιουργία σήματος λευκού Gaussian θορύβου
    noise = sigma * randn(1, N) + mu;

    % Γραφική παράσταση του σήματος λευκού Gaussian θορύβου
    figure;
    plot(noise);
    title(['Σήμα λευκού Gaussian θορύβου, \mu = ', num2str(mu), ', \sigma = ', num2str(sigma)]);
    xlabel('Δείγμα');
    ylabel('Τιμή σήματος');

    % Δημιουργία ιστογράμματος του σήματος λευκού Gaussian θορύβου
    figure;
    histogram(noise, 20);
    title(['Ιστόγραμμα σήματος λευκού Gaussian θορύβου, \mu = ', num2str(mu), ', \sigma = ', num2str(sigma)]);
    xlabel('Τιμή σήματος');
    ylabel('Συχνότητα');
end