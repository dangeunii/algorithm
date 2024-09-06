-- 코드를 입력하세요
SELECT CATEGORY, sum(sales) as TOTAL_SALES
from Book
LEFT join BOOK_SALES on BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
where sales_date between '2022-01-01' and '2022-01-31' 
group by category order by category asc