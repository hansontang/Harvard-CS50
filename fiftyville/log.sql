-- Keep a log of any SQL queries you execute as you solve the mystery.
sqlite3 fiftyville.db
.tables
.schema crime_scene_reports

-- 查看当天犯罪记录
SELECT * FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
--Littering took place at 16:36.No known witnesses
SELECT * FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%thief%" ;

--cars bakery ten minutes
--ATM on Leggett street ,withdrawing some money
--take the earliest flight out of Fiftyville tomorrow / call someone / purchase the flight ticket /<1 minute

--check car
SELECT * FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28;
--L68E5I0 -> 8:25 ENTRANCE,8:34 exit

--check atm
SELECT * FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location LIKE "Leggett street"
AND transaction_type LIKE "withdraw";

--check airport
SELECT * FROM airports WHERE city LIKE "fiftyville":
-- abbreviation CSF; full_name = Fiftyville Regional Airport

--check flights
SELECT * FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day = 29
--the ealiest : 2021/7/29/8/20 from 8 to 4  flights id = 36

--check airport
SELECT * FROM airports WHERE id = 4;
-- LaGuardia Airport in New York City

--check phone_calls
SELECT * FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

--bank
SELECT name FROM people,bank_accounts,atm_transactions
WHERE people.id = bank_accounts.person_id
AND bank_accounts.account_number = atm_transactions.account_number
AND month = 7
AND day = 28
AND atm_location LIKE "Leggett street"
AND transaction_type LIKE "withdraw";
--name : Bruce Diana Brooke Kenny Iman Luca Taylor Benista

--phone
SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60);
--name : Kenny Sofia Benista Taylor Diana Kelsey Bruce Carina

--airport
SELECT name FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id = 36);
--name:Kenny Sofia Taylor Luca Kelsey Edward Bruce Doris

--car
SELECT name FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute > 15
AND minute <=25
AND activity = "exit");
--name:Vanessa Barry Iman Sofia Luca Diana Kelsey Bruce


--answer the phone
SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE caller IN
(SELECT phone_number FROM people WHERE name LIKE "Bruce")
AND month = 7 AND day = 28 AND duration < 60
);
--name:Robin


-- call the phone :Bruce
-- answer the phone :Robin
