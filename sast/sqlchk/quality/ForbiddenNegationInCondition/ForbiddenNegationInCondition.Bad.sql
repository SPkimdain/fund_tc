
  SELECT
    ProductID, ProductName
  FROM
    Northwind.Products p
  WHERE
    p.ProductID
  NOT IN ( --@violation
    SELECT
      ProductID
    FROM
      Northwind.OrderDetails)