SELECT BOOK_ID, left(PUBLISHED_DATE, 10)
FROM BOOK
WHERE year(PUBLISHED_DATE) = '2021' and CATEGORY = '인문'