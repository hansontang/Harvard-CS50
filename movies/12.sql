SELECT title FROM movies,stars,people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name LIKE "Johnny Depp"
AND title IN
(SELECT title FROM movies,stars,people
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND name LIKE "Helena Bonham Carter");