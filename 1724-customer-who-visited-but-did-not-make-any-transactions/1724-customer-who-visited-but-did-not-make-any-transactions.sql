# Write your MySQL query statement below
SELECT CUSTOMER_ID, COUNT(VISIT_ID) AS COUNT_NO_TRANS
FROM VISITS AS V
LEFT JOIN TRANSACTIONS AS T
USING (VISIT_ID)
WHERE TRANSACTION_ID IS NULL
GROUP BY CUSTOMER_ID;
