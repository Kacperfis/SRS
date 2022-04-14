-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 14 Kwi 2022, 19:39
-- Wersja serwera: 10.4.20-MariaDB
-- Wersja PHP: 8.0.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `users`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `admin_tasks`
--

CREATE TABLE `admin_tasks` (
  `id_task` int(11) NOT NULL,
  `task_message` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `admin_tasks`
--

INSERT INTO `admin_tasks` (`id_task`, `task_message`) VALUES
(1, 'Test Content'),
(2, 'Test content 2');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `announcements`
--

CREATE TABLE `announcements` (
  `id_announcement` int(11) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `content` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `announcements`
--

INSERT INTO `announcements` (`id_announcement`, `id_person`, `content`) VALUES
(2, NULL, 'This is test announcement'),
(3, NULL, 'This is some test content for Adding announcement testing purposes');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `attendance`
--

CREATE TABLE `attendance` (
  `id_attendance` int(11) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `type` tinyint(1) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `id_subject` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `attendance`
--

INSERT INTO `attendance` (`id_attendance`, `id_person`, `type`, `date`, `id_subject`) VALUES
(35, 2, 1, '2022-04-03', 3),
(36, 7, 0, '2022-04-03', 3),
(37, 2, 1, '2022-04-14', 2),
(38, 7, 0, '2022-04-14', 2),
(39, 6, 1, '2022-04-14', 4),
(40, 5, 0, '2022-04-14', 4),
(41, 4, 0, '2022-04-14', 4);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `class`
--

CREATE TABLE `class` (
  `id_person` int(11) NOT NULL,
  `id_class` int(11) DEFAULT NULL,
  `class` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `class`
--

INSERT INTO `class` (`id_person`, `id_class`, `class`) VALUES
(2, 3, '2A'),
(3, 8, '4B'),
(4, 6, '3B'),
(5, 6, '3B'),
(6, 6, '3B'),
(7, 3, '2A'),
(8, 3, '2A');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `data`
--

CREATE TABLE `data` (
  `id_person` int(11) NOT NULL,
  `login` text DEFAULT NULL,
  `password` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `data`
--

INSERT INTO `data` (`id_person`, `login`, `password`) VALUES
(1, 'admin', 'admin'),
(2, 'fisiu', '123'),
(3, 'kowal', '12345'),
(4, 'marcinnowak', 'marcinek'),
(5, 'donaldT', 'donaldt123'),
(6, 'marianek13', 'mario1337'),
(7, 'marecki', '123'),
(8, 'Monia15', 'Moniusia123');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `form_teacher`
--

CREATE TABLE `form_teacher` (
  `id_person` int(11) NOT NULL,
  `id_class` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `form_teacher`
--

INSERT INTO `form_teacher` (`id_person`, `id_class`) VALUES
(6, 6);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `homework`
--

CREATE TABLE `homework` (
  `id_homework` int(11) NOT NULL,
  `start_data` date DEFAULT NULL,
  `end_data` date DEFAULT NULL,
  `id_class` int(11) DEFAULT NULL,
  `id_subject` int(11) DEFAULT NULL,
  `content` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `homework`
--

INSERT INTO `homework` (`id_homework`, `start_data`, `end_data`, `id_class`, `id_subject`, `content`) VALUES
(2, '2022-04-14', '2022-04-18', 6, 2, 'task 1, 2, 3 page 18,19,  Introduction To Algorithms I'),
(3, '2022-04-14', '2022-04-16', 6, 3, 'test task');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `info`
--

CREATE TABLE `info` (
  `id_info` int(11) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `name` text DEFAULT NULL,
  `surname` text DEFAULT NULL,
  `phone_number` text DEFAULT NULL,
  `email` text DEFAULT NULL,
  `PESEL` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `info`
--

INSERT INTO `info` (`id_info`, `id_person`, `name`, `surname`, `phone_number`, `email`, `PESEL`) VALUES
(1, 2, 'Kacper', 'Fiś', '123456789', 'kacperfis@wp.pl', '12345678912'),
(2, 3, 'jan', 'kowalski', '123521323', 'kowal@wp.pl', '12345678913'),
(3, 4, 'marcin', 'nowak', '123456789', 'marcinek@gmail.com', '54367814789'),
(4, 5, 'Donald', 'Trump', '654789253', 'donaltrump@gmail.com', '54367895648'),
(5, 6, 'Marian', 'Owczarz', '112344566', 'owczarek@wp.pl', '77542768990'),
(6, 7, 'Marek', 'Marecki', '123456753', 'marecki@wp.pl', '089059285642'),
(8, 1, 'admin', '', NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `marks`
--

CREATE TABLE `marks` (
  `id_mark` int(11) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `id_subject` int(11) DEFAULT NULL,
  `mark` int(11) DEFAULT NULL,
  `date_of_adding` date DEFAULT NULL,
  `description` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `marks`
--

INSERT INTO `marks` (`id_mark`, `id_person`, `id_subject`, `mark`, `date_of_adding`, `description`) VALUES
(1, 2, 3, 5, '2022-03-20', 'Exam grade'),
(4, 2, 2, 3, '2022-03-30', 'Activity grade'),
(5, 7, 2, 4, '2022-03-30', 'Exam Mark'),
(6, 2, 3, 6, '2022-03-24', 'Test grade'),
(7, 2, 2, 1, '2022-03-09', 'Test 2 grade'),
(8, 2, 2, 1, '2022-03-09', 'Test 2 grade'),
(9, 7, 3, 6, '2022-03-24', 'test grade ');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `messaging`
--

CREATE TABLE `messaging` (
  `id_message` int(11) NOT NULL,
  `sender` int(11) DEFAULT NULL,
  `recipient` int(11) DEFAULT NULL,
  `content` text DEFAULT NULL,
  `date` date DEFAULT NULL,
  `title` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `messaging`
--

INSERT INTO `messaging` (`id_message`, `sender`, `recipient`, `content`, `date`, `title`) VALUES
(2, 1, 7, 'This is the #END# message for #END# testing purposes #END#  #END# XYZ #END# ', '2022-04-13', 'message_title'),
(3, 1, 5, 'sad #END# sadasd #END# asdsad #END# ', '2022-04-13', 'asdsa'),
(4, 1, 6, 'sdsadqweqwe #END# wqewqea #END# xyz #END# ', '2022-04-13', 'sadsada'),
(5, 1, 6, 'asdasd #END# sa #END# d #END# q #END# we #END#  #END# asd #END# ', '2022-04-13', 'asdsad'),
(6, 5, 1, 'hi #END# it #END# will be beautiful #END# day #END#', '2022-04-13', 'Message from Trump'),
(12, 6, 5, 'This message  #END# was sent for testing #END# purposes #END#  #END# XYZ #END# ', '2022-04-14', 'Testing title');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `person_type`
--

CREATE TABLE `person_type` (
  `id_person` int(11) NOT NULL,
  `type` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `person_type`
--

INSERT INTO `person_type` (`id_person`, `type`) VALUES
(2, 'Student'),
(3, 'Student'),
(4, 'Student'),
(5, 'Student'),
(6, 'Teacher'),
(7, 'Student'),
(8, 'Student');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `subjects`
--

CREATE TABLE `subjects` (
  `id_subject` int(11) NOT NULL,
  `id_person` int(11) DEFAULT NULL,
  `subject_name` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `subjects`
--

INSERT INTO `subjects` (`id_subject`, `id_person`, `subject_name`) VALUES
(1, NULL, 'Polish language'),
(2, NULL, 'Mathematics'),
(3, NULL, 'English language'),
(4, NULL, 'Biology'),
(5, NULL, 'History'),
(6, NULL, 'Physical Education'),
(7, NULL, 'Physics'),
(8, NULL, 'Computer Science'),
(9, NULL, 'Chemistry'),
(10, NULL, 'Geography'),
(11, NULL, 'Religion');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `admin_tasks`
--
ALTER TABLE `admin_tasks`
  ADD PRIMARY KEY (`id_task`);

--
-- Indeksy dla tabeli `announcements`
--
ALTER TABLE `announcements`
  ADD PRIMARY KEY (`id_announcement`);

--
-- Indeksy dla tabeli `attendance`
--
ALTER TABLE `attendance`
  ADD PRIMARY KEY (`id_attendance`);

--
-- Indeksy dla tabeli `class`
--
ALTER TABLE `class`
  ADD PRIMARY KEY (`id_person`);

--
-- Indeksy dla tabeli `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`id_person`);

--
-- Indeksy dla tabeli `form_teacher`
--
ALTER TABLE `form_teacher`
  ADD PRIMARY KEY (`id_person`);

--
-- Indeksy dla tabeli `homework`
--
ALTER TABLE `homework`
  ADD PRIMARY KEY (`id_homework`);

--
-- Indeksy dla tabeli `info`
--
ALTER TABLE `info`
  ADD PRIMARY KEY (`id_info`);

--
-- Indeksy dla tabeli `marks`
--
ALTER TABLE `marks`
  ADD PRIMARY KEY (`id_mark`);

--
-- Indeksy dla tabeli `messaging`
--
ALTER TABLE `messaging`
  ADD PRIMARY KEY (`id_message`);

--
-- Indeksy dla tabeli `person_type`
--
ALTER TABLE `person_type`
  ADD PRIMARY KEY (`id_person`);

--
-- Indeksy dla tabeli `subjects`
--
ALTER TABLE `subjects`
  ADD PRIMARY KEY (`id_subject`);

--
-- AUTO_INCREMENT dla zrzuconych tabel
--

--
-- AUTO_INCREMENT dla tabeli `admin_tasks`
--
ALTER TABLE `admin_tasks`
  MODIFY `id_task` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT dla tabeli `announcements`
--
ALTER TABLE `announcements`
  MODIFY `id_announcement` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT dla tabeli `attendance`
--
ALTER TABLE `attendance`
  MODIFY `id_attendance` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=42;

--
-- AUTO_INCREMENT dla tabeli `data`
--
ALTER TABLE `data`
  MODIFY `id_person` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT dla tabeli `form_teacher`
--
ALTER TABLE `form_teacher`
  MODIFY `id_person` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT dla tabeli `homework`
--
ALTER TABLE `homework`
  MODIFY `id_homework` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT dla tabeli `info`
--
ALTER TABLE `info`
  MODIFY `id_info` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT dla tabeli `marks`
--
ALTER TABLE `marks`
  MODIFY `id_mark` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT dla tabeli `messaging`
--
ALTER TABLE `messaging`
  MODIFY `id_message` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT dla tabeli `subjects`
--
ALTER TABLE `subjects`
  MODIFY `id_subject` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
