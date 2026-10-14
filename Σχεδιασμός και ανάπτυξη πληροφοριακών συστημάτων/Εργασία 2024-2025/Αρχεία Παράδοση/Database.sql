CREATE TABLE `ΠΡΟΜΗΘΕΥΤΗΣ` (
  `id` int PRIMARY KEY,
  `επωνυμία` varchar(255),
  `αφμ` varchar(255)
);

CREATE TABLE `ΤΙΜΟΛΟΓΙΟ` (
  `id` int PRIMARY KEY,
  `προμηθευτής_id` int,
  `ημερομηνία` date,
  `ποσό` decimal,
  `κατήσταση` varchar(255)
);

CREATE TABLE `ΠΛΗΡΩΜΗ` (
  `id` int PRIMARY KEY,
  `τιμολόγιο_id` int,
  `ημερομηνία` date,
  `ποσό` decimal,
  `τρόπος_πληρωμής` varchar(255)
);

CREATE TABLE `ΛΟΓΙΣΤΙΚΗ_ΕΓΓΡΑΦΗ` (
  `id` int PRIMARY KEY,
  `τιμολόγιο_id` int,
  `ημερομηνία` date,
  `ποσό` decimal,
  `τύπος` varchar(255)
);

ALTER TABLE `ΤΙΜΟΛΟΓΙΟ` ADD FOREIGN KEY (`προμηθευτής_id`) REFERENCES `ΠΡΟΜΗΘΕΥΤΗΣ` (`id`);

ALTER TABLE `ΠΛΗΡΩΜΗ` ADD FOREIGN KEY (`τιμολόγιο_id`) REFERENCES `ΤΙΜΟΛΟΓΙΟ` (`id`);

ALTER TABLE `ΛΟΓΙΣΤΙΚΗ_ΕΓΓΡΑΦΗ` ADD FOREIGN KEY (`τιμολόγιο_id`) REFERENCES `ΤΙΜΟΛΟΓΙΟ` (`id`);
