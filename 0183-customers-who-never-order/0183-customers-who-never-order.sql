# Write your MySQL query statement below
select name as Customers 
from CUSTOMERS
left join ORDERS
on ORDERS.customerId = Customers.Id
where Orders.CustomerId is null

# SELECT Name AS Customers
# FROM CUSTOMERS
# LEFT JOIN ORDERS
# ON ORDERS.CustomerID = Customers.Id
# WHERE Orders.CustomerID IS NULL