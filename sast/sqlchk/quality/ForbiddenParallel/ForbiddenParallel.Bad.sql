INSERT /*+ PARALLEL(sales, 4) */ --@violation
INTO customers (cust_first_name, cust_last_name)
SELECT customers.cust_first_name, customers.cust_last_name
FROM sales
         JOIN customers ON sales.cust_id = customers.cust_id
GROUP BY customers.cust_first_name, customers.cust_last_name;
