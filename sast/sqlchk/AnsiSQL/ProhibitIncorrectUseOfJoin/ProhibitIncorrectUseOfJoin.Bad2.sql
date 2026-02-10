SELECT
     M.category_id
      ,M.name
      ,M.sales_amount
      ,S.product_id
      ,S.sales
 FROM
     categories_sales M
         JOIN sales_ranking S ON M.category_id = S.category_id --@violation