SELECT DISTINCT(name) FROM people
JOIN movies ON stars.movie_id = movies.id
JOIN stars ON (people.id = stars.person_id AND movies.id = stars.movie_id)
JOIN ratings ON movies.id = ratings.movies_id
WHERE name LIKE "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5