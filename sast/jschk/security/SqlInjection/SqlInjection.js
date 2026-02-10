
var productid = document.URL.indexOf(eid+4);


db.transaction(
    function (transaction) {
        transaction.executeSql(  // @violation
            'CREATE TABLE IF NOT EXISTS Product' + productid + 'INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, productname TEXT NOT NULL, price INTEGER, qoh INTEGER);',
            [], nullDataHandler, killTransaction
        );
    }
);


db.transaction(
    function (transaction) {
        transaction.executeSql( // no @violation
            'CREATE TABLE IF NOT EXISTS Product ? INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, productname TEXT NOT NULL, price INTEGER, qoh INTEGER);',
            [productid], nullDataHandler, killTransaction
        );
    }
);


function productValidation(){
       checkProducts(document.Products.product, 0);
       return false;
   }

   function checkProducts(products, i){
     var db = systemDB;
     if (i<products.length){
         if (document.Products.product[i].checked==true){
         productId = document.Products.product[i].value;
         qty = document.Products.p[i].value;

     db.transaction(
     function(transaction){
       transaction.executeSql('select * from product where productId='+ productid.split(1,4)+';', [],  // @violation
          function(transaction, results){
      for (var j=0; j<results.rows.length; j++) {
        var row = results.rows.item(j);
        if (qty>row['qoh']){
          alert(row['productname'] + ' is out of stock. We can serve you only ' + row['qoh'] + 'quantities currently!');
          document.Products.product[i].checked = false;
          document.Products.p[i].value = "";
        }
        else{
          document.Products.product[i].checked = false;
           document.Products.p[i].value = "";
          pId = productId;
          pQty = qty;
          pName = row['productname'];
          updateProduct();
      }
               }
              checkProductsSequential(products,i+1);
         });
       }
     );
    }
    else{
     checkProducts (products,i+1);
    }
}
}