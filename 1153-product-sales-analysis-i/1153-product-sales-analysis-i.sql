# Write your MySQL query statement below
select Product.product_name, Sales.year , Sales.price
from Sales left join Product using(product_id);